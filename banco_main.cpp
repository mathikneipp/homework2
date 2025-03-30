#include "Banco.h"

#include <iostream>
#include <memory>

double dinero_pedido(bool is_ingresar) {
    double dinero;
    if (is_ingresar) std::cout << "Ingrese cantidad a depositar ($): ";
    else std::cout << "Ingrese cantidad a retirar ($): ";
    std::cin >> dinero;
    if (std::cin.fail()) { // Caso de ingresar cualquier otra cosa
        throw std::runtime_error("Entrada inválida.");
    }
    return dinero;
}

int main() {
    bool run = true;
    std::string titular;
    int opcion = 0;
    double dinero;
    std::cout << "Ingrese el titular de la cuenta: ";
    std::cin >> std::ws; // Elimina los whitespaces del buffer
    std::getline(std::cin, titular); // Para tomar los espacios tambien
    std::shared_ptr<Caja_de_ahorro> caja_de_ahorro = std::make_shared<Caja_de_ahorro>(titular, 0.0); // Puntero a caja de ahorro
    std::unique_ptr<Cuenta_corriente> cuenta_corriente =  std::make_unique<Cuenta_corriente>(titular, 0.0, caja_de_ahorro); // Puntero a cuenta corriente

    while (run == true) {
        while (opcion < 1 || opcion > 8) {
            std::cout << "\nMenú Principal:\n"
                    << "1. Depositar dinero Caja de ahorro.\n"
                    << "2. Depositar dinero Cuenta corriente.\n"
                    << "3. Retirar dinero Caja de ahorro.\n"
                    << "4. Retirar dinero Cuenta corriente.\n"
                    << "5. Mostrar info Caja de ahorro.\n"
                    << "6. Mostrar info Cuenta corriente.\n"
                    << "7. Salir.\n"
                    << "Seleccionar opcion: ";
            std::cin >> opcion;
        }
        switch (opcion) {
            case 1:
                dinero = dinero_pedido(true);
                caja_de_ahorro->depositar(dinero);
                break;
            case 2:
                dinero = dinero_pedido(true);
                cuenta_corriente->depositar(dinero);
                break;
            case 3:
                dinero = dinero_pedido(false);
                caja_de_ahorro->retirar(dinero);
                break;
            case 4:
                dinero = dinero_pedido(false);
                cuenta_corriente->retirar(dinero);
                break;
            case 5:
                caja_de_ahorro->mostrar_info();
                break;
            case 6:
                cuenta_corriente->mostrar_info();
                break;
            case 7:
                run = false;
                break;
        }
        opcion = 0;
    }
    return 0;
}
