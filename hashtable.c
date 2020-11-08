#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

/*
	Hashtable : size M, dynamically allocating array
	key : natural number without duplication
	hash functon = x % M
	hash collision : insert at the beginning
*/

typedef struct list {
	int value;
	struct list *pre, *next;
}list;

int hashFunction(int x, int M) {
	return x % M;
}
void insertion(int x, list *hT, int M) {
	int hash = hashFunction(x, M);
	list *newhash = (list *)malloc(sizeof(list));
	newhash->value = x;
	newhash->next = NULL;
	newhash->pre = hT + hash;

	if ((hT + hash)->next != NULL) {//ºÐ¸®¿¬¼â¹ý(¸Ç¾Õ»ðÀÔ)
		(hT + hash)->next->pre = newhash;
		newhash->next = (hT + hash)->next;
	}
	(hT + hash)->next = newhash;
}
list* search(list *hT, int x, int M) {
	int hash = hashFunction(x, M);
	int rank = 0, f = 0;
	list *ls = hT + hash;
	while (ls->next != NULL) {
		ls = ls->next;
		rank++;
		if (ls->value == x) {
			f = 1;
			break;
		}
	}
	if (f == 1) {
		printf("%d\n", rank);
	}
	else {
		printf("0\n");
		ls = NULL;
	}
	return ls;
}
void deletion(list *hT, int x, int M) {
	list *del = search(hT, x, M);
	if (del != NULL) {
		if (del->next != NULL) {
			del->next->pre = del->pre;
		}
		del->pre->next = del->next;
	}
}
void print(list *hT, int M) {
	list *ls = hT;
	for (int i = 0; i < M; i++) {
		ls = hT + i;
		while (ls->next != NULL) {
			ls = ls->next;
			printf(" %d", ls->value);
		}
	}
	printf("\n");
}
int main() {
	int M, x;
	list *hT;
	char input;

	scanf("%d", &M);
	getchar();
	hT = (list *)malloc(sizeof(list)* M);
	for (int i = 0; i < M; i++) {
		(hT + i)->value = i;
		(hT + i)->next = NULL;
	}

	while (1) {
		scanf("%c", &input);
		if (input == 'e')
			break;
		if (input == 'i') {
			scanf("%d", &x);
			getchar();
			insertion(x, hT, M);
		}
		if (input == 's') {
			scanf("%d", &x);
			getchar();
			search(hT, x, M);
		}
		if (input == 'p') {
			getchar();
			print(hT, M);
		}
		if (input == 'd') {
			scanf("%d", &x);
			getchar();
			deletion(hT, x, M);
		}
	}

	return 0;
}