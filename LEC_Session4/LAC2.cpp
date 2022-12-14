#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	Node *next;
	Node *prev;
};

Node *HEAD = NULL;
Node *TAIL = NULL;
Node *CURR = NULL;

Node* create_node(int value){
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->value = value;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void push_head(int value){
	Node *newnode = create_node(value);
	if( !HEAD ){
		HEAD = TAIL = newnode;
	}
	else{
		newnode->next = HEAD;
		HEAD->prev = newnode;
		HEAD = newnode;
	}
}

void push_tail(int value){
	Node *newnode = create_node(value);
	if( !HEAD ){
		HEAD = TAIL = newnode;
	}
	else{
		newnode->prev = TAIL;
		TAIL->next = newnode;
		TAIL = newnode;
	}
}

void view_from_tail(){
	if( !HEAD ){
		printf("There is no data!\n");
	}
	else{
		CURR = TAIL;
		while( CURR ){
			printf("%d - ", CURR->value);
			CURR = CURR->prev;
		}
		printf("null\n");
	}
}

void pop_head(){
	if( !HEAD ){
		printf("There is no data!\n");
	}	
	else if( HEAD == TAIL ){
		free(HEAD);
		HEAD = TAIL = NULL;
	}
	else{
		HEAD = HEAD->next;
		free(HEAD->prev);
		HEAD->prev = NULL;
	}
}

void pop_tail(){
	if( !HEAD ){
		printf("There is no data!\n");
	}
	else if( HEAD == TAIL ){
		free(HEAD);
		HEAD = TAIL = NULL;
	}
	else{
		TAIL = TAIL->prev;
		free(TAIL->next);
		TAIL->next = NULL;
	}
}

void pop_all(){
	while(HEAD){
		pop_head();
	}
}

int main(){
	
	push_head(23);
	push_tail(10);
	push_tail(15);
	push_head(33);
	push_tail(50);
	
	pop_head();
	pop_tail();
	
//	33 23 10 15 50
	view_from_tail();
	
	
	return 0;
}
