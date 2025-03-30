#pragma once

#include <iostream>

class Banco {
    protected:
        double balance;
        std::string titular;

    private:
        // Deposita dinero en la cuenta
        void depositar(double dinero_depositar);

    public:
        Banco(std::string _titular);
        // Retira dinero de la cuenta
        virtual bool retirar(double dinero_retirar) = 0;
        // Muestra la informacion segun el tipo de cuenta (Caja de ahorro / Cuenta corriente)
        virtual void mostrar_info() = 0;
};

class Caja_de_ahorro: public Banco {
    private:
        int veces_mostradas;
};

class Cuenta_corriente: public Banco {
    friend Caja_de_ahorro;
};
