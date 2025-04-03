#include <iostream>
#include <utility>

#include "Numero.h"
#include <memory>

// Constructor Numero
Numero::Numero() = default;

// Enteros

Entero::Entero(int _valor) 
    : valor(_valor) {}

std::unique_ptr<Numero> Entero::operator+(const Numero& otro) const {
    const Entero* otro_entero = dynamic_cast<const Entero*>(&otro); // Casteo de Numero a Entero
    if (otro_entero == nullptr) { // Caso de que no sea Entero
        throw std::invalid_argument("La suma no es de enteros."); // ????? CONSULTAR ESTO ?????
    }
    return std::make_unique<Entero>(valor + otro_entero->valor); // Crea el puntero y el nuevo Entero y lo devuelve.
}

std::unique_ptr<Numero> Entero::operator-(const Numero& otro) const {
    const Entero* otro_entero = dynamic_cast<const Entero*>(&otro); // Casteo de Numero a Entero
    if (otro_entero == nullptr) { // Caso de que no sea Entero
        throw std::invalid_argument("La resta no es de enteros.");
    }
    return std::make_unique<Entero>(valor - otro_entero->valor); // Crea el puntero y el nuevo Entero y lo devuelve.
}

std::unique_ptr<Numero> Entero::operator*(const Numero& otro) const {
    const Entero* otro_entero = dynamic_cast<const Entero*>(&otro); // Casteo de Numero a Entero
    if (otro_entero == nullptr) { // Caso de que no sea Entero
        throw std::invalid_argument("La multiplicacion no es de enteros.");
    }
    return std::make_unique<Entero>(valor * otro_entero->valor); // Crea el puntero y el nuevo Entero y lo devuelve.
}

std::string Entero::to_string() const {
    return std::to_string(valor); // Pasa el numero a string
}

// Reales

Real::Real(double _valor)
    : valor(_valor) {}

std::unique_ptr<Numero> Real::operator+(const Numero& otro) const {
    const Real* otro_entero = dynamic_cast<const Real*>(&otro); // Casteo de Numero a Real
    if (otro_entero == nullptr) { // Caso de que no sea Real
        throw std::invalid_argument("La suma no es de reales.");
    }
    return std::make_unique<Real>(valor + otro_entero->valor); // Crea el puntero y el nuevo Real y lo devuelve.
}

std::unique_ptr<Numero> Real::operator-(const Numero& otro) const {
    const Real* otro_entero = dynamic_cast<const Real*>(&otro); // Casteo de Numero a Real
    if (otro_entero == nullptr) { // Caso de que no sea Real
        throw std::invalid_argument("La resta no es de reales.");
    }
    return std::make_unique<Real>(valor - otro_entero->valor); // Crea el puntero y el nuevo Real y lo devuelve.
}

std::unique_ptr<Numero> Real::operator*(const Numero& otro) const {
    const Real* otro_entero = dynamic_cast<const Real*>(&otro); // Casteo de Numero a Real
    if (otro_entero == nullptr) { // Caso de que no sea Real
        throw std::invalid_argument("La multiplicacion no es de reales.");
    }
    return std::make_unique<Real>(valor * otro_entero->valor); // Crea el puntero y el nuevo Real y lo devuelve.
}

std::string Real::to_string() const {
    return std::to_string(valor);  // Pasa el numero a string
}

// Complejos

Complejo::Complejo(double real, double imag)
    : valor(real, imag) {}

std::unique_ptr<Numero> Complejo::operator+(const Numero& otro) const {
    const Complejo* otro_entero = dynamic_cast<const Complejo*>(&otro); // Casteo de Numero a Complejo
    if (otro_entero == nullptr) { // Caso de que no sea Complejo
        throw std::invalid_argument("La suma no es de complejos.");
    }
    double a = valor.first;
    double b = valor.second;
    double c = otro_entero->valor.first;
    double d = otro_entero->valor.second;
    return std::make_unique<Complejo>(a + c, b + d); // Crea el puntero y el nuevo Complejo y lo devuelve.
}

std::unique_ptr<Numero> Complejo::operator-(const Numero& otro) const {
    const Complejo* otro_entero = dynamic_cast<const Complejo*>(&otro); // Casteo de Numero a Complejo
    if (otro_entero == nullptr) { // Caso de que no sea Complejo
        throw std::invalid_argument("La resta no es de complejos.");
    }
    double a = valor.first;
    double b = valor.second;
    double c = otro_entero->valor.first;
    double d = otro_entero->valor.second;
    return std::make_unique<Complejo>(a + c, b + d); // Crea el puntero y el nuevo Complejo y lo devuelve.
}

std::unique_ptr<Numero> Complejo::operator*(const Numero& otro) const {
    const Complejo* otro_entero = dynamic_cast<const Complejo*>(&otro); // Casteo de Numero a Complejo
    if (otro_entero == nullptr) { // Caso de que no sea Complejo
        throw std::invalid_argument("La multiplicacion no es de complejos.");
    }
    double a = valor.first;
    double b = valor.second;
    double c = otro_entero->valor.first;
    double d = otro_entero->valor.second;
    return std::make_unique<Complejo>(a*c - b*d, a*d + b*c); // Crea el puntero y el nuevo Complejo y lo devuelve.
}

std::string Complejo::to_string() const {
    return std::to_string(valor.first) + " + " + std::to_string(valor.second) + "i" ;  // Pasa el numero a string
}
