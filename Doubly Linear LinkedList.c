//DOUBLY  linear linklist
#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;
   struct node *prev;  //$
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));
    newn->next=NULL;
    newn->prev=NULL;  //$
    newn->data=no;

    if(*head==NULL)
    {
        *head=newn;
    }

    else
    {
        newn->next=*head;
        (*head)->prev=newn;   //$
        *head=newn;

    }
}

void InsertLast(PPNODE head,int no)
{
 PNODE newn=NULL;
 PNODE temp=NULL;

    newn=(PNODE)malloc(sizeof(NODE));
    newn->next=NULL;
    newn->prev=NULL;   //$
    newn->data=no;

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
       newn->prev=temp;   //$
    }
}

void Display(PNODE head)
{
    while(head!=NULL)
    {
        printf(" | %d |<->",head->data);
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
        return ;
    }
    else if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
    }

    else
    {
        temp=*head;
        *head=(*head)->next;
        free(temp);
        (*head)->prev=NULL;  //$
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp=NULL;

    if(*head==NULL)
    {
        return ;
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

    countnodes=Count(*head);

    if((ipos<1) || (ipos>countnodes+1))
    {
        printf("Invalid position\n");
    return ;
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
        newn=(PNODE)malloc(sizeof(NODE));
        newn->next=NULL;
        newn->prev=NULL;
        newn->data=no;
      temp=*head;

        for(icnt=1;icnt<ipos-1;icnt++)
        {
            temp=temp->next;
        }

        newn->next=temp->next;
        temp->next->prev=newn;   //$
        temp->next=newn;
        newn->prev=temp;         //$
    }
}

void DeleteAtPos(PPNODE head,int ipos)
{
    
    PNODE temp=NULL;
    PNODE target=NULL;
    int icnt=0;
    int countnodes=0;

    countnodes=Count(*head);

    if((ipos<1) || (ipos>countnodes))
    {
        printf("Invalid position\n");
    return ;
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
        target->prev=temp;          //$
        free(target);
    }
}

int main()
{
    PNODE first=NULL;
    int iret=0;
     InsertFirst(&first,55);
    InsertFirst(&first,51);
    InsertFirst(&first,21);
    InsertFirst(&first,11);
    InsertLast(&first,61);
    InsertLast(&first,5);
    InsertLast(&first,16);


    Display(first);
    iret=Count(first);
    
    printf("NULL\n");
    printf("elements in linklist is %d\n",iret);

    DeleteFirst(&first);
    Display(first);
    iret=Count(first);
    
    printf("NULL\n");
    printf("elements in linklist is %d\n",iret);

    DeleteLast(&first);
    Display(first);
    iret=Count(first);
    
    printf("NULL\n");
    printf("elements in linklist is %d\n",iret);

    InsertAtPos(&first,15,3);
    Display(first);
    iret=Count(first);
    
    printf("NULL\n");
    printf("elements in linklist is %d\n",iret);

    
    DeleteAtPos(&first,3);
    Display(first);
    iret=Count(first);
    
    printf("NULL\n");
    printf("elements in linklist is %d\n",iret);
    

    return 0;
}
