# Directories
SRC_DIR := src
BUILD_DIR := build-files

# File locations
CODE_FILES := $(BUILD_DIR)/%.cpp
OBJ_FILES := $(patsubst $(BUILD_DIR)/%.cpp, %.o, $(wildcard $(BUILD_DIR)/*.cpp))

# Program name
PROGRAM := visualizer

all: link

# Rule to compile all C++ files 
%.o: ${CODE_FILES}
	g++ -I${SRC_DIR}/include -c $<

# Link object files to SFML library
link: $(OBJ_FILES)
	g++ $^ -o ${PROGRAM} -L${SRC_DIR}/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	@echo "Cleaning project files..."
	del /Q /F ${PROGRAM}.exe ${OBJ_FILES}
	@echo "Clean successful."

run: link
	${PROGRAM}.exe