#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
using namespace std;

class Producto {
public:
    string get_nombre() const;
    string nombre;
    string marca;
    int precio;
    int descuento;
    int inventario;

    Producto(string nombre, string marca, int precio, int descuento, int inventario);
};



#endif // PRODUCTO_H
