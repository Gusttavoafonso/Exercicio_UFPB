# Diretórios
INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj

# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I$(INCLUDE_DIR)

# Nome do executável
TARGET = sistema

# Lista de arquivos fonte
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Arquivos objeto correspondentes
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Regra padrão
all: $(TARGET)

# Compila o programa
$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(TARGET)

# Regra para compilar arquivos .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cria o diretório obj se ele não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpa arquivos objeto e o executável
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

# Regra para rodar o programa
run: all
	./$(TARGET)
