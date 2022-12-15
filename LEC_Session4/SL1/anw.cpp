#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char type[][20]={"hunting","gathering"};

struct Node
{
    int type;
    int fur;
    int meet;
    int firewood;
    int herb;

    Node *next;
    Node *prev;
};

Node *HEAD,*TAIL,*CURR=NULL;

// NODE CREATE
Node *createNode(int type,int fur,int meet,int firewood,int herb)
{
    Node *newNode = new Node;
    newNode->type=type;
    newNode->fur=fur;
    newNode->meet=meet;
    newNode->firewood=firewood;
    newNode->herb=herb;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

// PUSH Head
void pushHead(int type,int fur,int meet,int firewood,int herb)
{
    Node *temp = createNode(type,fur,meet,firewood,herb);
    if(!HEAD)
    {
        HEAD=TAIL=temp;
    }
    else
    {
        temp->next=HEAD;
        HEAD->prev=temp;
        HEAD=temp;
    }
}

// view from tail
void viewTail()
{
    if(!TAIL)
    {
        printf("Empty List\n");
    }
    else
    {
        Node *curr=TAIL;
        while(curr)
        {
            printf("%s %d %d %d %d\n",type[curr->type],curr->fur,curr->meet,curr->firewood,curr->herb);
            curr=curr->prev;
        }
    }
}

// PUSH TAIL
void pushTail(int type,int fur,int meet,int firewood,int herb)
{
    Node *temp = createNode(type,fur,meet,firewood,herb);
    if(!TAIL)
    {
        HEAD=TAIL=temp;
    }
    else
    {
        TAIL->next=temp;
        temp->prev=TAIL;
        TAIL=temp;
    }
}

// view from head
void viewHead()
{
    if(!HEAD)
    {
        printf("Empty List\n");
    }
    else
    {
        int index=0;
        Node *curr=HEAD;
        while(curr)
        {
            printf("EXploration number %d\n",index);
            printf("You go %s and go: ",type[curr->type]);
            if(curr->type==0){
                printf("You go hunting and go: ");
                printf("%d piece(s) of fur, %d slices(s) of meat",curr->fur,curr->meet);
            }else if(curr->type==1){
                printf("%d piece(s) of firewood, %d piece(s) of herb",curr->firewood,curr->herb);
            }
            index++;
            curr=curr->next;
        }
    }
}

// POP HEAD
void popHead()
{
    if(!HEAD)
    {
        printf("Empty List\n");
    }
    else if(HEAD==TAIL)
    {
        free(HEAD);
        HEAD=TAIL=NULL;
    }
    else
    {
        Node *temp=HEAD;
        HEAD=HEAD->next;
        free(temp->prev);
        HEAD->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
}

// pop all
void popAll()
{
    if(!HEAD)
    {
        printf("Empty List\n");
    }
    else
    {
        while(HEAD)
        {
            popHead();
        }
    }
}

int main(){
    int menu;
    int fur,meet,firewood,herb=0,tipe=0;
    do{
        system("clear");
        printf("1. Explore The Woods\n");
        printf("2. Exploration Records\n");
        printf("3. Clear Exploration Records\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d",&menu);
        getchar();
        switch (menu){
        case 1:
            char explorationType[20];
            int duration=0;
            
            printf("Explore The Woods\n");
            do
            {
                printf("What type of exploration do you want to do? (hunting/gathering): ");
                scanf("%s",explorationType);
                getchar();
            } while (strcmp(explorationType,"hunting")!=0 && strcmp(explorationType,"gathering")!=0);

            do
            {
                printf("how long do you want to hunt? (1-3 hours): ");
                scanf("%d",&duration);
                getchar();

            } while (duration<1 || duration>3);
            
            printf("You explored the dark woods for %d hours\n",duration);
            printf("You obtained: \n");

            if (explorationType=="hunting")
            {
                tipe=0;
                fur=duration*rand()%11*duration;
                meet=duration*rand()%6*duration;
                firewood=herb=0;
                printf("%d piece(s) of fur, %d slices(s) of meat\n",fur,meet);
                pushTail(tipe,fur,meet,firewood,herb);
            }
            else if (explorationType=="gathering")
            {
                tipe=1;
                firewood=duration*rand()%101*duration;
                herb=duration*rand()%6*duration;
                fur=meet=0;
                printf("%d piece(s) of firewood, %d piece(s) of herb\n",firewood,herb);
                pushTail(tipe,fur,meet,firewood,herb);
            }
            
            printf("Press ENTER to continue\n");
            getchar();
            break;
        case 2:
            system("clear");
            printf("Exploration Records\n");
            viewHead();
            printf("Press ENTER to continue\n");
            getchar();
            break;
        case 3:
            system("clear");
            printf("Clear Exploration Records\n");
            popAll();
            printf("Press ENTER to continue\n");
            getchar();
            break;
        default:
            break;
        }
    }while (menu!=4);
}