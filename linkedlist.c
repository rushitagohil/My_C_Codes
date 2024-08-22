#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
};

void insert_last(struct node *, int);
void display(struct node *);
struct node *create_node(int);
struct node *insert_first(struct node *, int);

int main()
{
    // struct node a, b, c;
    struct node *p;
    p = create_node(10);
    p = insert_first(p, 50);
    insert_last(p, 20);
    insert_last(p, 30);
    display(p);
    insert_last(p, 40);
    display(p);
    p = insert_first(p, 60);
    display(p);
    // a.data = 10;
    // a.ptr  = &b;
    // b.data = 20;
    // b.ptr  = &c;
    // c.data = 30;
    // c.ptr  = NULL;
    // printf("Hello, World!\n");
    // display(a);
    return 0;
}

void display(struct node *x)
{
    // while(x.ptr != NULL)
    // {
    //     printf("%d ", x.data);
    //     x = *x.ptr;
    // }
    // printf("%d", x.data);
    while (x != NULL)
    {
        printf("%d ", (*x).data);
        x = (*x).ptr;
    }
    printf("\n");
}

void insert_last(struct node *p, int data)
{
    struct node *temp = p;
    while((*temp).ptr != NULL)
    {
        temp = (*temp).ptr;
    }
    (*temp).ptr = create_node(data);
}

struct node *create_node(int data)
{
    struct node *new_node_ptr = (struct node *)malloc(sizeof(struct node));
    (*new_node_ptr).data = data;
    (*new_node_ptr).ptr = NULL;
    return new_node_ptr;
}

struct node *insert_first(struct node *p, int data)
{
    struct node *new_node_ptr = create_node(data);
    (*new_node_ptr).ptr = p;
    return new_node_ptr;
}