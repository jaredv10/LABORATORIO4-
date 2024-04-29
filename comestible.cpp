#include "comestible.h"

Comestible::Comestible(string nombre, string marca, int precio, int descuento, int inventario, string fecha_vencimiento) :
    Producto(nombre, marca, precio, descuento, inventario), fecha_vencimiento(fecha_vencimiento) {}
