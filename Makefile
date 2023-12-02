SRC_DIR := src
BUILD_DIR := build-files

CLEAN_FILES := *.o 
COMPILE_FILES := $(wildcard $(BUILD_DIR)/*.cpp)

all: compile link

compile:
	g++ -I${SRC_DIR}/include -c ${COMPILE_FILES}

link:
	g++ main.o -o main -mwindows -L${SRC_DIR}/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	@echo "Cleaning project files..."
	del /Q /F main.exe ${CLEAN_FILES}
	@echo "Clean successful."