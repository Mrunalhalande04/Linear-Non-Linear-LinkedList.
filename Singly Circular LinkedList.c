//SINGLY circular Linklist

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

void Insertfirst(PPNODE head,PPNODE tail,int no)
{
   PNODE newn=NULL;

   newn=(PNODE)malloc(sizeof(NODE));
   newn->next=NULL;
   newn->data=no;

   if((*head==NULL) && (*tail==NULL))
   {
      *head=newn;
      *tail=newn;
   }
   else
   {
    newn->next=*head;
    *head=newn;
   }
   (*tail)->next=*head;
}

void InsertLast(PPNODE head,PPNODE tail,int no)
{
   PNODE newn=NULL;

   newn=(PNODE)malloc(sizeof(NODE));
   newn->next=NULL;
   newn->data=no;

   if((*head==NULL) && (*tail==NULL))
   {
      *head=newn;
      *tail=newn;
   }
   else
   {
    (*tail)->next=newn;
    *tail=newn;
   }
   (*tail)->next=*head; 
}

void Deletefirst(PPNODE head,PPNODE tail)
{
    PNODE temp=NULL;

    if((*head==NULL) && (*tail==NULL))
    {
        return;
    }
    else if(*head==*tail)
    {
        free(*head);
        *head=NULL;
        *tail==NULL;
    }

   else
   {
     *head=(*head)->next;
     free((*tail)->next);
      (*tail)->next=*head;                       /* temp=*head;
                                                *head=(*head)->next;
                                                (*tail)->next=*head;
                                                 free(temp);*/
   }
}

void DeleteLast(PPNODE head,PPNODE tail)
{
   
    PNODE temp=NULL;

    if((*head==NULL) && (*tail==NULL))
    {
        return;
    }
    else if(*head==*tail)
    {
        free(*head);
        *head=NULL;
        *tail==NULL;
    }

   else
   {
      temp=*head;
      while(temp->next!=*tail)
      {
        temp=temp->next;
      }
      free(temp->next);
      *tail=temp;
      (*tail)->next=*head;
   }
}

void Display(PNODE head,PNODE tail)
{
  
    if((head==NULL) && (tail==NULL))
    {
        printf("linklist is empty\n");
      return;
    }
 

    do
    {
        printf(" |%d |->",head->data);
        head=head->next;
    }
    while(head!=tail->next);
}

int Count(PNODE head,PNODE tail)
{
    int icount=0;
    if((head==NULL) && (tail==NULL))
    {
        printf("linklist is empty\n");
      return 0;
    }

    do{
        icount++;
        head=head->next;
    }
    while(head!=tail->next);

    return icount;
}

void InsertAtPos(PPNODE head,PPNODE tail,int no,int ipos)
{
    PNODE temp=NULL;
    PNODE newn=NULL;
    int icnt=0;
    int countnodes=0;

    countnodes=Count(*head,*tail);

    if((ipos<1) && (ipos>countnodes+1))
    {
      printf("invalid position\n");
      return;
    }

    else if(ipos==1)
    {
        Insertfirst(head,tail,no);
    }
    else if(ipos==countnodes+1)
    {
        InsertLast(head,tail,no);
    }

    else
    {
        newn=(PNODE)malloc(sizeof(NODE));
        newn->next=NULL;
        newn->data=no;

        temp=*head;

        for(icnt=1;icnt<ipos-1;icnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

void DeleteAtPos(PPNODE head,PPNODE tail,int ipos)
{
    PNODE target=NULL;
    PNODE temp=NULL;
    int icnt=0;
    int countnodes=0;

    countnodes=Count(*head,*tail);

    if((ipos<1) && (ipos>countnodes))
    {
      printf("invalid position\n");
      return;
    }

    else if(ipos==1)
    {
        Deletefirst(head,tail);
    }
    else if(ipos==countnodes)
    {
        DeleteLast(head,tail);
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
  PNODE last=NULL;
  int iret=0;

  Insertfirst(&first,&last,51);
  Insertfirst(&first,&last,41);
  Insertfirst(&first,&last,31);
  Insertfirst(&first,&last,21);
  Insertfirst(&first,&last,11);
  Insertfirst(&first,&last,10);
  InsertLast(&first,&last,61);
  Display(first,last);
  iret=Count(first,last);
  printf("\nelements in linklist is :  %d\n",iret);

  Deletefirst(&first,&last);
  Display(first,last);
  iret=Count(first,last);
  printf("\nelements in linklist is : %d \n",iret);

  DeleteLast(&first,&last);
  Display(first,last);
  iret=Count(first,last);
  printf("\nelements in linklist is :  %d\n",iret);

  InsertAtPos(&first,&last,20,4);
  Display(first,last);
  iret=Count(first,last);
  printf("\nelements in linklist is :  %d\n",iret);

  DeleteAtPos(&first,&last,4);
  Display(first,last);
  iret=Count(first,last);
  printf("\nelements in linklist is :  %d\n",iret);
  




    return 0;
}
