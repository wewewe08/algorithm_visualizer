SRC_DIR := src
BUILD_DIR := build-files

COMPILE_FILES = $(wildcard $(BUILD_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(BUILD_DIR)/%.cpp, %.o, ${COMPILE_FILES})

PROGRAM := visualizer

all: link

%.o: $(BUILD_DIR)/%.cpp
	g++ -I${SRC_DIR}/include -c $<

link: $(OBJ_FILES)
	g++ $^ -o ${PROGRAM} -mwindows -L${SRC_DIR}/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	@echo "Cleaning project files..."
	del /Q /F ${PROGRAM}.exe ${OBJ_FILES}
	@echo "Clean successful."