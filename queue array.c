#include<stdio.h>
int arr[100];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if(rear > 99)
    {
        printf("Overflowing.\n");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front++;
        rear++;
    }
    else
    {
        rear++;
    }
    arr[rear] = data;
}

void dequeue()
{

    if(front == -1 || front >rear)
    {
        printf("Underflowing.\n");
    }
    else
    {
        front++;
    }

}

void display()
{
    if(rear == -1)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        for(int i = front; i<=rear; i++)
        {
            printf("%d ", arr[i]);
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
