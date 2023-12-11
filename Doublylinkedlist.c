
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *head = NULL;
int position = 0;

void begin_insert(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
    position++;
}

void end_insert(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    position++;
}

void random_insert(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        int randomPosition = rand() % position + 1; //+1 to avoid the head

        for(int i = 1; i < randomPosition; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp;
        newNode->prev = temp->prev;

        if(temp->prev != NULL)
        {
            temp->prev->next = newNode;
        }
        temp->prev = newNode;
    }
    position++;
}

void begin_delete()
{
    if(head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        Node *temp = head;
        head = head->next;

        if(head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        position--;
    }
}

void end_delete()
{
    if(head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        Node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        free(temp);
        position--;
        position--;
    }
}

void random_delete()
{
    if(head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        Node *temp = head;
        Node *prev = NULL;
        int randomPosition = rand() % position + 1; //+1 to avoid the head

        for(int i = 1; i < randomPosition; i++)
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

        if(temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        free(temp);
        position--;
    }
}

void search(int data)
{
    Node *temp = head;
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
    Node *temp = head;

    if(head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int data, choice;

    while(1)
    {
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Random\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Random\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            begin_insert(data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            end_insert(data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            random_insert(data);
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            end_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            printf("Enter data to search: ");
            scanf("%d", &data);
            search(data);
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
