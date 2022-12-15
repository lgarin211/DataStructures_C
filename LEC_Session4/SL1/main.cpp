#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char EXPLORATION_TYPE[][20] = {"hunting", "gathering"};

struct Exploration{
	int type;
	int fur;
	int meat;
	int firewood;
	int herb;
};

struct Node{
	Exploration exploration;
	Node *next;
	Node *prev;
};

Node *HEAD = NULL;
Node *TAIL = NULL;
Node *CURR = NULL;

Node* create_node(Exploration exploration){
	Node *node = (Node*)malloc(sizeof(Node));
	node->exploration = exploration;
	node->next = node->prev = NULL;
	return node;
}

void push(Exploration exploration){	
	Node *node = create_node(exploration);
	if( !HEAD ){
		HEAD = TAIL = node;
	}
	else{
		TAIL->next = node;
		node->prev = TAIL;
		TAIL = node;
	}
}

void view(){
	if( !HEAD ){
		printf("There is no data!\n");
	}
	else{
		int index = 1;
		CURR = HEAD;
		while( CURR ){
			printf("Exploration number %03d:\n", index);
			printf("You go %s and got:", EXPLORATION_TYPE[CURR->exploration.type]);
			if( CURR->exploration.type == 0 ){
				printf("%d piece(s) of fur and %d slice(s) of meat\n\n", 
					CURR->exploration.fur, CURR->exploration.meat);
			}
			else{
				printf("%d piece(s) of firewood and %d pouch(s) of herbs\n\n", 
					CURR->exploration.firewood, CURR->exploration.herb);
			}
			CURR = CURR->next;
			index++;
		}
	}
}

void pop_head(){
	if( !HEAD ){
		
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

void pop_all(){
	while(HEAD){
		pop_head();
	}
}


int main(){
	
	srand(time(NULL));
	
	int menu;
	Exploration exploration;
	
	do{
		system("cls");
		printf("Exploration Game\n");
		printf("===========================\n");
		printf("1) Explore the Woods!\n");
		printf("2) Exploration Records\n");
		printf("3) Clear Exploration Record\n");
		printf("4) Exit\n");
		
		do{
			printf("Choice: ");
			scanf("%d", &menu);
			fflush(stdin);
		}while( menu<1 || menu>4 );
		
		switch(menu){
			
			case 1:
				system("cls");
				printf("Explore the Woods!\n\n");
				
				char type[20];
				int duration;
				
				do{
					printf("Choose exploration type [hunting|gathering]: ");
					scanf("%s", &type);
					fflush(stdin);
				}while( strcmp(type, "hunting") != 0 && strcmp(type, "gathering") != 0 );
				
				do{
					printf("How long do you want to do %s? [1-3 hours]: ", type);
					scanf("%d", &duration);
					fflush(stdin);
				}while( duration< 1 || duration>3 );
				
				printf("you explored the darkside of the woods!\n");
				printf("You obtained:\n");
				
				if( strcmp(type, "hunting") == 0) {
					exploration.type = 0;
					exploration.fur = rand()%11 * duration;
					exploration.meat = rand()%6 * duration;
					exploration.firewood = exploration.herb = 0;
					printf("%2d piece(s) of fur\n", exploration.fur);
					printf("%2d slice(s) of meat\n", exploration.meat);
				}
				else if( strcmp(type, "gathering") == 0 ){
					exploration.type = 1;
					exploration.firewood = rand()%101 * duration;
					exploration.herb = rand()%6 * duration;
					exploration.fur = exploration.meat = 0;
					printf("%2d piece(s) of firewood\n", exploration.firewood);
					printf("%2d pouch(s) of herb\n", exploration.herb);
				}
				
				push(exploration);
				
				printf("\n\nPress ENTER to continue");
				getchar();
				break;
				
			case 2:
				system("cls");
				printf("Exploration Records\n\n");
				
				view();
				
				printf("Press ENTER to continue");
				getchar();
				break;
				
			case 3:
				system("cls");
				printf("Clear Exploration Record\n\n");
				
				pop_all();
				printf("Exploration record has been cleared!\n");
				
				printf("Press ENTER to continue");
				getchar();
				break;			
		}
		
	}while( menu != 4 );
	
	return 0;
}
