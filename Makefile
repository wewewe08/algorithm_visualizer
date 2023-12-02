CLEAN_FILES = *.o 

COMPILE_FILES = *.cpp

all: compile link

compile:
	g++ -Isrc/include -c build-files/${COMPILE_FILES}

link:
	g++ main.o -o main -mwindows -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	@echo "cleaning project files..."
	del /Q /F main.exe ${CLEAN_FILES}
	@echo "clean successful."