//Implement a linked list in C

#include <stdio.h>
#include <string.h>

#define LENGTH 128
#define INTIAL_SIZE 2
typedef char String[LENGTH];

typedef struct NodeTag{
    String Name;
    String bestFriend;
    struct NodeTag * next;
}Node;

Node *createNode(String name)
{
    Node * nodePtr = (Node *)malloc(sizeof(Node));

    if (nodePtr == NULL)
        return NULL;

    nodePtr->next = NULL;
    
    strcpy(nodePtr->Name, name);
    if (nodePtr->Name == NULL)
    {
        free(nodePtr);
        return NULL;
    }

    return nodePtr;
}

void addNode(Node * head, String choice){
    Node * current = head;
    while(current-> next != NULL){
        current = current -> next;
    }
    current -> next = (Node *)malloc(sizeof(Node));
    strcpy(current->next->Name, choice); //potential for bug
    current->next->next = NULL; 
}

void destroyList(Node *head)
{
    if (head == NULL)
        return;
    destroyList(head->next);
    free(head);
}

void outputList(Node *head){
    Node * current = head;
    while(current -> next != NULL){
        printf("The best ally of %s is %s\n", current->Name, current->bestFriend);
        current = current -> next;
    }
}
void getBestFriends(Node * head){
    Node *current = head;
    String name;
    while(current -> next != NULL){
       
        printf("Enter the best ally name for %s : ", current->Name);
        scanf("%s",name);
        
        strcpy(current->bestFriend, name);
        
        current = current -> next;
    }
}

int main(void){
    String choice;
    Node *head = NULL;
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    int init = 0;
    do
    {
        printf("Enter your nations name : ");
        scanf("%s",choice);
        if(init == 0) {
            strcpy(head->Name, choice);
        }
        else{
            addNode(head,choice);
        }
        ++init;

        
    } while(strcmp(choice, "exit"));

getBestFriends(head);
outputList(head);


destroyList(head);

    return 0;
}