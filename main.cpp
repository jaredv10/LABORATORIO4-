#include <iostream>
#include <vector>
#include "producto.h"
#include "tienda.h"
#include "cuentacorriente.h"
#include "comestible.h"
#include "electronico.h"
#include "aseo.h"

using namespace std;

int main() {
    // Creación de una cuenta corriente
    string nombre, apellidos, direccion, telefono, numeroIdentificacion, clave;
    double saldo;

    cout << "¡Bienvenido a la Tienda Temática!\n";
    cout << "Por favor, ingrese sus datos para crear una cuenta corriente.\n";
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Apellidos: ";
    getline(cin, apellidos);
    cout << "Dirección: ";
    getline(cin, direccion);
    cout << "Teléfono: ";
    getline(cin, telefono);
    cout << "Número de identificación: ";
    getline(cin, numeroIdentificacion);
    cout << "Clave (ingrese 12345 si no tiene una clave): ";
    getline(cin, clave);
    cout << "Saldo inicial: ";
    cin >> saldo;
    cin.ignore(); // Limpiar el buffer del salto de línea

    CuentaCorriente cuenta(nombre, apellidos, direccion, telefono, numeroIdentificacion, clave, saldo);

    // Creación de la tienda
    Tienda tienda;

    // Agregar algunos productos a la tienda (solo como ejemplo)
    tienda.agregar_producto(new Comestible("Manzanas", "FruitCo", 50, 0, 10, "01/05/2024"));
    tienda.agregar_producto(new Electronico("Teléfono", "TechCorp", 1000, 10, 5, 12));
    tienda.agregar_producto(new Aseo("Jabón", "CleanCare", 5, 0, 20, "Plástico"));

    int opcion;
    do {
        cout << "\n*** Menú de la Tienda Temática ***\n";
        cout << "1. Agregar productos al carrito.\n";
        cout << "2. Modificar nombres, precios o % descuento de productos.\n";
        cout << "3. Realizar compra.\n";
        cout << "4. Salir.\n";
        cout << "Ingrese el número de la opción que desea realizar: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer del salto de línea

        switch (opcion) {
            case 1: {
                if (!tienda.productos.empty()) {
                    cout << "\n*** Catálogo de Productos ***\n";
                    cout << "Productos disponibles:\n";
                    for (size_t i = 0; i < tienda.productos.size(); ++i) {
                        cout << i+1 << ". " << tienda.productos[i]->nombre << " - Precio: $" << tienda.productos[i]->precio << "\n";
                    }
                    size_t seleccion;
                    cout << "Seleccione el producto que desea agregar al carrito (Ingrese el número): ";
                    cin >> seleccion;
                    cin.ignore(); // Limpiar el buffer del salto de línea
                    if (seleccion >= 1 && seleccion <= tienda.productos.size()) {
                        tienda.agregar_al_carrito(tienda.productos[seleccion-1]);
                        cout << "¡Producto agregado al carrito!\n";
                    } else {
                        cout << "¡Opción no válida!\n";
                    }
                } else {
                    cout << "No hay productos disponibles.\n";
                }
                break;
            }
            case 2: {
                if (!tienda.productos.empty()) {
                    cout << "\n*** Modificación de Productos ***\n";
                    cout << "Seleccione el producto que desea modificar:\n";
                    for (size_t i = 0; i < tienda.productos.size(); ++i) {
                        cout << i+1 << ". " << tienda.productos[i]->nombre << "\n";
                    }
                    size_t seleccion;
                    cout << "Ingrese el número del producto que desea modificar: ";
                    cin >> seleccion;
                    cin.ignore(); // Limpiar el buffer del salto de línea
                    if (seleccion >= 1 && seleccion <= tienda.productos.size()) {
                        cout << "\nSeleccione qué desea modificar:\n";
                        cout << "1. Nombre\n";
                        cout << "2. Precio\n";
                        cout << "3. % Descuento\n";
                        int opcion_modificacion;
                        cout << "Ingrese el número de la opción que desea modificar: ";
                        cin >> opcion_modificacion;
                        cin.ignore(); // Limpiar el buffer del salto de línea
                        string nuevo_nombre;
                        int nuevo_precio, nuevo_descuento;
                        switch (opcion_modificacion) {
                            case 1:
                                cout << "Ingrese el nuevo nombre: ";
                                getline(cin, nuevo_nombre);
                                tienda.modificar_producto(tienda.productos[seleccion-1], nuevo_nombre);
                                cout << "¡Nombre modificado exitosamente!\n";
                                break;
                            case 2:
                                cout << "Ingrese el nuevo precio: $";
                                cin >> nuevo_precio;
                                tienda.modificar_producto(tienda.productos[seleccion-1], "", nuevo_precio);
                                cout << "¡Precio modificado exitosamente!\n";
                                break;
                            case 3:
                                cout << "Ingrese el nuevo % descuento: ";
                                cin >> nuevo_descuento;
                                tienda.modificar_producto(tienda.productos[seleccion-1], "", -1, nuevo_descuento);
                                cout << "% Descuento modificado exitosamente!\n";
                                break;
                            default:
                                cout << "¡Opción no válida!\n";
                                break;
                        }
                    } else {
                        cout << "¡Opción no válida!\n";
                    }
                } else {
                    cout << "No hay productos disponibles para modificar.\n";
                }
                break;
            }
            case 3:
                if (!tienda.carrito.empty()) {
                    cout << "\n*** Resumen de Compra ***\n";
                    int total = 0;
                    for (auto producto : tienda.carrito) {
                        cout << "Producto: " << producto->nombre << " - Precio: $" << producto->precio << "\n";
                        total += producto->precio;
                    }
                    cout << "Total: $" << total << "\n";
                    cout << "¡Gracias por su compra!\n";
                    for (auto producto : tienda.carrito) {
                        producto->inventario--;
                    }
                    tienda.carrito.clear();
                } else {
                    cout << "¡No hay productos en el carrito para realizar la compra!\n";
                }
                break;
            case 4:
            cout << "¡Gracias por visitar la Tienda Temática! ¡Hasta pronto!\n";
            break;
            default:
            cout << "Opción no válida. Por favor, ingrese una opción válida.\n";
            break;
            }
            } while (opcion != 4);
    for (auto producto : tienda.productos) {
        delete producto;
    }

    return 0;
 }
