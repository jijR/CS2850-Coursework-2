#include <stdio.h>
#include <stdlib.h>
#define BATCH 10
#define FREE '_'
#define STOP '@'
#define REMOVE 8

void initialize(struct space *mem);

/*
 * Space in memory where words are stored
 */
struct space {
	char *memory; // string of all the words in memory
	int len;  // length of the space of memory
};

/*
 * Node of a linked list to represent the location of each individual word in the memory space
 */
struct node {
	int p; // integer to represent the location of the word
	struct node *next; // pointer to next node in linked list
};

void initialize(struct space *mem) {

	// allocate memory space BATCH + 1 bytes
	mem->memory = malloc(BATCH + 1);
	if (mem->memory == NULL) {
		printf("ERROR 1: Memory Allocation Failure.\n");
		exit();
	}

	mem->len = BATCH;

	// Initialise first entries to FREE (_)
	for (int i = 0; i < BATCH; i++) {
		mem->memory[i] = FREE;
	}
	mem->memory[BATCH] = '\0';

	for (int i = 0; i <= BATCH; i++) {
		printf("%c|", mem->memory[i]);
	}
}

void clear(struct space *mem) {
	free(mem);
}
