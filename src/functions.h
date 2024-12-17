#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*
 * Space in memory where words are stored
 */
struct space {
	char *memory; // string of all the words in memory
	int len;  // length of the space of memory
};


/*
 * Space in memory where words are stored
 */
struct node {
	int p; // integer to represent the location of the word
	struct node *next; // pointer to next node in linked list
};

void initialize(struct space *mem);
void clear(struct space *mem);

#endif
