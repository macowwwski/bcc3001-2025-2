#include <iostream>

using namespace std;

class No{
public: 
    int dado;
    No* prox;
    No* ant;

    No(){}

    No(int elemento){
        this->dado = elemento;
        this->ant = nullptr;
        this->prox = nullptr;    
    }
};


class Fila {
private:
    No* prim;
    No* fim;
    int qtde;
  

public:
    Fila(){
        // cout << "construtor" << endl;
        this->prim = nullptr;   //1º nó nulo
        this->fim = nullptr;    //último nó nulo
        this->qtde = 0;         
    }

    ~Fila() {
        // cout << "DEStrutor" << endl;
        No* aux;
        while (this->prim != nullptr) { //enquanto o 1º não for nulo
            aux = this->prim; //auxiliar recebe o 1º nó, que será apagado
            this->prim = this->prim->prox; //1º recebe o próximo nó, pois a deleção sempre acontece na primeira posição
            delete aux; //usa o ponteiro armazenado em aux para deletar o nó
        }
    }

    bool anexar(int elemento){
        No* novo = new No(elemento);

        if (this->qtde == 0){ //fila vazia
            this->prim = novo;
            this->fim = nullptr;
        } else{
            this->fim->prox = novo;
            novo->ant = this->fim;
            this->fim = novo;
        }

        this->qtde++;
        return true;
    }

    bool remover(){
        No* aux = this->prim;

        if (this->qtde == 0) return false;

        if (this->qtde == 1){ //só um elemento
            this->prim = nullptr;
            this->fim = nullptr;
        } else{ //mais de um elemento -> remove sempre o prim
            this->prim = this->prim->prox;
            this->prim->ant = nullptr;
        }

        delete aux;
        this->qtde--;
        return true;
    }

}