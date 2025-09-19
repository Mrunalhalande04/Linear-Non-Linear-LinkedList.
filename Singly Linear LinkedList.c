// SINGLY Linear LinkList

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;


void InsertFirst(PPNODE head,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if(*head==NULL)
    {
        *head=newn;
    }

    else
    {
        newn->next=*head;
        *head=newn;
    }
}

void InsertLast(PPNODE head,int no)
{
      PNODE newn=NULL;
      PNODE temp=NULL;

    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;
    

    if(*head==NULL)
    {
        *head=newn;
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

void Display(PNODE head)
{
    while(head!=NULL)
    {
        printf("| %d |->",head->data);
        head=head->next;
    }
}

int Count(PNODE head)
{
    int icount=0;
    while(head!=NULL)
    {
        icount++;
        head=head->next;
    }
    return icount;
}

void DeleteFirst(PPNODE head)
{

    PNODE temp=NULL;

    if(*head==NULL)
    {
        return;
    }
  
    else if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
    {
    temp=*head;
   *head=temp->next;
   free(temp);
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp=NULL;

    if(*head==NULL)
    {
        return;
    }

    else if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
    }

    else
    {
        temp=*head;

        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void InsertAtPos(PPNODE head,int no,int ipos)
{
    PNODE newn=NULL;
    PNODE temp=NULL;
    int icnt=0;
    int countnodes=0;

     newn=(PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;

    countnodes=Count(*head);

    if((ipos<1) || (ipos>countnodes+1))
    {
     printf("invalid position\n");
     return;
    }

    if(ipos==1)
    {
        InsertFirst(head,no);
    }

    else if(ipos==countnodes+1)
    {
        InsertLast(head,no);
    }

    else
    {
        temp=*head;

        for(icnt=1;icnt<ipos-1;icnt++)
        {
            temp=temp->next;
        }

        newn->next=temp->next;
        temp->next=newn;
    }
}


 void DeleteAtPos(PPNODE head,int ipos)
{
    PNODE newn=NULL;
    PNODE temp=NULL;
    PNODE target=NULL;
    int countnodes=0;
    int icnt=0;

    countnodes=Count(*head);

    if((ipos<1) || (ipos>countnodes))
    {
     printf("invalid position\n");
     return;
    }

    if(ipos==1)
    {
        DeleteFirst(head);
    }

    else if(ipos==countnodes)
    {
        DeleteLast(head);
    }

    else
    {
        temp=*head;

        for(icnt=1;icnt<ipos-1;icnt++)
        {
            temp=temp->next;
        }
        target=temp->next;
        temp->next=target->next;
        free(target);
    }
}
    
int main()

{
    PNODE first=NULL;
    int iret=0;
    
    InsertFirst(&first,50);
    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertLast(&first,100);

    Display(first);
    iret=Count(first);   
    printf("NULL\n");
    printf("elements in linklist is %d\n",iret);

    DeleteFirst(&first);
    Display(first);
    iret=Count(first); 
    printf("NULL\n");
    printf("elements in linklist after deleting first node %d\n",iret);

    DeleteLast(&first);
    Display(first);
    iret=Count(first); 
    printf("NULL\n");
    printf("elements in linklist after deleting last node %d\n",iret);

    InsertAtPos(&first,200,3);
    Display(first);
    iret=Count(first); 
    printf("NULL\n");
    printf("linklist after inserting elements at position %d\n",iret);

    DeleteAtPos(&first,3);
    Display(first);
    iret=Count(first); 
    printf("NULL\n");
    printf("linklist after deleting elements at position %d\n",iret);

    return 0;
}
