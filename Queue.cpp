// Queue

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;

}NODE , * PNODE;

class Queue   //Insertlast
{
    public:
        PNODE head;
        int iCount;

        Queue()
        {
            head = NULL;
            iCount = 0;
        }

        void Enqueue(int iNo)      
        { 
            PNODE newn = NULL;
            PNODE temp=NULL;

            newn = new NODE;

            newn->data = iNo;
            newn->next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
               temp=head;
               while(temp->next !=NULL)
               {
                temp=temp->next;
               }
               temp->next=newn;

            }
            iCount++;
        }

        int Dequeue()  //delete first
        { 
            PNODE temp = NULL;

            int no=-1;

            if(head == NULL)
            {
                cout<<"Stack is Empty\n";
                return -1;
            }
            else if(head->next == NULL)
            {
                no = head->data;
                delete head;
                head=NULL;
            }
            else
            {
                no=head->data;
                temp = head;
                head = head->next;
                delete temp;
            }
            iCount--;
            return no;
        }

        void Display()
        { 
            
            PNODE temp=head; 

            while(temp !=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
   
    int iret=0;

    Queue sobj;
    sobj.Enqueue(101);
    sobj.Enqueue(51);
    sobj.Enqueue(21);
    sobj.Enqueue(11);
   
    cout<<"Queue elements are \n";
    sobj.Display();
    iret=sobj.Count();
    
    cout<<"total elements "<<iret<<"\n";

    iret=sobj.Dequeue();
    cout<<"Dequeue elements is :"<<iret<<"\n";
    iret=sobj.Dequeue();
    cout<<"Dequeue elements is :"<<iret<<"\n";

    cout<<"Queue elements are \n";
    sobj.Display();

    iret=sobj.Count();
    cout<<"total elements "<<iret<<"\n";
    

    return 0;

}
