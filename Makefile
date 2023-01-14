# Compiler variables
CC= gcc
CFLAGS= -Wall -g

# Helper variables
APP_NAME= "Hello_SDL"
GAME= Src/
FILES= Main.o
INCLUDES= -I Src/include
LINKS= -L Src/lib/SDL
DEPS= -l mingw32 -l SDL2main -l SDL2

# Compiles C and H files, deletes O files, and Runs app
default: mainapp clean run

# Compiles C and H files
mainapp: ${GAME}Main.o
	$(CC) ${CFLAGS} ${INCLUDES} ${LINKS} ${FILES} -o Build/${APP_NAME} ${DEPS}

# Compiles C and O files
%.o: %.c
	$(CC) ${CFLAGS} ${INCLUDES} ${LINKS} -c $^ ${DEPS}

# Deletes O files
clean:
	del -f *.o

# Runs app
run:
	./Build/${APP_NAME}
