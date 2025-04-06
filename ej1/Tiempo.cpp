#include "Tiempo.h"

#include <iostream>
#include <iomanip>

// Constructor 00h:00m:00s am.
Tiempo::Tiempo() { 
    horas = 0;
    minutos = 0;
    segundos = 0;
    periodo = "a.m.";
}
// Constructor HHh:00m:00s am.
Tiempo::Tiempo(int horas_param) {
    if (horas_param > 11 || horas_param < 0) throw std::runtime_error("La hora no es correcta, debe ser un valor entre 0 y 11");
    horas = horas_param;
    minutos = 0;
    segundos = 0;
    periodo = "a.m.";
}
// Constructor HHh:MMm:00s am.
Tiempo::Tiempo(int horas_param, int minutos_param) {
    if (horas_param > 11 || horas_param < 0) throw std::runtime_error("La hora no es correcta, debe ser un valor entre 0 y 11");
    if (minutos_param > 59 || minutos_param < 0) throw std::runtime_error("Los minutos no son correctas, debe ser un valor entre 0 y 59");
    horas = horas_param;
    minutos = minutos_param;
    segundos = 0;
    periodo = "a.m.";
}
// Constructor HHh:MMm:SSs am.
Tiempo::Tiempo(int horas_param, int minutos_param, int segundos_param) {
    if (horas_param > 11 || horas_param < 0) throw std::runtime_error("La hora no es correcta, debe ser un valor entre 0 y 11");
    if (minutos_param > 59 || minutos_param < 0) throw std::runtime_error("Los minutos no son correctas, debe ser un valor entre 0 y 59");
    if (segundos_param > 59 || segundos_param < 0) throw std::runtime_error("Los segundos no son correctas, debe ser un valor entre 0 y 59");
    horas = horas_param;
    minutos = minutos_param;
    segundos = segundos_param;
    periodo = "a.m.";
}
// Constructor HHh:MMm:SSs am/pm.
Tiempo::Tiempo(int horas_param, int minutos_param, int segundos_param, std::string periodo_param) {
    if (horas_param > 11 || horas_param < 0) throw std::runtime_error("La hora no es correcta, debe ser un valor entre 0 y 11");
    if (minutos_param > 59 || minutos_param < 0) throw std::runtime_error("Los minutos no son correctas, debe ser un valor entre 0 y 59");
    if (segundos_param > 59 || segundos_param < 0) throw std::runtime_error("Los segundos no son correctas, debe ser un valor entre 0 y 59");
    if (periodo_param != "a.m." && periodo_param != "p.m.") throw std::runtime_error("El formato es incorrecto, debe ser 'a.m.' o 'p.m.'");
    horas = horas_param;
    minutos = minutos_param;
    segundos = segundos_param;
    periodo = periodo_param;
}

// Setter's
void Tiempo::set_hora(int nueva_hora) {
    if (nueva_hora > 11 || nueva_hora < 0) throw std::runtime_error("La hora no es correcta, debe ser un valor entre 0 y 11");
    horas = nueva_hora;
}
void Tiempo::set_minutos(int nuevos_minutos) {
    if (nuevos_minutos > 59 || nuevos_minutos < 0) throw std::runtime_error("Los minutos no son correctas, debe ser un valor entre 0 y 59");
    minutos = nuevos_minutos;
}
void Tiempo::set_segundos(int nuevos_segundos) {
    if (nuevos_segundos > 59 || nuevos_segundos < 0) throw std::runtime_error("Los segundos no son correctas, debe ser un valor entre 0 y 59");
    segundos = nuevos_segundos;
}
void Tiempo::set_periodo(std::string nuevo_periodo) {
    if (nuevo_periodo != "a.m." && nuevo_periodo != "p.m.") throw std::runtime_error("El formato es incorrecto, debe ser 'a.m.' o 'p.m.'");
    periodo = nuevo_periodo;
}

// Print's
void Tiempo::print_hora(bool hs24) {
    if (hs24 == false) { // Caso a.m. o p.m.
        std::cout << horas << "hs" << std::endl;
    } else { // Caso de que sea formato 24hs
        if (periodo == "a.m.") {
            std::cout << horas << "hs" << std::endl;
        } else {
            std::cout << horas + 12 << "hs" << std::endl;
        }
    }
}
void Tiempo::print_minutos() {
    std::cout << minutos << 'm' << std::endl;
}
void Tiempo::print_segundos() {
    std::cout << segundos << 's' << std::endl;
}
void Tiempo::print_periodo() {
    std::cout << periodo << std::endl;
}
void Tiempo::print_tiempo(bool hs24) {
    if (hs24 == false) { // Caso a.m. o p.m.
        std::cout << std::setw(2) << std::setfill('0') << horas << "h "
                    << std::setw(2) << minutos << "m "
                    << std::setw(2) << segundos << "s " << periodo << std::endl;
    } else { // Caso de que sea formato 24hs
        if (periodo == "a.m.") {
            std::cout << std::setw(2) << std::setfill('0') << horas << "h "
                        << std::setw(2) << minutos << "m "
                        << std::setw(2) << segundos << "s" << std::endl;
        } else {
            std::cout << std::setw(2) << std::setfill('0') << horas + 12 << "h "
                        << std::setw(2) << minutos << "m "
                        << std::setw(2) << segundos << "s" << std::endl;
        }
    }
}
