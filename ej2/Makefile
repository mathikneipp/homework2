UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	CXX := clang++
else
	CXX := g++
endif

CXXFLAGS = -Wall -Wextra -std=c++17 -g

TARGET_CURSO = curso_exec

run: 
	$(CXX) $(CXXFLAGS) -o $(TARGET_CURSO) curso_main.cpp Estudiante.cpp Curso.cpp
	./curso_exec

clean:
	rm -rf *.o *.dSYM curso_exec output
