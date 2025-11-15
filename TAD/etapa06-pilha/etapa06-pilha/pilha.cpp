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


class Pilha {
private:
    No* topo;
    int qtde;
    
public:
    Pilha(){
        // cout << "construtor" << endl;
        this->topo = nullptr;
        this->qtde = 0;
    }

    ~Pilha() {
        // cout << "DEStrutor" << endl;
        No* aux;
        while (this->topo != nullptr) {
            aux = this->topo;
            this->topo = this->topo->ant;
            delete aux;
        }
    }

    bool push_inserir(int elemento){
        No* novo = new No(elemento);

        if (this->topo != nullptr){
            novo->ant = this->topo;
            this->topo->prox = novo;
        } 

        this->topo = novo;
        this->qtde++;
        return true;
    }

    bool pop_remover() {
        if (this->qtde == 0) {
            return false;
        } else {
            No* aux = this->topo;

            if (this->topo->ant != nullptr) {
                this->topo = this->topo->ant;
                this->topo->prox = nullptr;
            } else {
                this->topo = nullptr;
            }

            delete aux;
            this->qtde--;

            return true;
        }
}



    int peek(){
        if (this->qtde == 0){
            cout << "Pilha vazia";
            return -999;
        } else {
            return this->topo->dado;
        }
    }

    void print() {
        cout << "[";
        No* aux = this->topo;
        while(aux != nullptr){
            cout << aux->dado << " ";
            aux = aux->ant;
        }
        cout << "]"<< endl;
    }
};