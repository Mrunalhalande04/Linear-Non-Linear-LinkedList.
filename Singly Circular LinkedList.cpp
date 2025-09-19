//SINGLY circular linklist 

#include<iostream>
using namespace std;

struct  node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyCL
{
    public :
    PNODE head;
    PNODE tail;
    int icount;

    SinglyCL()
    {
      head=NULL;
      tail=NULL;
      icount=0;
    }

    void InsertFirst(int no)
    {
        PNODE newn=NULL;

        newn=new NODE;
        newn->next=NULL;
        newn->data=no;

        if((head==NULL) && (tail==NULL))
        {
           head=newn;
           tail=newn;
        }
        else
        {
            newn->next=head;
            head=newn;
        }
        tail->next=head;

        icount++;
    }

    void InsertLast(int no)
    {
        PNODE newn=NULL;

        newn=new NODE;
        newn->next=NULL;
        newn->data=no;

        if((head==NULL) && (tail==NULL))
        {
           head=newn;
           tail=newn;
        }
        else
        {
            tail->next=newn;
            tail=newn;
        }
        tail->next=head;

        icount++;
    }

    void DeleteFirst()
    {
        PNODE temp=NULL;

    if((head==NULL) && (tail==NULL))
    {
        return;
    }
    else if(head==tail)
    {
        delete head;
        head=NULL;
        tail==NULL;
    }

   else
   {
     head=(head)->next;
     delete ((tail)->next);
      (tail)->next=head;                       /* temp=*head;
                                                *head=(*head)->next;
                                                (*tail)->next=*head;
                                                 free(temp);*/
   }
   icount--;
    }

    void DeleteLast()
{
   
    PNODE temp=NULL;

    if((head==NULL) && (tail==NULL))
    {
        return;
    }
    else if(head==tail)
    {
        delete (head);
        head=NULL;
        tail==NULL;
    }

   else
   {
      temp=head;
      while(temp->next!=tail)
      {
        temp=temp->next;
      }
      delete temp->next;
      tail=temp;
      (tail)->next=head;
   }
   icount--;
}


void Display()
{
    if((head==NULL) && (tail==NULL))
    {
        cout<<"linklist is empty\n";
        return ;
    }

    do
    {
       cout<< head->data<<"\t";
       head=head->next;

    } while (head!=tail->next);
}

int Count()
{
    return icount;
}

void InsertAtPos(int no,int ipos)
{
    PNODE temp=NULL;
    PNODE newn=NULL;
    int icnt=0;
    
 
    if((ipos<1) && (ipos>icount+1))
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
        newn=new NODE;
        newn->next=NULL;
        newn->data=no;

        temp=head;

        for(icnt=1;icnt<ipos-1;icnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

        icount++;
    }
}

void DeleteAtPos(int ipos)
{
    PNODE target=NULL;
    PNODE temp=NULL;
    int icnt=0;
  
    if((ipos<1) && (ipos>icount))
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
        target=temp->next;
        temp->next=target->next;
        delete target;
        icount--;
    }
}

};


int main()
{
    int iret=0;
    SinglyCL sobj;
    sobj.InsertFirst(91);
    sobj.InsertFirst(81);
    sobj.InsertFirst(61);
    sobj.InsertFirst(51);
    sobj.InsertFirst(41);
    sobj.InsertFirst(31);
    sobj.InsertFirst(21);
    sobj.InsertLast(71);
    sobj.Display();
    iret=sobj.Count();
    cout<<"\nelements in link list is :"<<iret<<"\n";

    sobj.DeleteFirst();
    sobj.Display();
    iret=sobj.Count();
    cout<<"\nelements in link list is :"<<iret<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    iret=sobj.Count();
    cout<<"\nelements in link list is :"<<iret<<"\n";

    sobj.InsertAtPos(100,4);
    sobj.Display();
    iret=sobj.Count();
    cout<<"\nelements in link list is :"<<iret<<"\n";

    sobj.DeleteAtPos(4);
    sobj.Display();
    iret=sobj.Count();
    cout<<"\nelements in link list is :"<<iret<<"\n";



}
