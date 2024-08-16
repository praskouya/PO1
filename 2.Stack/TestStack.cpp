#include "Stack.h"
#include <stdio.h>

int main()
{
	Stack s1;
	Stack s2;

	for (int i = 1; i < 50; i = i + 2) {
		s1.push(i);
	}
	s2.push(5);
	s2.push(6);
	for (int i = 1; i < 50; i = i + 2) {
		int PoppedElement;
		PoppedElement = s1.pop();
		printf("%d  ", PoppedElement);
	}
	s1.push(1);
	s1.push(2);
	s1.push(3);
	printf("\n%d %d\n", s1.pop(), s2.pop());
	printf("%d\n", s1.pop());
	return 0;
}
