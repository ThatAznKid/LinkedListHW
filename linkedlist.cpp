#include <stdio.h>
#include <stdlib.h>

struct node {
	int cargo; 
	struct node *next;
};

void print_list(struct node* N) {
	printf("LIST: ["); 
	while (N) {
		printf("%d,", N->cargo); 
		N = N->next;
		//printf("%d",N->next);
	}
	printf("]\n");
}

struct node* insert_front(int data, struct node* p) {
	struct node* head = (struct node*)malloc(sizeof(struct node)); 
	head->cargo = data; 
	head->next = p; 
	return head; 
}

struct node* free_list(struct node* list) {
	struct node* temp; 
	while (list) {
		temp = list->next; 
		free(list); 
		list = temp;
	}
	return list;
}

int main() {
	struct node *b, *c; 
	b = (struct node*)malloc(sizeof(struct node)); 
	c = (struct node*)malloc(sizeof(struct node));  
	b->next = c; 
	c->next = NULL;
	b->cargo = 20; 
	c->cargo = 30; 
	struct node* a = insert_front(10, b); 
	print_list(a);
	free_list(a);

	return 0;
}