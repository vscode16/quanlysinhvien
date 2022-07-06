#include <stdio.h>

struct SinhVien{
	char id[10];
	char name[20];
	double score;
};

int main(void) {
	printf("Hello World\n");
	struct SinhVien at;
	fgets(at.id, 9, stdin);
	at.score = 2.45;
	printf("%s", at.id);
	return 0;
}