#include "tienda.h"
#include <iostream>

void Tienda::agregar_producto(Producto* producto) {
    productos.push_back(producto);
}

void Tienda::modificar_producto(Producto* producto, string nombre, int precio, int descuento) {
    if (nombre != "") {
        producto->nombre = nombre;
    }
    if (precio != -1) {
        producto->precio = precio;
    }
    if (descuento != -1) {
        producto->descuento = descuento;
    }
}

void Tienda::agregar_al_carrito(Producto* producto) {
    if (producto->inventario > 0) {
        carrito.push_back(producto);
    } else {
        std::cout << "El producto está agotado.\n";
    }
}
void Tienda::realizar_compra(CuentaCorriente* cuenta) {
    int total = 0;
    for (auto producto : carrito) {
        total += producto->precio;
    }
    if (total <= cuenta->getSaldo()) {
        cuenta->retirarDinero(total);
        std::cout << "Compra realizada exitosamente.\n";
        for (auto producto : carrito) {
            producto->inventario--;
        }
        carrito.clear();
    } else {
        std::cout << "Saldo insuficiente.\n";
    }
}

