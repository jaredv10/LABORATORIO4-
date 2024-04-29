#ifndef COMESTIBLE_H
#define COMESTIBLE_H
#include "producto.h"
using namespace std;

class Comestible : public Producto {
public:
   std::string fecha_vencimiento;

    Comestible(string nombre, string marca, int precio, int descuento, int inventario, string fecha_vencimiento);
};


#endif // COMESTIBLE_H
