#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
	int element;
	struct listNode * link;
}listNode;

listNode * createNode(int element) {
	listNode* node = malloc(sizeof(listNode));
	node->element = element;
	node->link = NULL;
	return node;
}
void appendNode(listNode ** head, listNode * newnode) {
	listNode * ptr = *head;
	if (*head == NULL) {
		*head = newnode;
	}
	else {
		while (ptr->link != NULL) {
			ptr = ptr->link;
		}
		ptr->link = newnode;
	}
}
void deleteNode(listNode **head, int element) {
	listNode * ptr = *head;
	listNode * prev = NULL;
	while (ptr != NULL && ptr->element != element) {
		prev = ptr;
		ptr = ptr->link;
	}
	if (ptr != NULL) {
		prev->link = ptr->link;
		free(ptr);
	}
}
void printNode(listNode * head) {
	listNode * ptr = head;
	while (ptr != NULL) {
		printf("%d ", ptr->element);
		ptr = ptr->link;
	}printf("\n");
}
int main() {
	listNode * head = NULL;
	appendNode(&head, createNode(1));
	appendNode(&head, createNode(2));
	appendNode(&head, createNode(4));
	printNode(head);
	deleteNode(&head, 2);
	printNode(head);
}