default:
	g++ src/*.c -o bin/AstroAssault.exe -O2 -Wall -Wno-missing-braces -I../ -L../ -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows