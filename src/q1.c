#include <stdio.h>
#include <stdlib.h>
#define BATCH 10
#define FREE '_'
#define STOP '@'
#define REMOVE 8
#include "functions.c"
#include "functions.h"

int main () {
	struct space mem;
	initialize(&mem);
	clear(&mem);
}


