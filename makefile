# Nome do executável
TARGET = main

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c11 -O2

# Arquivos fonte
SRC = main.c aeroportos.c

# Arquivos objeto (gerados automaticamente)
OBJ = $(SRC:.c=.o)

# Regra padrão: compila o executável
all: $(TARGET)

# Compilando o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compilando arquivos objeto individualmente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -f $(OBJ) $(TARGET)
