#include <iostream>
using namespace std;
struct t_no {
  int id;
  struct t_no *prox;
  struct t_no *anterior;
} typedef no;

void imprimir_frente(no *cabeca) {
  no *aux = cabeca;
  cout << "lista frente............." << endl;
  while (aux != NULL) {
    cout << aux->id << endl;
    aux = aux->prox;
  }
}

void imprimir_atras(no *cabeca) {
  no *aux = cabeca;
  cout << "lista atras:.............." << endl;
  ;
  while (aux != NULL) {
    cout << aux->id << endl;
    aux = aux->anterior;
  }
}
void buscar_frente(no *cabeca, int num) {
  no *aux = cabeca;
  while (aux != NULL) {
    if (num == aux->id) {
      cout << "o item " << aux->id << " esta na lista ";
      return;
    }
    aux = aux->prox;
  }
  cout << "o item nao esta na lista";
}
void buscar_atras(no *cabeca, int num) {
  no *aux = cabeca;
  while (aux != NULL) {
    if (num == aux->id) {
      cout << "o item " << aux->id << " esta na lista ";
      return;
    }
    aux = aux->anterior;
  }
  cout << "o item nao esta na lista";
}

int inserir_frente(no **cabeca, int id) {
  no *aux = (no *)malloc(sizeof(no));
  no *temp = NULL;

  aux->id = id;
  aux->prox = NULL;
  aux->anterior = NULL;
  if (*cabeca == NULL) {
    *cabeca = aux;
  } else {
    temp = *cabeca;
    while (temp->prox != NULL) {
      temp = temp->prox;
    }
    temp->prox = aux;
  }
  return 1;
}
int inserir_atras(no **cabeca, int id) {
  no *aux = (no *)malloc(sizeof(no));
  no *temp = NULL;
  aux->id = id;
  aux->prox = NULL;
  aux->anterior = NULL;
  if (*cabeca == NULL) {
    *cabeca = aux;
  } else {
    temp = *cabeca;
    while (temp->anterior != NULL) {
      temp = temp->anterior;
    }
    temp->anterior = aux;
  }
  return 1;
}

int excluir_frente(no **cabeca, int id) {
  no *temp = *cabeca;
  no *ant = NULL;
  while (temp != NULL) {
    if (temp->id == id) {
      if (ant != NULL) {
        ant->prox = temp->prox;
      } else {
        *cabeca = temp->prox;
        if (temp != NULL) {
          temp->prox->anterior = NULL;
        }
      }
      free(temp);
      return 1;
    }
    else{
      ant = temp;
      temp = temp->prox;
    }
  }
  return 0;
}

int excluir_atras(no **cabeca, int id) {
  no *temp = *cabeca;
  no *proximo = NULL;
  while (temp != NULL) {
    if (temp->id == id) {
      if (proximo != NULL) {
        proximo->anterior = temp->anterior;
      } else {
        *cabeca = temp->anterior;
      }
      free(temp);
      return 1;
    }
    else{
      proximo = temp;
      temp = temp->anterior;
    }
  }
  return 0;
}

int main() {
  no *lista = NULL;
  inserir_frente(&lista, 10);
  inserir_atras(&lista, 3);
  inserir_frente(&lista, 20);
  imprimir_frente(lista);
  imprimir_atras(lista);
  buscar_atras(lista, 3);
  return 1;
}