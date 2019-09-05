#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
    int data;
    struct LinkedList *next;
} LinkedList;

typedef struct LinkedList* Node;

Node create_node(int a){
    Node res = malloc(sizeof(LinkedList));
    res->data = a;
    res->next = NULL;
    return res;
}

void print_list(Node head){
    Node p = head;
    while (p->next != NULL){
        printf("%d->", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
}

void insert_node(Node *head, int val){
    if (*head == NULL){
        *head = create_node(val);
    } else {
        Node p = *head;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = create_node(val);
    }
}

void delete_node(Node *head, int val){
    if (*head == NULL) return;

    if ((*head)->data == val) {
        Node p = *head;
        *head = (*head)->next;
        free(p);
    } else {
        Node p = *head;
        while (p != NULL && p->next != NULL) {
            if (p->next->data == val) {
                Node t = p->next;
                p->next = p->next->next;
                free(t);
                return;
            }
            p = p->next;
        }
    }
}

int main(){
    Node head = NULL; // empty node
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 65);
    insert_node(&head, 7);
    delete_node(&head, 4);
    print_list(head);
}