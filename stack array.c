//stack array
#include<stdio.h>
int top = -1;
int arr[100];

void push(int data)
{
    if(top>99)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        arr[top] = data;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        top--;
    }
}

void show()
{
    for(int i=top; i>=0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    show();

    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

    show();

    return 0;
}
