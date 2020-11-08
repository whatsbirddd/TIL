#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int hashFunction(int x, int M) {
	return x % M;
}
int hashFunction2(int x, int q) {
	return q - (x%q);
}
void insertion(int *hT, int x, int M, int q) {
	int hash = hashFunction(x, M);
	int hash2;
	while (hT[hash] != 0) {
		printf("C");
		hash2 = hashFunction2(x, q);
		hash = hashFunction(hash+hash2, M);
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
void print(int *hT, int M) {
	for (int i = 0; i < M; i++) {
		printf(" %d", hT[i]);
	}
	printf("\n");
}
int main() {
	int M,x, N,cnt = 0, *hT,q;
	char input;

	scanf("%d %d %d", &M, &N, &q);
	getchar();
	hT = (int *)malloc(sizeof(int)* M);
	for (int i = 0; i < M; i++) {
		hT[i] = 0;
	}
	while(cnt<=N){
		scanf("%c", &input);
		if (input == 'e') {
			print(hT,M);
			break;
		}
		if (input == 'i') {
			cnt++;
			scanf("%d", &x);
			getchar();
			insertion(hT,x,M,q);
		}
		if (input == 's') {
			scanf("%d", &x);
			getchar();
			search(hT,x,M);
		}
		if (input == 'p') {
			getchar();
			print(hT, M);
		}
	}
	
	return 0;
}