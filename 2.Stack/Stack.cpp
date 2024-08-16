#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack::Stack()
{
	this->top = 0;
	this->size = 20;
	int* stos = (int*)malloc(this->size * sizeof(int));
	if (stos == NULL) {
		printf("Blad alokacji pamieci");
		exit(1);
	}
	else {
		this->dane = stos;
	}
}

Stack::~Stack()
{
	free(this->dane);
}

void Stack::push(int a)
{
	if (this->top == this->size) {
		int* CurrentSize;
		CurrentSize =
			(int*)realloc(this->dane, (this->size + INCREMENTSIZE) * sizeof(int));
		if (CurrentSize == NULL) {
			printf("Blad alokacji pamieci");
			exit(1);
		}

		this->dane = CurrentSize;
		this->size += INCREMENTSIZE;
	}
	this->dane[this->top] = a;
	this->top++;
}

int Stack::pop()
{
	if (this->top == 0) {
		printf("Stos jest pusty");
		exit(1);
	}

	return this->dane[--this->top];
}

void Stack::clear()
{
	this->top = 0;
}
