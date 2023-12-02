SRC_DIR := src
BUILD_DIR := build-files

OBJ_FILES := $(patsubst $(BUILD_DIR)/%.cpp, %.o, $(wildcard $(BUILD_DIR)/*.cpp))

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

run: link
	${PROGRAM}.exe