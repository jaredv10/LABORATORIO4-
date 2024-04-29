#include "electronico.h"

Electronico::Electronico(string nombre, string marca, int precio, int descuento, int inventario, int garantia) :
    Producto(nombre, marca, precio, descuento, inventario), garantia(garantia) {}
