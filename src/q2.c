#include <stdio.h>
#include <stdlib.h>
#define BATCH 10
#define FREE '_'
#define STOP '@'
#define REMOVE 8
#include "functions.c"
int main () {
	struct space mem;
	initialize(&mem);
	struct node *head = NULL;
	char c = '\0';
	while (c != EOF) {
		int t = 0;
		char buf[BATCH];
		while ((c = getchar()) != ' ' && c != '\n' && c != EOF && t < BATCH - 1) {
			*(buf + t) = c;
			t++;
		}
		int p = allocator(&mem, t + 1, &head);
		if (p >= 0) {
			for (int i = 0; i < t; i++) *((&mem)->memory + p + i) = *(buf + i);
			*((&mem)->memory + p + t) = STOP;
		}
		printf("new word saved: memory=%s(%d)\n", (&mem)->memory, (&mem)->len);
	}
	struct node *cur = head;
	while (head) {
		cur = head;
		head = head->next;
		free(cur);
	}
	clear(&mem);
}


