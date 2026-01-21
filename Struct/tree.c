#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int value;
    struct treenode *left;
    struct treenode *right;
} *Tree;

int is_empty(Tree t)
{
    return t == NULL;
}

int depth(Tree t)
{
    if (t == NULL)
        return -1;
    int left_depth = depth(t->left);
    int right_depth = depth(t->right);
    return 1 + ((left_depth > right_depth) ? left_depth : right_depth);
}

void print(Tree t)
{
    if (t == NULL)
        return;
    printf("%d ", t->value);
    print(t->left);
    print(t->right);
}

Tree find(Tree t, int value)
{
    if (t == NULL)
        return NULL;
    if (t->value == value)
        return t;
    Tree left = find(t->left, value);
    if (left != NULL)
        return left;
    return find(t->right, value);
}

void bfs(Tree t)
{
    List worklist = NULL;
    Tree tmp;
    insert(&worklist, t);
    while (worklist)
    {
        tmp = pop_last(&worklist);
        printf("%d ", tmp->value);
        if (tmp->left)
            insert(&worklist, tmp->left);
        if (tmp->right)
            insert(&worklist, tmp->right);
    }
}

int main()
{
    Tree t = NULL;
    printf("Empty: %d\n", is_empty(t));
    return 0;
}

int main()
{
    struct treenode t2 = {2, NULL, NULL}, t9 = {9, NULL, NULL}, t1 = {1, NULL, NULL};
    struct treenode t7 = {7, &t2, &t9};
    struct treenode t5 = {5, &t7, &t1};
    Tree t = &t5;
    printf("Depth: %d\n", depth(t));
    return 0;
}