#include "Banco.h"

#include <iostream>

Banco::Banco(std::string _titular) : titular(_titular), balance(0.0) {}

void Caja_de_ahorro::depositar(double dinero_depositar) {
    balance += dinero_depositar;
}

bool Caja_de_ahorro::retirar(double dinero_retirar) {
    if (dinero_retirar <= balance) {
        std::cout << "No se puede retirar mas dinero del disponible" << std::endl;
        return false;
    } 
    balance -= dinero_retirar;
    return true;
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

void Cuenta_corriente::depositar(double dinero_depositar) {
    balance += dinero_depositar;
}

bool Cuenta_corriente::retirar(double dinero_retirar) {
    if (balance < dinero_retirar) {
        if (balance + balance < dinero_retirar) { // Balance cuenta corriente + cuenta de ahorro
            std::cout << "La cuenta no tiene fondos suficientes." << std::endl;
            return false;
        }
        balance -= dinero_retirar; // Cuenta corriente
        balance += balance; // Cuanta de ahorro / cuenta corriente
        balance = 0.0; // Cuenta corriente
        return true;
    }
    balance -= dinero_retirar; // Cuenta corriente
    return true;
}

void Cuenta_corriente::mostrar_info() {
    std::cout << "\nCuenta:"
              << "\nTitular: " << titular
              << "\nTipo de cuenta: Cuenta corriente"
              << "\nBalance: " << balance << std::endl; 
}
