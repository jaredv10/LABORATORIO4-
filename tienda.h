#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "producto.h"
#include "cuentacorriente.h"

class Tienda {
public:
    vector<Producto*> productos;
    vector<Producto*> carrito;

    void agregar_producto(Producto* producto);
    void modificar_producto(Producto* producto, string nombre = "", int precio = -1, int descuento = -1);
    void agregar_al_carrito(Producto* producto);
    void realizar_compra(CuentaCorriente* cuenta);
};

#endif // TIENDA_H
