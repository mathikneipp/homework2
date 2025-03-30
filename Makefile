CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Ejecutables individuales
TARGET_TIEMPO = tiempo_exec
TARGET_CURSO = curso_exec
TARGET_NUMERO = numero_exec
TARGET_BANCO = banco_exec

run_ej1: 
	$(CXX) $(CXXFLAGS) -o $(TARGET_TIEMPO) tiempo_main.cpp Tiempo.cpp
	./tiempo_exec

run_ej2: 
	$(CXX) $(CXXFLAGS) -o $(TARGET_CURSO) curso_main.cpp Estudiante.cpp Curso.cpp
	./curso_exec

run_ej3:
	$(CXX) $(CXXFLAGS) -o $(TARGET_NUMERO) numero_main.cpp Numero.cpp
	./numero_exec

run_ej4:
	$(CXX) $(CXXFLAGS) -o $(TARGET_BANCO) banco_main.cpp Banco.cpp
	./banco_exec

clean:
	rm -rf *.o *.dSYM banco_exec curso_exec numero_exec tiempo_exec output
