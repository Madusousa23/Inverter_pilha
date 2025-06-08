#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, int valor) {
    if (!estaCheia(p)) {
        p->itens[++p->topo] = valor;
    }
}

int pop(Pilha *p) {
    if (!estaVazia(p)) {
        return p->itens[p->topo--];
    }
    return -1; // erro
}

void inverterPilha(Pilha *origem, Pilha *destino) {
    while (!estaVazia(origem)) {
        int valor = pop(origem);
        push(destino, valor);
    }
}

void imprimirPilha(Pilha *p) {
	int i;
    for (i = p->topo; i >= 0; i--) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main() {
    Pilha p1, p2;
    inicializar(&p1);
    inicializar(&p2);

    push(&p1, 1);
    push(&p1, 2);
    push(&p1, 3);
    push(&p1, 4);

    printf("Pilha original: ");
    imprimirPilha(&p1);

    inverterPilha(&p1, &p2);

    printf("Pilha invertida: ");
    imprimirPilha(&p2);

    return 0;
}


