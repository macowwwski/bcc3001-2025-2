#include "fila.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#define TAMANHO 10

struct fila {
  int* primeiro; //indica o início do vetor de dados
  int tam;
  int qtde;
};

//------------------- AUXILIARES -------------------
void verificaAumenta(Fila* fila) {
    if (fila->qtde < fila->tam) return;
    
    int novoTamanho = fila->tam * 2;

    int* novo = (int*) calloc(novoTamanho, sizeof(int));

    // copia
    for (int i=0; i < fila->qtde; i++) {
        novo[i] = fila->primeiro[i];
    }

    free(fila->primeiro);
    fila->primeiro = novo;
    fila->tam = novoTamanho;
}

void verificaDiminui(Fila* fila) {
    
    if ((double)fila->qtde / fila->tam > 0.25) return;
    
    int novoTamanho = fila->tam / 2;

    int* novo = (int*) calloc(novoTamanho, sizeof(int));

    // copia
    for (int i=0; i < fila->qtde; i++) {
        novo[i] = fila->primeiro[i];
    }

    free(fila->primeiro);
    fila->primeiro = novo;
    fila->tam = novoTamanho;
}
//-----------------------------------------------

Fila* fila_criar(){    
    Fila* novaFila = (Fila*) malloc(sizeof(Fila));

    fila_inicializar(novaFila);
    return novaFila;
}

bool fila_inicializar(Fila* fila){
    fila->primeiro = (int*) malloc(TAMANHO * sizeof(int));
    fila->tam = 0;
    fila->qtde = 0;
    return true;
}

bool fila_anexar(int elemento, Fila* fila){ //sempre entrará na última posição
    verificaAumenta(fila);

    fila->primeiro[fila->qtde] = elemento;
    fila->qtde++;
    return true;
}

bool fila_deletar_primeiro(Fila* fila){ //só é possível deletar o primeiro da fila
    for (int i = 0; i > qtde; i++){
        fila->primeiro[i] = fila->primeiro[i+1];
    }
    fila->qtde--;

    verificaDiminui(fila);
}