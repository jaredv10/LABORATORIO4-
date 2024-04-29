#ifndef ASEO_H
#define ASEO_H

#include "producto.h"
using namespace std;

class Aseo : public Producto {
public:
    string material;

    Aseo(string nombre, string marca, int precio, int descuento, int inventario, string material);
};

#endif // ASEO_H
