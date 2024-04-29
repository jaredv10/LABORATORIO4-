#include "aseo.h"

Aseo::Aseo(string nombre, string marca, int precio, int descuento, int inventario,string material) :
    Producto(nombre, marca, precio, descuento, inventario), material(material) {}
