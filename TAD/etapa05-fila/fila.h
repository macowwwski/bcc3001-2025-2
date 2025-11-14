#include <stdbool.h>
#include <stdio.h>

typedef struct fila Fila;

Fila* fila_criar();
bool fila_inicializar(Fila* fila);
bool fila_anexar(int elemento, Fila* fila);
bool fila_deletar_primeiro(Fila* fila);