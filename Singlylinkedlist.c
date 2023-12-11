#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head=NULL;

void beginsert(int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Overflowing\n");
    }
    else
    {
        newNode->data = data;
        newNode->next = head;
        head=newNode;
    }
}

void lastinsert(int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Overflowing\n");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct node *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insertafternode(int data, int position)
{
    struct node *newNode = malloc(sizeof(struct node));
    if(newNode==NULL)
    {
        printf("Overflowing\n");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            struct node *temp = head;

            for(int i = 1; i < position; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void begin_delete()
{
    if(head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void last_delete()
{
    if(head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        struct node *temp = head;
        struct node *prev = NULL;

        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        if(prev != NULL)
        {
            prev->next = NULL;
        }
        else
        {
            head = NULL;
        }
        free(temp);
    }
}

void random_delete(int position)
{
    if(head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        struct node *temp = head;
        struct node *prev = NULL;

        for(int i = 1; i < position; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        if(prev != NULL)
        {
            prev->next = temp->next;
        }
        else
        {
            head = temp->next;
        }
        free(temp);
    }
}

void search(int data)
{
    struct node *temp = head;
    int position = 0;

    while(temp != NULL)
    {
        position++;
        if(temp->data == data)
        {
            printf("Data found at position %d\n", position);
            return;
        }
        temp = temp->next;
    }
    printf("Data not found in the list\n");
}

void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n\n");
}


int main()
{
    beginsert(3);
    beginsert(2);
    beginsert(1);

    lastinsert(7);
    lastinsert(8);
    lastinsert(9);

    insertafternode(4, 3);
    insertafternode(5, 4);
    insertafternode(6, 5);

    display();
//
//    begin_delete();
//    last_delete();
//    random_delete();
//
//    display();
//
//    search(3);
//    search(7);

    return 0;
}
