#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* new_stack() {
    return NULL;
}

int is_empty(Stack *s) {
    if(!s)
        return 1;
    else
        return 0;
}

int is_unitary(Stack *s) {
    if(s->next == NULL)
        return 1;
    else
        return 0;
}

void push(Stack **pstack, int num) {
    Stack *aux;

    // Aloca��o de novo elemento
    aux = (Stack*) malloc(sizeof(Stack));

    if(!aux) {
        printf("\nErro de alocacao\n");
        return;
    }

    aux->info = num;
    aux->next = *pstack;
    *pstack = aux;
}

int pop(Stack **pstack) {
    Stack *aux;

    if(is_empty(*pstack))
        printf("\nPilha vazia\n");

    else {
        int num = (*pstack)->info;

        aux = *pstack;
        *pstack = aux->next;
        free(aux);

        return num;
    }
}

void clear(Stack **pstack) {
    Stack *aux, *aux2;

    aux = *pstack;

    while(aux) {
        aux2 = aux;
        aux = aux->next;

        free(aux2);
    }
}
