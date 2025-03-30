#include "Numero.h"

#include <iostream>
#include <memory>

int main() {
    // Prueba Enteros

    std::unique_ptr<Entero> entero_a = std::make_unique<Entero>(4);
    std::unique_ptr<Entero> entero_b = std::make_unique<Entero>(3);

    std::cout << "\nEnteros:\n"
              << "\nEntero a = " << entero_a->to_string()
              << "\nEntero b = " << entero_b->to_string() << std::endl;
    
    // Suma
    {
        std::unique_ptr<Numero> resultado = *entero_a + *entero_b;
        std::cout << "\na + b = " << resultado->to_string() << std::endl;
    }
    // Resta
    {
        std::unique_ptr<Numero> resultado = *entero_a - *entero_b;
        std::cout << "\na - b = " << resultado->to_string() << std::endl;
    }
    // Multiplicacion
    {
        std::unique_ptr<Numero> resultado = *entero_a * *entero_b;
        std::cout << "\na * b = " << resultado->to_string() << std::endl;
    }
    
    // Prueba Reales

    std::unique_ptr<Real> real_a = std::make_unique<Real>(2.567);
    std::unique_ptr<Real> real_b = std::make_unique<Real>(4.715);

    std::cout << "\nReales:\n"
              << "\nReal a = " << real_a->to_string()
              << "\nReal b = " << real_b->to_string() << std::endl;
    // Suma
    {
        std::unique_ptr<Numero> resultado = *real_a + *real_b;
        std::cout << "\na + b = " << resultado->to_string() << std::endl;
    }
    // Resta
    {
        std::unique_ptr<Numero> resultado = *real_a - *real_b;
        std::cout << "\na - b = " << resultado->to_string() << std::endl;
    }
    // Multiplicacion
    {
        std::unique_ptr<Numero> resultado = *real_a * *real_b;
        std::cout << "\na * b = " << resultado->to_string() << std::endl;
    }  
    
    // Prueba Complejos

    std::unique_ptr<Complejo> complejo_a = std::make_unique<Complejo>(1, 2);
    std::unique_ptr<Complejo> complejo_b = std::make_unique<Complejo>(3, 4);

    std::cout << "\nComplejos:\n"
              << "\nComplejo a = " << complejo_a->to_string()
              << "\nComplejo b = " << complejo_b->to_string() << std::endl;   
    // Suma
    {
        std::unique_ptr<Numero> resultado = *complejo_a + *complejo_b;
        std::cout << "\na + b = " << resultado->to_string() << std::endl;
    }
    // Resta
    {
        std::unique_ptr<Numero> resultado = *complejo_a - *complejo_b;
        std::cout << "\na - b = " << resultado->to_string() << std::endl;
    }
    // Multiplicacion
    {
        std::unique_ptr<Numero> resultado = *complejo_a * *complejo_b;
        std::cout << "\na * b = " <<  resultado->to_string() << std::endl;
    }     
    return 0;
}
