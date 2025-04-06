#include "Banco.h"

#include <iostream>
#include <memory>

// Constructores

Banco::Banco(std::string _titular, double balance_inicial) 
    : titular(_titular), balance(balance_inicial) {}

Caja_de_ahorro::Caja_de_ahorro(std::string _titular, double balance_inicial) 
    : Banco(_titular, balance_inicial), veces_mostradas(0) {}

Cuenta_corriente::Cuenta_corriente(std::string _titular, double balance_inicial, std::shared_ptr<Caja_de_ahorro> _caja_de_ahorro) 
    : Banco(_titular, balance_inicial), caja_de_ahorro(_caja_de_ahorro) {}

// Metodos Caja de Ahorro

void Caja_de_ahorro::depositar(double dinero_depositar) {
    balance += dinero_depositar;
}

void Caja_de_ahorro::retirar(double dinero_retirar) {
    if (dinero_retirar > balance) {
        std::cout << "La cuenta no tiene fondos suficientes." << std::endl;
        return;
    } 
    balance -= dinero_retirar;
    return;
}

void Caja_de_ahorro::mostrar_info() {
    veces_mostradas = (veces_mostradas + 1) % 3;
    if (veces_mostradas == 0) {
        if (balance < 20) {
            std::cout << "No tienes fondos suficientes para mostrar la informacion." << std::endl;
            return;
        }
        balance -= 20;
    }
    std::cout << "\nCuenta:"
              << "\nTitular: " << titular
              << "\nTipo de cuenta: Caja de ahorro"
              << "\nBalance: " << balance << std::endl; 
}

// Metodos Cuenta Corriente

void Cuenta_corriente::depositar(double dinero_depositar) {
    balance += dinero_depositar;
}

void Cuenta_corriente::retirar(double dinero_retirar) {
    if (dinero_retirar > balance) { // Caso el dinero no alcance con el balance de la Cuenta Corriente
        if (dinero_retirar > balance + caja_de_ahorro->balance) { // Caso el dinero no alcance con el balance de la Cuenta Corriente y Cuanta de Ahorro
            std::cout << "La cuenta no tiene fondos suficientes." << std::endl;
            return;
        }
        balance -= dinero_retirar; // Le resto todo al balance de la Cuenta Corriente
        caja_de_ahorro->balance += balance; // Le saco lo que falta al balance de la Cuenta de Ahorro
        balance = 0.0; // Pongo en 0 el balance de la Cuenta Corriente
        return;
    }
    balance -= dinero_retirar; // Cuenta corriente
    return;
}

void Cuenta_corriente::mostrar_info() {
    std::cout << "\nCuenta:"
              << "\nTitular: " << titular
              << "\nTipo de cuenta: Cuenta corriente"
              << "\nBalance: " << balance << std::endl; 
}
