#include <stdio.h>
#include <stdlib.h>
#define SIZE 1001

size_t my_strlen(const char* str);
char* my_strcat(const char* source1, const char* source2);
void ClearBuffer();

int main()
{
	char source1[SIZE], source2[SIZE];
	printf("Podaj pierwszy napis: ");
	scanf("%1000[^\n]", source1);
	ClearBuffer();
	printf("Podaj drugi napis: ");
	scanf("%1000[^\n]", source2);
	ClearBuffer();
	char* result = my_strcat(source1, source2);
	if (result != NULL) {
		printf("%s\n", result);
		free(result);
	}
	else {
		printf("Błąd alokacji pamięci.\n");
	}

	return 0;
}

size_t my_strlen(const char* str)
{

	size_t dlugosc = 0;
	while (*str) {
		dlugosc++;
		str++;
	}
	return dlugosc;
}

char* my_strcat(const char* source1, const char* source2)
{

	size_t lensrc1 = my_strlen(source1);
	size_t lensrc2 = my_strlen(source2);

	char* res = malloc(lensrc1 + lensrc2 + 1);
	if (res == NULL) {
		return NULL;
	}
	char* konkat = res;

	while (*source1 != '\0') {
		*res++ = *source1++;
	}
	while (*source2 != '\0') {
		*res++ = *source2++;
	}
	*res = '\0';
	return konkat;
}

void ClearBuffer()
{

	while (getchar() != '\n')
		;
}
