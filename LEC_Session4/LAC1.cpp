#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	Node *next;
}*HEAD = NULL, *TAIL = NULL;

Node *CURR = NULL;

Node* create_node(int value){
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}

void push_head(int value){
	Node *newnode = create_node(value);
	if( !HEAD ){
		HEAD = TAIL = newnode;
	}else{
		newnode->next = HEAD;
		HEAD = newnode;		
	}
}

void push_tail(int value){
	Node *newnode = create_node(value);
	if( !HEAD ){
		HEAD = TAIL = newnode;
	}
	else{
		TAIL->next = newnode;
		TAIL = newnode;
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
		CURR = HEAD;
		HEAD = HEAD->next;
		free(CURR);
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
		CURR = HEAD;
		while( CURR->next != TAIL ){
			CURR = CURR->next;
		}
		free(TAIL);
		TAIL = CURR;
		TAIL->next = NULL;
	}
}

void pop_all(){
	while(HEAD){
		pop_head();
	}
}

void view(){
	if( !HEAD ){
		printf("There is no data!\n");
	}
	else{
		CURR = HEAD;
		while( CURR ){
			printf("%d - ", CURR->value);
			CURR = CURR->next;
		}
		printf("null");
	}
}

void pop_search(int value){
	if( !HEAD ){
		printf("There is no data!\n");
	}
	else if( HEAD->value == value ){
		pop_head();
	}
	else if( TAIL->value == value ){
		pop_tail();
	}
	else{
		CURR = HEAD;
		while( CURR->next ){
			if( CURR->next->value == value ){
				Node *todelete = CURR->next;
				CURR->next = CURR->next->next;
				free(todelete);
				return;
			}
			CURR = CURR->next;
		}
		printf("%d not found!\n", value);
	}
}

int main(){
	
	push_head(15);
	push_tail(22);
	push_tail(31);
	push_head(55);
	push_tail(21);
	
	pop_search(30);
//	pop_head();
//	pop_head();
//	pop_tail();
//	pop_tail();
//	pop_tail();

//	pop_all();
	
	//55 15 22 31 21
	view();
	
	
	
	return 0;
}
