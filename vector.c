#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Space{
	int *arr;
	int size;
	int tail;
}Space;

int queue(Space *, int); //ADD AN ELEMENT
int pop(Space *); //DELETE AN ELEMENT
int isEmpty(Space *); //EMPTY - 1, NOT EMPTY - 0
int isFull(Space *); //FULL - 1, NOT FULL - 0
int peek(Space *); //GET AN ELEMENT FROM THE BEGIN

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

int main(){
	srand(time(NULL));
	Space space;
	space.arr = malloc(12*sizeof(int));
	space.size = 12;
	space.tail = -1;
	for (int i = 1; i<43; i++){
		switch(rand()%2){
			case 2:
				if (queue(&space, i)){
					printf("QUEUE\n");
					print(&space);
				}
			case 0:
				if (pop(&space)){
					printf("POP\n");
					print(&space);
				}
			case 1:
				if (!isEmpty(&space)){
					printf("PEEK\n");
					printf("%d\n", peek(&space));
				}
		}
	}

}
