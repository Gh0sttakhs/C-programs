#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
    int value;
    struct listnode *next;
} *List;


// CHECK IF LIST IS EMPTY,
int is_empty(List list)
{
    return list == NULL;
}

// INSERT A NEW NODE
void insert(List *list, int value)
{
    List current_head = *list;
    List new_head = malloc(sizeof(struct listnode));
    new_head->value = value;
    new_head->next = current_head;
    *list = new_head;
}

// PRINT NODES OF THE LIST
void print(List list)
{
    printf("list: ");
    while (list)
    {
        printf(" -> %d", list->value);
        list = list->next;
    }
    printf(" -> NULL\n");
}

//CHECK THE LENGTH OF THE LIST(1ST WAY)
int length(List list){
    int counter = 0;
    while (list)
    {
        counter++;
        list = list->next;
    }
    return counter;
    
}
//2ND
int length(List list){
    if (!list){
        return 0;
    }
    return 1+length(list->next);
}

//FIND A VALUE IN A LIST
List find(List list,int value){
    while(list && list->value != value){
        list = list->next;
    }
    return list;
}

//DELETE A NODE FROM A LIST
void delete(List *list,int value) {
    List temp;
    while (*list && (*list)->value != value)
    {
        list = &((*list)->next);
    }
    if (*list){
        temp = *list;
        *list = temp->next;
        free(temp);
    }
    
}


// MAIN FOR EMPTY FUNCTION
int main()
{
    struct listnode node = {42, NULL};
    List list1 = &node;
    List list2 = NULL;
    printf("Is empty: %d\n", if_empty(list1));
    printf("Is empty: %d\n", if_empty(list2));
    return 0;
}

// MAIN FOR INSERT, PRINT AND FIND FUNCTIONS
int main()
{
    List list = NULL;
    insert(&list, 42);
    insert(&list, 43);
    insert(&list, 44);
    
    print(list);

    printf("Found 43: %x\n",find(&list,43));
    printf("Found 34: %x\n",find(&list,34));

    return 0;
}