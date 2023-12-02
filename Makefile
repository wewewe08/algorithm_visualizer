SRC_DIR := src
BUILD_DIR := build-files

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

CLEAN_FILES := $(OBJ_FILES) main.exe

all: compile link

compile: $(OBJ_FILES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -I$(SRC_DIR)/include -c $< -o $@

link: $(OBJ_FILES)
	g++ $(OBJ_FILES) -o main -mwindows -L$(SRC_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	@echo "Cleaning project files..."
	del /Q /F main.exe $(CLEAN_FILES)
	@echo "Clean successful."