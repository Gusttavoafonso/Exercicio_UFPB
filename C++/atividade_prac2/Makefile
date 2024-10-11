# Compilador a ser utilizado
CXX = g++
CXXFLAGS = -Wall -g

# Nome do executável
TARGET = campeonato

# Arquivos de origem
SRCS = main.cpp \
       Pessoa.cpp \
       MembroClube.cpp \
       Jogador.cpp \
       Tecnico.cpp \
       TecnicoJogador.cpp \
       Juiz.cpp \
       Time.cpp \
       Jogo.cpp \
       Campeonato.cpp

# Arquivos de cabeçalho
HEADERS = Pessoa.h \
           MembroClube.h \
           Jogador.h \
           Tecnico.h \
           TecnicoJogador.h \
           Juiz.h \
           Time.h \
           Jogo.h \
           Campeonato.h

# Regra padrão para compilar o executável
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET) *.o

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
