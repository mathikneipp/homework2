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
	$(CXX) $(CXXFLAGS) -o $(TARGET_TIEMPO) curso_main.cpp Estudiante.cpp Curso.cpp
	./tiempo_exec

run_ej3:
	$(CXX) $(CXXFLAGS) -o $(TARGET_TIEMPO) numero_main.cpp Numero.cpp
	./tiempo_exec

run_ej4:
	$(CXX) $(CXXFLAGS) -o $(TARGET_TIEMPO) banco_main.cpp Banco.cpp
	./tiempo_exec

clean:
	rm -f tiempo_exec curso_exec
