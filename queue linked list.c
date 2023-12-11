//queue link list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front = NULL, *rear = NULL;

void enqueue(int data)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    if(ptr == NULL)
    {
        printf("Overflowing\n");
        return;
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;
        if(front == NULL)
        {
            front = rear = ptr;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
    }
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Underflowing\n");
    }
    else
    {
        temp = front;
        front = front->next;
        free(temp);
    }
}





void display()
{
    struct node *ptr = front;

    if(ptr == NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }

        printf("\n\n");
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
//    dequeue();
//    dequeue();
//    dequeue();
//    dequeue();

    display();

    return 0;
}
