UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	CXX := clang++
else
	CXX := g++
endif

CXXFLAGS = -Wall -Wextra -std=c++17 -g

TARGET_BANCO = banco_exec

run:
	$(CXX) $(CXXFLAGS) -o $(TARGET_BANCO) banco_main.cpp Banco.cpp
	./banco_exec

clean:
	rm -rf *.o *.dSYM banco_exec output
