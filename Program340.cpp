//cpp Deleteatpos

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyLL
{
    public:
        PNODE head;
        int iCount;

        SinglyLL()
        {
            head = NULL;
            iCount = 0;
        }

        void InsertFirst(int iNo)
        {
            PNODE newn = NULL;

            newn = new NODE;    //newn = (PNODE)malloc(sizeof(NODE))
            newn->data = iNo;
            newn->next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                newn->next = head;
                head = newn;
            }

            iCount++;
        }
        void InsertLast(int iNo)
        {
             PNODE newn = NULL;
             PNODE temp = NULL;

            newn = new NODE;    
            newn->data = iNo;
            newn->next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                temp = head;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;   
            }

            iCount++;
        }

        void InsertAtPos(int iNo , int ipos)
        {
            PNODE newn=NULL;
            PNODE temp=NULL;
            int icnt=0;
           
            if((ipos<1) ||(ipos>iCount+1))
            {
                cout<<"Invalid position\n";
                return;
            }

            if(ipos==1)
            {
                InsertFirst(iNo);
            }
            else if(ipos==iCount+1)
            {
                InsertLast(iNo);
            }

            else
            {
                newn= new NODE;
                newn->next=NULL;
                newn->data=iNo;

                temp=head;

                for(icnt=1;icnt<ipos-1;icnt++)
                {
                    temp=temp->next;
                }
                newn->next=temp->next;
                temp->next=newn;
                    iCount++;
            }
        }

        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(head == NULL)
            {
                return ;
            }

            else if(head->next == NULL)
            {
                delete head;
                head = NULL;
            }

            else
            {
                temp = head;

                head = head -> next;
                delete temp;
            }
            iCount--;
        }
        void DeleteLast()
        {
            PNODE temp = NULL;

            if(head == NULL)
            {
                return ;
            }

            else if(head->next == NULL)
            {
                delete head;
                head = NULL;
            }

            else
            {
                temp=head;

                while (temp->next->next!=NULL)
                {
                   temp=temp->next;
                }
                 delete temp->next;
                 temp->next=NULL;
            }
            iCount--;
        }
        void DeleteAtPos(int ipos)
        {
             PNODE target=NULL;
            PNODE temp=NULL;
            int icnt=0;
           
            if((ipos<1) ||(ipos>iCount))
            {
                cout<<"Invalid position\n";
                return;
            }

            if(ipos==1)
            {
                DeleteFirst();
            }
            else if(ipos==iCount)
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
          iCount--;
            }
        }

        void Display()
        {
            PNODE temp = head;

            cout<<"Elements of LinkedList are:\n";

            while(temp != NULL)
            {
                cout<<" "<<temp->data<<" | -> ";
                temp = temp->next;
            }

            cout<<"NULL\n";
        }

        int Count()
        {
            return iCount;
        }
};
int main()
{
    SinglyLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();
    iRet = sobj.Count();

    cout<<"Number of elements are :"<<iRet<<"\n";

    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

     sobj.Display();
    iRet = sobj.Count();

    cout<<"Number of elements are :"<<iRet<<"\n";

    sobj.DeleteFirst();
    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    sobj.InsertAtPos(31,3);
    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

     sobj.DeleteAtPos(3);
    sobj.Display();
    
    iRet = sobj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}