/// DOUBLY circular linklist 
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE head,PPNODE tail,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));
    newn->next=NULL;
    newn->prev=NULL;
    newn->data=no;

    if((*head==NULL) && (*tail==NULL))
    {
        *head=newn;
        *tail=newn;
    }

    else
    {
        newn->next=*head;
        (*head)->prev=newn;
        *head=newn;
    }
    (*tail)->next=*head;
    (*head)->prev=*tail;
}

void InsertLast(PPNODE head,PPNODE tail,int no)
{
    PNODE newn=NULL;
    PNODE temp=NULL;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->next=NULL;
    newn->prev=NULL;
    newn->data=no;

    if((*head==NULL) && (*tail==NULL))
    {
        *head=newn;
        *tail=newn;
    }

    else
    {
      // (*tail)->next=newn;
       newn->prev=*tail;
       (*tail)->next=newn;
        *tail=newn;


    }
    (*tail)->next=*head;
    (*head)->prev=*tail;

}

void DeleteFirst(PPNODE head,PPNODE tail)
{
    //PNODE temp=NULL;
   if((*head==NULL) && (*tail==NULL))
   {
    return;
   }

   else if(*head == *tail)
   {
        free(*head);
        *head = NULL;
        *tail = NULL;
   }

    else
    {
  *head=(*head)->next;        // temp=*head;
   free((*tail)->next);      // *head=(*head)->next;
   }                        //  free(temp);
    
    (*tail)->next=*head;
    (*head)->prev=*tail;
}

void DeleteLast(PPNODE head,PPNODE tail)
{
    if((*head==NULL) && (*tail==NULL))
    {
        return ;
    }
    else if(*head==*tail)
    {
        free(*head);
        *head=NULL;
        *tail==NULL;
    }

    else
    {
        *tail=(*tail)->prev;
        free((*tail)->next);
    }

    (*tail)->prev=*head;
    (*head)->prev=*tail;
    printf("\n");
}

void Display(PNODE head,PNODE tail)
{
    if((*head==NULL) && (*tail==NULL))
    {
     printf("Linklist is empty\n");
     return;   
    }
    do
    {
        printf(" | %d | <=>",head->data);
        head=head->next;
    }
    while(head!=tail->next);

}

int Count(PNODE head,PNODE tail)
{
    int icount=0;

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
    int countnode=0;
    int icnt=0;

    countnode=Count(*head,*tail);

    if((ipos<1) || (ipos>countnode+1))
    {
        printf("Invalid position\n");
        return ;
    }

    else if(ipos==1)
    {
        InsertFirst(head,tail,no);
    }

    else if(ipos==countnode+1)
    {
        InsertLast(head,tail,no);
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
        newn->next->prev=newn;  //right connention
        temp->next=newn;
        newn->prev=temp;     //left connention
    }
    (*tail)->prev=*head;
    (*head)->prev=*tail;
    printf("\n");
}

void DeleteAtPos(PPNODE head,PPNODE tail,int ipos)
{
    PNODE temp=NULL;
    PNODE target=NULL;
    int countnode=0;
    int icnt=0;

    countnode=Count(*head,*tail);

    if((ipos<1) || (ipos>countnode))
    {
        printf("Invalid position\n");
        return ;
    }

    else if(ipos==1)
    {
        DeleteFirst(head,tail);
    }

    else if(ipos==countnode)
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

        temp->next=temp->next->next;
        free(temp->next->prev);
        temp->next->prev=temp;
    }
    (*tail)->prev=*head;
    (*head)->prev=*tail;
    printf("\n");
}


int main()
{
    PNODE first=NULL;
    PNODE last=NULL;
    int iret=0;
    
    InsertFirst(&first,&last,91);
    InsertFirst(&first,&last,81);
    InsertFirst(&first,&last,71);
    InsertFirst(&first,&last,61);
    InsertFirst(&first,&last,51);
    InsertFirst(&first,&last,21);
    InsertFirst(&first,&last,11);
    InsertLast(&first,&last,61);

     Display(first,last);
     iret=Count(first,last);
     printf("elements in linklist %d\n",iret);
    

     DeleteFirst(&first,&last);
     Display(first,last);
     iret=Count(first,last);
     printf("elements in linklist %d\n",iret);
    

     DeleteLast(&first,&last);
     Display(first,last);
     iret=Count(first,last);
     printf("elements in linklist %d\n",iret);


     InsertAtPos(&first,&last,75,4);
     Display(first,last);
     iret=Count(first,last);
     printf("elements in linklist %d\n",iret);
     
     DeleteAtPos(&first,&last,4);
     Display(first,last);
     iret=Count(first,last);
     printf("elements in linklist %d\n",iret);
     

    return 0;
}
