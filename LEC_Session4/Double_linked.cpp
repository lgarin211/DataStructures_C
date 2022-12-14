#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    Node *next;
    Node *prev;
};

// creat a new node
Node *createNode(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next=newNode->prev=NULL;
    return newNode;
}

// HEAD and tail
Node *HEAD = NULL;
Node *tail = NULL;

// push HEAD
void pushHEAD(int value) {
    Node *newNode = createNode(value);
    if (HEAD == NULL) {
        HEAD = tail = newNode;
    } else {
        newNode->next = HEAD;
        HEAD=HEAD->prev = newNode;
    }
}

// push tail
void pushTail(int value) {
    Node *newNode = createNode(value);
    if (HEAD == NULL) {
        HEAD = tail = newNode;
    } else {
        newNode->prev = tail;
        tail=tail->next = newNode;
    }
}

// view form tail
void viewTail() {
    Node *temp = tail;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
} 

// view form HEAD
void viewHEAD() {
    Node *temp = HEAD;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// pop HEAD
void popHEAD() {
    if (HEAD == NULL) {
        printf("List is empty");
    } else {
        Node *temp = HEAD;
        HEAD = HEAD->next;
        HEAD->prev = NULL;
        free(temp);
    }
}

// pop tail
void popTail() {
    if (HEAD == NULL) {
        printf("List is empty");
    } else {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

// pop all
void popAll() {
    while (HEAD != NULL) {
        popHEAD();
    }
}
// pop sort
void popSort() {
    Node *temp = HEAD;
    while (temp != NULL) {
        Node *temp2 = temp->next;
        while (temp2 != NULL) {
            if (temp->value > temp2->value) {
                int tempValue = temp->value;
                temp->value = temp2->value;
                temp2->value = tempValue;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
