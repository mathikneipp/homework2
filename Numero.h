#pragma once

#include <iostream>
#include <utility>
#include <memory>

class Numero {
    public:
        //Constructor
        Numero();

        // Suma de 2 numeros
        virtual std::unique_ptr<Numero> operator+(const Numero& otro) const = 0;
        // Resta de 2 numeros
        virtual std::unique_ptr<Numero> operator-(const Numero& otro) const = 0;
        // Multiplicacion de 2 numeros
        virtual std::unique_ptr<Numero> operator*(const Numero& otro) const = 0;
        //Convierte a string el numero
        virtual std::string to_string() const = 0;
};

class Entero: public Numero {
    private:
        int valor;
    public:
        Entero(int _valor);
        std::unique_ptr<Numero> operator+(const Numero& otro) const override;
        std::unique_ptr<Numero> operator-(const Numero& otro) const override;
        std::unique_ptr<Numero> operator*(const Numero& otro) const override;
        std::string to_string() const override;
};

class Real: public Numero {
    private:
        double valor;
    public:
        Real(double _valor);
        std::unique_ptr<Numero> operator+(const Numero& otro) const override;
        std::unique_ptr<Numero> operator-(const Numero& otro) const override;
        std::unique_ptr<Numero> operator*(const Numero& otro) const override;
        std::string to_string() const override;
};

class Complejo: public Numero {
    private:
        std::pair<double, double> valor;
    public:  
        Complejo(double real, double imag);
        std::unique_ptr<Numero> operator+(const Numero& otro) const override;
        std::unique_ptr<Numero> operator-(const Numero& otro) const override;
        std::unique_ptr<Numero> operator*(const Numero& otro) const override;
        std::string to_string() const override;
};


