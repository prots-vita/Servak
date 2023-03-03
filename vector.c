#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

Space* creat(Space *sp){
	sp->arr = malloc(12*sizeof(int));
	sp->size = 12;
	sp->tail = -1;
}	

int queue(Space *sp, int elem){
	if (isFull(sp)){
		return 0;
	}
	sp->tail+=1;
	sp->arr[sp->tail] = elem;
	return 1;
}

int pop(Space *sp){
	if (isEmpty(sp)){
		return 0;
	}
	for (int i = 1; i<=sp->tail; i++){
		sp->arr[i-1] = sp->arr[i];
	}
	sp->tail-=1;
	return 1;
}

int isFull(Space *sp){
	if (sp->size==(sp->tail+1)){
		return 1;
	}
	return 0;
}

int isEmpty(Space *sp){
	if (sp->tail==-1){
		return 1;
	}
	return 0;
}

int peek(Space *sp){
	if (isEmpty(sp)){
		return 0;
	}
	return sp->arr[0];
}	

void print(Space *sp){
	for (int i = 0; i<=sp->tail; i++){
		printf("%d ", sp->arr[i]);
	}
	printf("\n");
}

void clear(Space *sp){
	free(sp->arr);
	sp->size = 0;
	sp->tail = -1;
}

