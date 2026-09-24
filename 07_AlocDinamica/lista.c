#include <stdio.h>
#include <stdlib.h>

typedef struct TNodo {
  int dado;
  struct TNodo* prox;
} Nodo;

typedef struct {
  Nodo* head;
  Nodo* tail;
  int size;  // é conveniente armazenar o tamanho!
} Lista;

void inicializaLista(Lista* lista);
void insereFinal(Lista* lista, int valor);
void exibeLista(Lista* lista);
void limpaLista(Lista* lista);

void inicializaLista(Lista* lista) {
  lista->head = NULL;
  lista->tail = NULL;
  lista->size = 0;
}

void insereFinal(Lista* lista, int valor) {
  Nodo* novo = malloc(sizeof(Nodo));
  novo->dado = valor;
  // Se a lista não existe...
  if (lista->head == NULL) {
    lista->head = novo;
  } else {
    lista->tail->prox = novo;
  }
  lista->tail = novo;
  lista->size++;
}

void exibeLista(Lista* lista) {
  Nodo* ptr = lista->head;
  // Enquanto não chegar no final da lista...
  while (ptr != NULL) {
    printf("%d ", ptr->dado);
    ptr = ptr->prox;
  }
  printf("\n");
}

void limpaLista(Lista* lista) {
  Nodo* ptr = lista->head;
  Nodo* aux;
  while (ptr != NULL) {
    aux = ptr->prox;
    free(ptr);
    ptr = aux;
  }
}

int main() {
  Lista lista;
  inicializaLista(&lista);
  for (int i = 0; i < 1000; i++) {
    insereFinal(&lista, i);
  }
  exibeLista(&lista);
  limpaLista(&lista);
}