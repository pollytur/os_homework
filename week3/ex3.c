#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void print_list(struct node *list) {
    struct node *help = malloc(sizeof(struct node));
    help->value=list->value;
    help->next=list->next;
    while (help->next != NULL) {
        printf("%d ", help->value);
        help=help->next;
    }
    printf("%d\n", help->value);
}

void insert_node(struct node *after_this, struct node *to_insert) {
    if(after_this->next!=NULL){
        to_insert->next=after_this->next;
        after_this->next=to_insert;
    }
    else{
        after_this->next=to_insert;
    }
}

void delete_node(struct node *list, struct node *to_delete) {
    struct node *help = malloc(sizeof(struct node));
    help->value=list->value;
    help->next=list->next;
    struct node *prev=malloc(sizeof(struct node));;
    while (help->next != to_delete->next) {
            prev=help;
            help = help->next; }

    if ((help->next == to_delete->next)&&(help->value == to_delete->value)){
        if(help->next!=NULL){
            prev->next=help->next;
        } else{
            prev->next=NULL;
        }
        help->next=NULL;
    }
}

int main() {

    struct node *n1=malloc(sizeof(struct node));
    struct node *n2=malloc(sizeof(struct node));
    struct node *n3=malloc(sizeof(struct node));
    struct node *n4=malloc(sizeof(struct node));
    struct node *n5=malloc(sizeof(struct node));
    n1->value=1;
    n2->value=2;
    n3->value=3;
    n4->value=4;
    n5->value=5;
    n1->next=NULL;
    n2->next=NULL;
    n3->next=NULL;
    n4->next=NULL;
    n5->next=NULL;

    insert_node(n1, n2);
    print_list(n1);
    insert_node(n2,n3);
    print_list(n1);
    insert_node(n2,n4);
    print_list(n1);
    delete_node(n1, n4);
    print_list(n1);
    delete_node(n1, n5);
    print_list(n1);
    delete_node(n1, n3);
    print_list(n1);
    insert_node(n2, n5);
    print_list(n1);

    return 0;
}