//Doubly linear link list
#include <iostream>
using namespace std;

struct  node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class DoublyLL
{
    public:

   PNODE head;
   int icount;

   DoublyLL()
   {
    head =NULL;
    icount=0;
   }

   void InsertFirst(int no)
   {
    PNODE newn=NULL;

    newn=new NODE;
    newn->next=NULL;
    newn->prev=NULL;
    newn->data=no;

    if(head==NULL)
    {
        head=newn;
    }
    else
    {
       newn->next=head;
       head->prev=newn;
       head=newn;
    }
      icount++;
   }

   void InsertLast(int no)
   {
 PNODE newn=NULL;
 PNODE temp=NULL;

    newn=new NODE;
    newn->next=NULL;
    newn->prev=NULL;
    newn->data=no;

    if(head==NULL)
    {
        head=newn;
    }
    else
    {
       temp=head;

       while(temp->next!=NULL)
       {
        temp=temp->next;
       }
       temp->next=newn;
       newn->prev=temp;
    }
      icount++;
   }

   void DeleteFirst()
   {
    PNODE temp=NULL;

    if(head==NULL)
    {
        return ;
    }

    else if(head->next==NULL)
    {
        delete head;
        head=NULL;
    }

    else 
    {
        temp=head;
        head=head->next;
        delete temp;
        head->prev=NULL;
    }
    icount--;
   }

   void DeleteLast()
   {
     PNODE temp=NULL;
     

    if(head==NULL)
    {
        return ;
    }

    else if(head->next==NULL)
    {
        delete head;
        head=NULL;
    }

    else 
    {
        temp=head;

        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }

        delete temp->next;
        temp->next=NULL;
    }
    icount--;
   }

   void Display()
   {
      PNODE temp=head;

      cout<<"NULL";
      while(temp!=NULL)
      {
       
        cout<<" -> |"<<temp->data<<" | " ;
        temp=temp->next;
        
      }
      cout<<"NULL \n";
   }

   int Count()
   {
    return icount;
   }

   void InsertAtPos(int no,int ipos)
   {
    PNODE newn=NULL;
    PNODE temp=NULL;
    int icnt=0;

    if((ipos<1) || (ipos>icount+1))
    {
        cout<<"Invalid position\n";
        return ;
    }

     if(ipos==1)
    {
        InsertFirst(no);
    }

    else if(ipos==icount+1)
    {
        InsertLast(no);
    }

    else
    {
        newn=new NODE;
        newn->next=NULL;
        newn->prev=NULL;
        newn->data=no;

        temp=head;

        for(icnt=1;icnt<ipos-1;icnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
icount++;
    }
    
}

    void DeleteAtPos(int ipos)
   {
    PNODE newn=NULL;
    PNODE temp=NULL;
    PNODE target=NULL;
    int icnt=0;

    if((ipos<1) || (ipos>icount))
    {
        cout<<"Invalid position\n";
        return ;
    }

     if(ipos==1)
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
       
        target=temp->next;
        
       temp->next=target->next;
       temp->next->prev=temp;
        delete target;
     icount--;
    }
   }
   
};
int main()
{
    DoublyLL dobj;
    int iret=0;
    
    dobj.InsertFirst(61);
    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.Display();
    iret=dobj.Count();

    cout<<"number of nodes in linklist is "<<iret<<"\n";

    dobj.InsertLast(10);
    dobj.InsertLast(15);
    dobj.Display();
    iret=dobj.Count();

    cout<<"number of nodes in linklist is "<<iret<<"\n";

    dobj.DeleteFirst();
    dobj.Display();
    iret=dobj.Count();

    cout<<"number of nodes in linklist is "<<iret<<"\n";

    dobj.DeleteLast();
    dobj.Display();
    iret=dobj.Count();

    cout<<"number of nodes in linklist is "<<iret<<"\n";

    dobj.InsertAtPos(45,3);
    dobj.Display();
     iret=dobj.Count();

    cout<<"number of nodes in linklist is... "<<iret<<"\n";

     dobj.DeleteAtPos(3);
    dobj.Display();
     iret=dobj.Count();

    cout<<"number of nodes in linklist is... "<<iret<<"\n";



    return 0;
}
