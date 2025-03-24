CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g

# Ejecutables individuales
TARGET_TIEMPO = tiempo_exec


run_tiempo: 
	$(CXX) $(CXXFLAGS) -o $(TARGET_TIEMPO) tiempo_main.cpp Tiempo.cpp
	./tiempo_exec

clean:
	rm -f tiempo_exec
