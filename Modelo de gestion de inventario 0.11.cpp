#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // Para usar system("cls") o system("clear")

using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(string n, double p, int c) : nombre(n), precio(p), cantidad(c) {}

    string getNombre() { return nombre; }
    double getPrecio() { return precio; }
    int getCantidad() { return cantidad; }

    void setNombre(string n) { nombre = n; }
    void setPrecio(double p) { precio = p; }
    void setCantidad(int c) { cantidad = c; }

    void mostrarProducto() {
        cout << "Nombre: " << nombre << " | Precio: " << precio << " | Cantidad: " << cantidad << endl;
    }

    bool vender(int cantidadVendida) {
        if (cantidadVendida > cantidad) {
            cout << "No hay suficiente inventario para vender esa cantidad.\n";
            return false;
        }
        cantidad -= cantidadVendida;
        return true;
    }
};

class Inventario {
private:
    vector<Producto> productos;

    // Función para limpiar la pantalla (compatible con Windows y Linux)
    void limpiarPantalla() {
#ifdef _WIN32
        system("cls"); // Comando para limpiar la pantalla en Windows
#else
        system("clear"); // Comando para limpiar la pantalla en Linux/macOS
#endif
    }

public:
    void agregarProducto() {
        string nombre;
        double precio;
        int cantidad;
        cout << "Ingrese el nombre del producto: ";
        cin.ignore(); // Ignorar el salto de línea pendiente del buffer
        getline(cin, nombre); // Permitir leer nombres con espacios
        cout << "Ingrese el precio del producto: ";
        cin >> precio;
        cout << "Ingrese la cantidad del producto: ";
        cin >> cantidad;
        productos.push_back(Producto(nombre, precio, cantidad));
        cout << "Producto agregado con éxito.\n";
    }

    void mostrarInventario() {
        limpiarPantalla(); // Limpiar la pantalla antes de mostrar el inventario
        if (productos.empty()) {
            cout << "El inventario está vacío.\n";
        }
        else {
            cout << "Inventario:\n";
            for (size_t i = 0; i < productos.size(); ++i) {
                cout << i + 1 << ". ";
                productos[i].mostrarProducto();
            }
        }
    }

    void modificarProducto() {
        mostrarInventario();
        int indice;
        cout << "Ingrese el número del producto a modificar: ";
        cin >> indice;
        if (indice > 0 && indice <= productos.size()) {
            string nombre;
            double precio;
            int cantidad;
            cout << "Ingrese el nuevo nombre del producto: ";
            cin.ignore(); // Ignorar el salto de línea pendiente del buffer
            getline(cin, nombre); // Permitir leer nombres con espacios
            cout << "Ingrese el nuevo precio del producto: ";
            cin >> precio;
            cout << "Ingrese la nueva cantidad del producto: ";
            cin >> cantidad;
            productos[indice - 1].setNombre(nombre);
            productos[indice - 1].setPrecio(precio);
            productos[indice - 1].setCantidad(cantidad);
            cout << "Producto modificado con éxito.\n";
        }
        else {
            cout << "Número de producto no válido.\n";
        }
    }

    void venderProducto() {
        mostrarInventario();
        int indice, cantidad;
        cout << "Ingrese el número del producto a vender: ";
        cin >> indice;
        if (indice > 0 && indice <= productos.size()) {
            cout << "Ingrese la cantidad a vender: ";
            cin >> cantidad;
            if (productos[indice - 1].vender(cantidad)) {
                cout << "Venta realizada con éxito.\n";
            }
        }
        else {
            cout << "Número de producto no válido.\n";
        }
    }
};

int main() {
    Inventario inventario;
    int opcion;

    do {
        // Limpiar la pantalla antes de mostrar el menú
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        cout << "\n--- Menú de Gestión de Inventario ---\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Modificar producto\n";
        cout << "4. Vender producto\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            inventario.agregarProducto();
            break;
        case 2:
            inventario.mostrarInventario();
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get(); // Pausa antes de limpiar la pantalla de nuevo
            break;
        case 3:
            inventario.modificarProducto();
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            break;
        case 4:
            inventario.venderProducto();
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción no válida. Intente nuevamente.\n";
            cout << "Presione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 5);

    return 0;
}


