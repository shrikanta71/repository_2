//stack linklist
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*top = NULL;

void push(int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    if(ptr == NULL)
    {
        printf("Unable to push data.\n");
    }
    else
    {
        ptr->data = data;
        ptr->next = top;
        top = ptr;
    }
}

void pop()
{
    struct node *ptr;

    if(top == NULL)
    {
        printf("underflowing.\n");
    }
    else
    {
        ptr = top;
        top = top->next;

        free(ptr);
    }
}

void display()
{
    struct node *ptr = top;

    if(ptr == NULL)
    {
        printf("stack is empty.\n");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }

    printf("\n\n");
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);

    display();


    pop();
    pop();
    pop();
    pop();
//    pop();
//    pop();
//    pop();
//    pop();

    display();

    return 0;
}
