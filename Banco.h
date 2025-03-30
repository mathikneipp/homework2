#pragma once

#include <iostream>
#include <memory>

/*
 * protected, para que despues quede como private en las subclases y no se puedan modifiacar de afuera
 * el resto en public para poder usarlas de afuera
 */

class Banco {
    protected:
        std::string titular;
        double balance;
    public:
        // Constructor cuenta de banco
        Banco(std::string _titular, double balance_inicial);
        // Deposita dinero en la cuenta
        void depositar(double dinero_depositar);
        // Retira dinero de la cuenta
        virtual void retirar(double dinero_retirar) = 0;
        // Muestra la informacion segun el tipo de cuenta (Caja de ahorro / Cuenta corriente)
        virtual void mostrar_info() = 0;
};

/*
 * uso a Banco como public para usar los metodos, y tengo el contador de veces_mostradas para descontar los 20$
 */

class Cuenta_corriente;

class Caja_de_ahorro: public Banco {
    private:
        int veces_mostradas;
    public:
        Caja_de_ahorro(std::string titular, double balance_inicial);
        void depositar(double dinero_depositar);
        void retirar(double dinero_retirar) override;
        void mostrar_info() override;

    friend Cuenta_corriente;
};

/*
 *  uso a Banco como public para usar los metodos, y tengo el puntero a caja de ahorro para vincular las cuentas
 */

class Cuenta_corriente: public Banco {
    private:
        std::shared_ptr<Caja_de_ahorro> caja_de_ahorro; // Puntero a la caja de ahorro
    public:
        Cuenta_corriente(std::string titular, double balance_inicial, std::shared_ptr<Caja_de_ahorro> _caja_de_ahorro);
        void depositar(double dinero_depositar);
        void retirar(double dinero_retirar) override;
        void mostrar_info() override;
};
