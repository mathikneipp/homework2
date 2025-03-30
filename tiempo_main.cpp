#include "Tiempo.h"
#include <iostream>
#include <limits>
#include <iomanip>

void reset(int& horas, int& minutos, int& segundos, std::string& periodo) {
    horas = 0;
    minutos = 0;
    segundos = 0;
    periodo = "a.m.";
}

int main() {
    int horas, minutos, segundos, items, error;
    int if_horas, if_minutos, if_segundos, if_periodo;
    std::string periodo;
    bool seguir = true;
    while (seguir == true || error != 0) {
        items = 0;
        reset(horas, minutos, segundos, periodo); // Pongo todo en 0 y a.m.
        std::cout << "\nHoras: 1 (SI), otro num (NO): "; // Pregunto por horas
        std::cin >> if_horas;
        if (if_horas == 1) {
            std::cout << "\nHoras: ";
            std::cin >> horas;
            items++;

            std::cout << "\nMinutos: 1 (SI), otro num (NO): "; // Pregunto por minutos
            std::cin >> if_minutos;
            if (if_minutos == 1) {
                std::cout << "\nMinutos: ";
                std::cin >> minutos;
                items++;

                std::cout << "\nSegundos: 1 (SI), otro num (NO): "; // Pregunto por segundos
                std::cin >> if_segundos;
                if (if_segundos == 1) {
                    std::cout << "\nSegundos: ";
                    std::cin >> segundos;
                    items++;

                    std::cout << "\nPeriodo: 1 (SI), otro num (NO): "; // Pregunto por periodo
                    std::cin >> if_periodo;
                    if (if_periodo == 1) {
                        std::cout << "\nPeriodo: ";
                        std::cin >> periodo;
                        items++;
                    }
                }
            }
        }

        std::cout << std::endl;

        error = 0;
        Tiempo reloj;
        switch (items) {
            case 0:
                reloj = Tiempo();
                break;
            case 1:
                try {
                    reloj = Tiempo(horas);
                } catch (std::runtime_error& e) {
                    std::cout << "[ERROR]: " << e.what() << std::endl; // Caso que se ingrese un valor erroneo
                    error = 1;
                }
                break;
            case 2:
                try {
                    reloj = Tiempo(horas, minutos);
                } catch (std::runtime_error& e) {
                    std::cout << "[ERROR]: " << e.what() << std::endl; // Caso que se ingrese un valor erroneo
                    error = 1;
                }
                break;
            case 3:
                try {
                    reloj = Tiempo(horas, minutos, segundos);
                } catch (std::runtime_error& e) {
                    std::cout << "[ERROR]: " << e.what() << std::endl; // Caso que se ingrese un valor erroneo
                    error = 1;
                }
                break;
            case 4:
                try {
                    reloj = Tiempo(horas, minutos, segundos, periodo);
                } catch (std::runtime_error& e) {
                    std::cout << "[ERROR]: " << e.what() << std::endl; // Caso que se ingrese un valor erroneo
                    error = 1;
                }
                break;
        }
        int accion = 9;
        bool hs24;
        if (error == 0) {
            while (accion >= 0) {
                do {
                    accion = 9;
                    std::cout << "\n-1: salir,\n"
                            << "0: set_hora,\n"
                            << "1: set_minutos,\n"
                            << "2: set_segundos,\n"
                            << "3: set_periodo,\n"
                            << "4: get_hora,\n"
                            << "5: get_minutos,\n"
                            << "6: get_segundos,\n"
                            << "7: get_periodo,\n"
                            << "8: get_tiempo,\n"
                            << "Opción: ";
                    std::cin >> accion;
                } while (accion < -1 || accion > 8);
                hs24 = false;
                switch (accion) {
                    case 0:
                        std::cout << "Nueva hora: ";
                        std::cin >> horas;
                        try {
                            reloj.set_hora(horas);
                        } catch (std::runtime_error& e) {
                            std::cout << "[ERROR]: " << e.what() << std::endl; // Caso que se ingrese un valor erroneo
                        }
                        break;
                    case 1:
                        std::cout << "Nuevos minutos: ";
                        std::cin >> minutos;
                        try {
                        reloj.set_minutos(minutos);
                        } catch (std::runtime_error& e) {
                            std::cout << "[ERROR]: " << e.what() << std::endl; // Caso que se ingrese un valor erroneo
                        }
                        break;
                    case 2:
                        std::cout << "Nuevos segundos: ";
                        std::cin >> segundos;
                        try {
                        reloj.set_segundos(segundos);
                        } catch (std::runtime_error& e) {
                            std::cout << "[ERROR]: " << e.what() << std::endl; // Caso que se ingrese un valor erroneo
                        }
                        break;
                    case 3:
                        std::cout << "Nuevo período (a.m./p.m.): ";
                        std::cin >> periodo;
                        try {
                        reloj.set_periodo(periodo);
                        } catch (std::runtime_error& e) {
                            std::cout << "[ERROR]: " << e.what() << std::endl; // Caso que se ingrese un valor erroneo
                        }
                        break;
                    case 4:
                        std::cout << "¿Formato 24hs? (1: sí, 0: no): ";
                        std::cin >> hs24;
                        reloj.print_hora(hs24);
                        break;
                    case 5:
                        reloj.print_minutos();
                        break;
                    case 6:
                        reloj.print_segundos();
                        break;
                    case 7:
                        reloj.print_periodo();
                        break;
                    case 8:
                        std::cout << "¿Formato 24hs? (1: sí, 0: no): ";
                        std::cin >> hs24;
                        reloj.print_tiempo(hs24);
                        break;
                } 
            }
        }
        std::cout << "¿Devuelta? (1: sí, 0: no): ";
        std::cin >> seguir;
    }
    return 0;
}
