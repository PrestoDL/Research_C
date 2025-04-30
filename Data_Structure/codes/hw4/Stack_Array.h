// 2020116706

#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef int Boolean;

typedef struct {
    Element* stack;
    int size;
    int top;
} Stack;

Stack* CreateStack(int size) {
    Stack* temp = (Stack*)malloc(sizeof(Stack));
    if (temp == NULL) {
        return NULL;
    }

    temp->stack = (Element*)malloc(size * sizeof(Element));
    if (temp->stack == NULL) {
        free(temp);
        return NULL;
    }

    temp->size = size;
    temp->top = -1;

    return temp;
}

void Push(Stack* temp, Element item) {
    if (temp->top == temp->size - 1) {
        return;
    }

    temp->stack[++temp->top] = item;
}

Element Pop(Stack* temp) {
    if (temp->top == -1) {
        return;
    }

    return temp->stack[temp->top--];
}

Element Top(Stack* temp) {
    if (temp->top == -1) {
        return;
    }

    return temp->stack[temp->top];
}

void DestroyStack(Stack* temp) {
    if (temp->stack != NULL) {
        free(temp->stack);
    }
    free(temp);
}

Boolean IsFullStack(Stack* temp) {
    if (temp->size == temp->top - 1) {
        return 1;
    }

    return 0;
}

Boolean IsEmptyStack(Stack* temp) {
    if (temp->top == -1) {
        return 1;
    }

    return 0;
}

int CountStackItem(Stack* temp) { return temp->top + 1; }

void ClearStack(Stack* temp) { temp->top = -1; }