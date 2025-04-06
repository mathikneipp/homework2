UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	CXX := clang++
else
	CXX := g++
endif

CXXFLAGS = -Wall -Wextra -std=c++17 -g

TARGET_TIEMPO = tiempo_exec

run: 
	$(CXX) $(CXXFLAGS) -o $(TARGET_TIEMPO) tiempo_main.cpp Tiempo.cpp
	./tiempo_exec

clean:
	rm -rf *.o *.dSYM tiempo_exec output
