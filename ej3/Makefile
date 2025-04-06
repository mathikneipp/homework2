UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	CXX := clang++
else
	CXX := g++
endif

CXXFLAGS = -Wall -Wextra -std=c++17 -g

TARGET_NUMERO = numero_exec

run:
	$(CXX) $(CXXFLAGS) -o $(TARGET_NUMERO) numero_main.cpp Numero.cpp
	./numero_exec

clean:
	rm -rf *.o *.dSYM numero_exec output
