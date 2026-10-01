# Makefile multiplataforma

PROG = stars

# Compilador
CC = gcc

# Flags
CFLAGS = -Iinclude -g -O3 # -Wall -g  # Todas as warnings, infos de debug
LDFLAGS  =
LIBS     =

# Detecta SO and e ajusta extensao se necessario
ifeq ($(OS),Windows_NT)
    # Windows (MinGW)
    EXEEXT  = .exe
    OSNAME  = Windows
    CFLAGS  = -O3 -Iinclude
    LDFLAGS = -Llib\GL
    LIBS    += -lfreeglut -lopengl32 -lglu32 -lm
else
    UNAME_S := $(shell uname -s)
    EXEEXT  =
    ifeq ($(UNAME_S),Linux)
        OSNAME  = Linux
        CFLAGS  += -O3
        LIBS    += -lGL -lGLU -lglut -lm
    endif
    ifeq ($(UNAME_S),Darwin)
        OSNAME  = macOS
        CFLAGS  += -Wno-deprecated -O3
        LIBS    += -framework OpenGL -framework Cocoa -framework GLUT -lm
    endif
endif

# Fontes
FONTES = main.c
OBJ = $(FONTES:.c=.o)

# Target (com extensao se necessario)
TARGET = $(PROG)$(EXEEXT)

# Regras
all: $(TARGET)
	@echo "Build completado para $(OSNAME). Saida: $(TARGET)"

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LDFLAGS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
ifeq ($(OS),Windows_NT)
	del /Q $(subst /,\,$(OBJ)) $(TARGET) 2>nul || true
else
	rm -f $(OBJ) $(TARGET)
endif

# Mostra infos do SO detectado
info:
	@echo "SO detectado: $(OSNAME)"
	@echo "Compilador:   $(CC)"
	@echo "CFLAGS:       $(CFLAGS)"
	@echo "LIBS:        $(LIBS)"
	@echo "Target:       $(TARGET)"

.PHONY: all clean info

