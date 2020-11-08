#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int hashFunction(int x, int M) {
	return x % M;
}
void insertion(int *hT, int x, int M) {
	int hash = hashFunction(x, M);
	while (hT[hash] != 0) {
		printf("C");
		hash = hashFunction(hash + 1, M);
	}
	hT[hash] = x;
	printf("%d\n", hash);
}
void search(int *hT, int x, int M) {
	for (int i = 0; i < M; i++) {
		if (hT[i] == x) {
			printf("%d %d\n", i, x);
			return;
		}
	}
	printf("-1\n");
}
int main() {
	int M, x, N, cnt = 0, *hT;
	char input;

	scanf("%d %d", &M, &N);
	getchar();
	hT = (int *)malloc(sizeof(int)* M);
	for (int i = 0; i < M; i++) {
		hT[i] = 0;
	}
	while (cnt <= N) {
		scanf("%c", &input);
		if (input == 'e')
			break;
		if (input == 'i') {
			cnt++;
			scanf("%d", &x);
			getchar();
			insertion(hT, x, M);
		}
		if (input == 's') {
			scanf("%d", &x);
			getchar();
			search(hT, x, M);
		}
	}

	return 0;
}