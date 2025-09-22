// QUEUE

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next; 
}NODE , *PNODE,**PPNODE;

void EnQueue(PPNODE head, int iNo) //insertLast
{
    PNODE newn = NULL;
    PNODE temp=NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
    }
    else
    {
        temp=*head;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      temp->next=newn;
  
    }
}

int DeQueue(PPNODE head)    //deletefirst
{
    PNODE temp = NULL;

    int no = -1;

    if(*head == NULL)       //empty
    {
        printf("Stack is Empty\n");
       return -1;
    }
    else if((*head)->next == NULL)  //single node
    {
        no = (*head)->data;
        free(*head);
        *head = NULL;
    }
    else        //more than one node
    {
        no = (*head)->data;
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    return no;
}

void Display (PNODE head)
{ 
    printf("Elements of stack are :\n");

    while(head != NULL)
    {
        printf("| %d |\n",head->data);
        head = head->next;
    }
}

int Count(PNODE head)
{ 
    int iCount = 0;
    while(head != NULL)
    {
        iCount++;
        head = head->next;
    }
    return iCount;
}

int main()
{
    PNODE first = NULL;

    int iRet = 0;

    EnQueue(&first,101);
    EnQueue(&first,51);
    EnQueue(&first,21);
    EnQueue(&first,11);

    Display(first);

    iRet = DeQueue(&first);
    printf("Popped element is :%d\n",iRet);

    Display(first);

    iRet = DeQueue(&first);
    printf("Popped element is :%d\n",iRet);

    

    return 0;
}
