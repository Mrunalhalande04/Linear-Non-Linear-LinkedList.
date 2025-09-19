//Doubly Circular LinkedList
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE ,*PNODE,**PPNODE;

class DoublyCL
{
    public :
   int icount;
   PNODE head;
   PNODE tail;

   DoublyCL ()
   {
    icount=0;
    head=NULL;
    tail=NULL;
   }

   void InsertFirst(int no)
   {
    PNODE newn=NULL;
    newn=new NODE;
    newn->next=NULL;
    newn->prev=NULL;
    newn->data=no;

    if((head==NULL) && (tail==NULL))
    {
        head=newn;
        tail=newn;
    }

    else
    {
        head->prev=newn;
        newn->next=head;
        head=newn;
    }

    tail->next=head;
    head->prev=tail;

    icount++;
   }

   void InsertLast(int no)
   {
    PNODE newn=NULL;
    newn=new NODE;
    newn->next=NULL;
    newn->prev=NULL;
    newn->data=no;

    if((head==NULL) && (tail==NULL))
    {
        head=newn;
        tail=newn;
    }

    else
    {
        newn->prev=tail;
        tail->next=newn;
        tail=newn;
    }

    tail->next=head;
    head->prev=tail;

    icount++;
   }

   void DeleteFirst()
   {
   // PNODE temp=NULL;
    if((head==NULL) && (tail==NULL))
    {
        return;
    }

    else if(head==tail)
    {
        delete head;
        head=NULL;
        tail=NULL;
    }

    else
    {
       head=head->next;          // temp=*head;
       delete (tail->next);       // *head=(*head)->next; 
     }                         //  free(temp);
    

    tail->next=head;
    head->prev=tail;

    icount--;
   }

   void DeleteLast()
   {
    
    if((head==NULL) && (tail==NULL))
    {
        return;
    }

    else if(head==tail)
    {
        delete head;
        head=NULL;
        tail=NULL;
    }

    else
    {
       tail=tail->prev;
       delete tail->next;
    }
    tail->next=head;
    head->prev=tail;

    icount--;
   }

   void Display()
   {

     if((head==NULL) && (tail==NULL))
     {
        cout<<"LinkedList is empty";
     }


    do
    {
        cout<<head->data<<"\t";
        head=head->next;
    }
    while(head!=tail->next);
   }

   int Count()
   {
    return icount;
   }

   void InsertAtPos(int ipos,int no)
   {
    PNODE newn=NULL;
    PNODE temp=NULL;
    int icnt=0;

   if((ipos<1) && (ipos> icount+1))
   {
    cout<<"invalid position\n";
    return;
   }

   else if(ipos==1)
   {
    InsertFirst(no);
   }

   else if(ipos==icount+1)
   {
    InsertLast(no);
   }

   else
   {
    temp=head;
     newn=new NODE;
     newn->next=NULL;
     newn->prev=NULL;
     newn->data=no;

     for(icnt=1;icnt<ipos-1;icnt++)
     {
        temp=temp->next;
     }
     newn->next=temp->next;
     temp->next->prev=newn;
     temp->next=newn;
     newn->prev=temp;

    tail->next=head;
    head->prev=tail;
    
     icount++;
   }
   }

    void DeleteAtPos(int ipos)
   {
    PNODE newn=NULL;
    PNODE temp=NULL;
    PNODE target=NULL;
    int icnt=0;

   if((ipos<1) && (ipos> icount))
   {
    cout<<"invalid position\n";
    return;
   }

   else if(ipos==1)
   {
    DeleteFirst();
   }

   else if(ipos==icount)
   {
    DeleteLast();
   }

   else
   {
    temp=head;
     
     for(icnt=1;icnt<ipos-1;icnt++)
     {
        temp=temp->next;
     }
     
      temp->next=temp->next->next;                //target=temp->next;
      delete temp->next->prev;                   //target->next->prev=temp;    
      temp->next->prev=temp;;                    //temp->next=target->next;
                                                 //delete target;                                            
    tail->next=head;
    head->prev=tail;
    
     icount--;
   }
   }

};
int main()
{
    int iret=0;
    DoublyCL dobj;
    dobj.InsertFirst(51);
    dobj.InsertFirst(41);
    dobj.InsertFirst(31);
    dobj.InsertFirst(21);
    dobj.InsertLast(25);

    dobj.Display();
    iret=dobj.Count();
    cout<<"\nlinklist elements are "<<iret<<"\n";

    dobj.DeleteFirst();
    dobj.Display();
    iret=dobj.Count();
    cout<<"\nlinklist elements are "<<iret<<"\n";

    dobj.DeleteLast();
    dobj.Display();
    iret=dobj.Count();
    cout<<"\nlinklist elements are "<<iret<<"\n";

    dobj.InsertAtPos(2,25);
    dobj.Display();
    iret=dobj.Count();
    cout<<"\nlinklist elements are "<<iret<<"\n";
    
     dobj.DeleteAtPos(2);
     dobj.Display();
     iret=dobj.Count();
     cout<<"\nlinklist elements are "<<iret<<"\n";


    return 0;
}
