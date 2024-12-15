#ifndef HOJA_H
#define HOJA_H

#include "Celda.h"
#include "CeldaOperacion.h"
#include "CeldaMakefile.h"
#include <vector>
#include <iostream>

class Hoja {
public:
    Hoja(int filas, int columnas) : filas(filas), columnas(columnas) {
        tabla.resize(filas, std::vector<Celda*>(columnas, nullptr));
    }

    void establecerCelda(int fila, int columna, Celda* celda) {
        if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
            tabla[fila][columna] = celda;
        }
    }

    void mostrar() const {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                if (tabla[i][j]) {
                    std::cout << tabla[i][j]->obtenerValor() << "\t";
                } else {
                    std::cout << "Vacía\t";
                }
            }
            std::cout << std::endl;
        }
    }

private:
    int filas, columnas;
    std::vector<std::vector<Celda*>> tabla;
};

#endif
