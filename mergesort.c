#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}node;
typedef struct tmp {
	node *left;
	node *right;
}tmp;


tmp partition(node *L, int k) {
	node *p;
	tmp result;
	node *left, *right;

	p = L;
	left = L;
	for (int i = 0; i < k - 1; i++) {
		p = p->next;
	}
	right = p->next;
	p->next = NULL; //left right를 나누어주기 위함

	result.left = left;
	result.right = right;

	return result;
}
node* merge(node *left, node *right) {
	node *result = NULL;

	if (left == NULL) {
		return right;
	}
	else if (right == NULL) {
		return left;
	}

	if (left->data < right->data) {
		result = left;
		result->next = merge(left->next, right);
	}
	else {
		result = right;
		result->next = merge(left, right->next);
	}
	return result;
}
void mergeSort(node **ls, int n) {//n개의 node 합병정렬
	node *left = NULL, *right = NULL;
	tmp temp;
	node *p;
	if (n > 1 && *ls != NULL) {
		temp = partition(*ls, n / 2);
		left = temp.left;
		right = temp.right;

		mergeSort(&left, n / 2);
		mergeSort(&right, (int)(n / 2.0 + 0.5));

		*ls = merge(left, right);
	}
}
int main() {
	node *head, *prenode, *newnode;
	int n, data;
	scanf("%d", &n);

	head = (node *)malloc(sizeof(node));
	head->next = NULL;

	prenode = head;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		newnode = (node*)malloc(sizeof(node));
		newnode->data = data;
		newnode->next = NULL;
		prenode->next = newnode;
		prenode = newnode;
	}
	mergeSort(&head->next, n);
	prenode = head->next;
	for (int i = 0; i < n; i++) {
		printf(" %d", prenode->data);
		prenode = prenode->next;
	}

	return 0;
}