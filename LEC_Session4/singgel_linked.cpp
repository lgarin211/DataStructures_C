#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    Node *next;
} *HEAD = NULL, *TAIL = NULL, *CURR = NULL;

Node *create_node(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
}

void push_head(int value)
{
    Node *newNode = create_node(value);
    if (!HEAD)
    {
        HEAD = TAIL = newNode;
    }
    else
    {
        newNode->next = HEAD;
        HEAD = newNode;
    }
}

void push_tail(int value)
{
    Node *newNode = create_node(value);
    if (!HEAD)
    {
        HEAD = TAIL = newNode;
    }
    else
    {
        TAIL->next = newNode;
        TAIL = newNode;
    }
}

void viewData()
{
    if (!HEAD)
    {
        printf("Data belum tersedia");
    }
    else
    {
        CURR = HEAD;
        while (CURR)
        {
            printf("%d-", CURR->value);
            CURR = CURR->next;
        }
        printf("null\n");
    }
}
// pop_head
void pop_head()
{
    if (!HEAD)
    {
        printf("Data belum tersedia");
    }
    else if (HEAD == TAIL)
    {
        free(HEAD);
        HEAD = TAIL = NULL;
    }
    else
    {
        Node *temp = HEAD;
        HEAD = HEAD->next;
        free(temp);
        temp=NULL;
    }
}

// pop_tail
void pop_tail()
{
    if (!HEAD)
    {
        printf("Data belum tersedia");
    }
    else if (HEAD == TAIL)
    {
        free(HEAD);
        HEAD = TAIL = NULL;
    }
    else
    {
        CURR = HEAD;
        while (CURR->next != TAIL)
        {
            CURR = CURR->next;
        }
        free(TAIL);
        TAIL = CURR;
        TAIL->next = NULL;
    }
}

// pop_all
void pop_all()
{
    if (!HEAD)
    {
        printf("Data belum tersedia");
    }
    else
    {
        while (HEAD)
        {
            pop_head();
        }
    }
}

// pop_search
void pop_search(int value)
{
    if (!HEAD)
    {
        printf("Data belum tersedia");
    }
    else
    {
        CURR = HEAD;
        while (CURR)
        {
            if (CURR->value == value)
            {
                if (CURR == HEAD)
                {
                    pop_head();
                }
                else if (CURR == TAIL)
                {
                    pop_tail();
                }
                else
                {
                    Node *temp = CURR;
                    CURR = CURR->next;
                    free(temp);
                    temp = NULL;
                }
            }
            else
            {
                CURR = CURR->next;
            }
        }
    }
}


int main()
{
    push_head(2);
    push_head(3);
    push_head(3);
    push_head(100);
    push_head(1);
    push_tail(6);
    push_tail(8);
    push_tail(2);
    push_tail(84);
    
    pop_search(8);
    viewData();
    return 0;
}
