#include "Tiempo.h"
#include <iostream>
#include <limits>
#include <iomanip>

void limpiar_entrada() {
    std::cin.clear(); // Limpiar estado de error de cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar el resto de la entrada
}

int pedir_tiempo(int& horas, int& minutos, int& segundos, std::string& periodo) {
    std::cout << "Ingrese el tiempo con el siguiente formato HH MM SS a.m/p.m.\n"
    << "En caso de dejar alguna posición vacía, se autocompleta con 00 y a.m." << std::endl;
    std::cout << "\nHoras: ";
    if (!(std::cin >> std::setw(3) >> horas)) { // Caso que no se asigne nada a horas
        horas = 0;
        minutos = 0;
        segundos = 0;
        periodo = "a.m.";
        limpiar_entrada();
        return 0;
    } 
    std::cout << "\nMinutos: ";
    if (!(std::cin >> std::setw(3)  >> minutos)) { // Caso que no se asigne nada a minutos
        minutos = 0;
        segundos = 0;
        periodo = "a.m.";
        limpiar_entrada();
        return 1;
    } 
    std::cout << "\nSegundos: ";
    if (!(std::cin >> std::setw(3)  >> segundos)) { // Caso que no se asigne nada a segundos
        segundos = 0;
        periodo = "a.m.";
        limpiar_entrada();
        return 2;
    } 
    std::cout << "\na.m./p.m.: ";
    if (!(std::cin >> std::setw(5)  >> periodo)) { // Caso que no se asigne nada a periodo
        periodo = "a.m.";
        limpiar_entrada();
        return 3;
    }
    return 4;
}

int main() {
    int horas, minutos, segundos, items, error;
    std::string periodo;
    bool seguir = true;
    while (seguir == true) {
        items = pedir_tiempo(horas, minutos, segundos, periodo);
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
                    std::cout << "[ERROR]: " << e.what() << std::endl;
                    error = 1;
                }
                break;
            case 2:
                try {
                    reloj = Tiempo(horas, minutos);
                } catch (std::runtime_error& e) {
                    std::cout << "[ERROR]: " << e.what() << std::endl;
                    error = 1;
                }
                break;
            case 3:
                try {
                    reloj = Tiempo(horas, minutos, segundos);
                } catch (std::runtime_error& e) {
                    std::cout << "[ERROR]: " << e.what() << std::endl;
                    error = 1;
                }
                break;
            case 4:
                try {
                    reloj = Tiempo(horas, minutos, segundos, periodo);
                } catch (std::runtime_error& e) {
                    std::cout << "[ERROR]: " << e.what() << std::endl;
                    error = 1;
                }
                break;
        }
        if (error == 0) {
            int accion = 9;
            bool hs24;
            while (accion >= 0) {
                do {
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
                    limpiar_entrada();
                } while (accion < -1 || accion > 8);
                hs24 = false;
                switch (accion) {
                    case 0:
                        std::cout << "Nueva hora: ";
                        std::cin >> horas;
                        reloj.set_hora(horas);
                        break;
                    case 1:
                        std::cout << "Nuevos minutos: ";
                        std::cin >> minutos;
                        reloj.set_minutos(minutos);
                        break;
                    case 2:
                        std::cout << "Nuevos segundos: ";
                        std::cin >> segundos;
                        reloj.set_segundos(segundos);
                        break;
                    case 3:
                        std::cout << "Nuevo período (a.m./p.m.): ";
                        std::cin >> periodo;
                        reloj.set_periodo(periodo);
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
}
