#include <iostream>

using namespace std;

struct lista{
    int number;
    struct lista* prox;
};

void inicializaLista(lista*&l){
    l=NULL;
}

void inserirFim(lista*&l, int dado){
    lista* novo = new lista;
    novo->number = dado;
    novo->prox = NULL;
    if(l == NULL)
        l = novo;
    else{
        lista* auxiliar = l;
        while(auxiliar->prox != NULL){
            auxiliar = auxiliar->prox;
        }
        auxiliar->prox = novo;
    }
}

void imprimir(lista* l){
    while(l != NULL){
        cout << l->number << endl;
        l = l->prox;
    }
}

int tamanho(lista *l){
    int contador = 0;
    while(l != NULL){
        contador++;
        l = l->prox;
    }
    return contador;
}


bool inserirPos(lista*&l, int dado, int pos){
    int tam = tamanho(l);
    if (pos > tam+1 ){
        return false;
    }else{
        lista* novo = new lista;
        novo->number = dado;
        novo->prox = NULL;
        if( pos == 1){
            novo->prox = l;
            l = novo;
        }else if(pos == tam+1 ){
            lista* perc = l;
            while(perc->prox != NULL){
                perc = perc->prox;
            }
            perc->prox = novo;
        }else{
            lista* perc = l;
            int cont = 1;
            while(cont != pos-1 ){
                perc = perc->prox;
                cont++;
            }
            novo->prox = perc->prox;
            perc -> prox = novo;
        }
        return true;
    }
}

void intercalar(lista*&l1, lista*&l2){
    int tamL1 = tamanho(l1);
    int tamL2 = tamanho(l2);

    if (tamL1 == tamL2){
        int tam3 = tamL1 + tamL2;
        for (int i = 1; i <= tam3 ; i++){
            if(i%2 == 0){
                inserirPos(l1,l2->number,i);
                l2 = l2->prox;
            }
        }
        imprimir(l1);
    }else{
        cout << "as listas nao possuem o mesmo tamanho" << endl;
    }
}




int main(){

    lista* l1;
    inicializaLista(l1);
    lista* l2;
    inicializaLista(l2);

    cout << "atividade 1" << endl;

    int elemento, n, opcao = 0;
    while(opcao != 3){
        cout <<"\n"<<  "o que voce deseja:" << "\n" << "1-adicionar elementos" << "\n"
        << "2-mostrar elementos" << "\n" << "3-sair" << endl;
        cin >> opcao;
        switch (opcao){
            case 1:
                cout << "\n" << "insira o elemento a ser inserido:";
                cin >> elemento;
                cout << "escolha uma lista para add o elemento:" << "\n" << "1-primeira lista" << "\n" << "2-segunda lista" <<endl;
                cin >> n;
                if(n == 1)
                    inserirFim(l1,elemento);
                else if(n == 2)
                    inserirFim(l2,elemento);
                else{
                    cout << "voce nao escolheu a lista!" << endl;
                }
                break;
            case 2:
                cout << "\n" << "voce deseja:"<< "\n" << "1-mostra a primeira lista" << "\n" << "2-mostrar a segunda lista"
                << "\n" << "3-mostrar as listas de formar intercalada(eles devem ter a mesma quantidade de elementos)" << endl;
                cin >> n;
                if (n == 1){
                    cout << "lista 1"<< endl;
                    imprimir(l1);
                }
                else if(n == 2){
                    cout << "lista 2" << endl;
                    imprimir(l2);
                }
                else if(n == 3){
                    cout << "\n" << "intercalacao" << endl;
                    intercalar(l1,l2);
                }
                break;
            case 3:
                cout << "voce saiu do programa!" << endl;
                break;
            default:
                cout << "valor invalido" << endl;
        }
    }

    return 0;
}
