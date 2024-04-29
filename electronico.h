#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include "producto.h"


class Electronico : public Producto {
public:
    int garantia;

    Electronico(string nombre, string marca, int precio, int descuento, int inventario, int garantia);
};


#endif // ELECTRONICO_H
