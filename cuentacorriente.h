#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H

#include <string>

using namespace std;

class CuentaCorriente
{
private:
    string nombre;
    string apellidos;
    string direccion;
    string telefono;
    string numeroIdentificacion; // Nuevo atributo
    string clave; // Nuevo atributo
    double saldo;

public:
    CuentaCorriente();
    CuentaCorriente(string nombre, string apellidos, string direccion, string telefono, string numeroIdentificacion, string clave, double saldo);

    void setNombre(string nombre);
    string getNombre();

    void setApellidos(string apellidos);
    string getApellidos();

    void setDireccion(string direccion);
    string getDireccion();

    void setTelefono(string telefono);
    string getTelefono();

    void setNumeroIdentificacion(string numeroIdentificacion); // Nuevo método
    string getNumeroIdentificacion(); // Nuevo método

    void setClave(string clave); // Nuevo método
    string getClave(); // Nuevo método

    void setSaldo(double saldo);
    double getSaldo();

    void retirarDinero(double cantidad);
    void ingresarDinero(double cantidad);

    void consultarCuenta();

    bool saldoNegativo();
};

#endif // CUENTACORRIENTE_H
