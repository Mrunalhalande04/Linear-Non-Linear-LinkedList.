
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;

}NODE , * PNODE;

class Stack
{
    public:
        PNODE head;
        int iCount;

        Stack()
        {
            head = NULL;
            iCount = 0;
        }

        void Push(int iNo)      //Insertfirst
        { 
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = iNo;
            newn->next = NULL;

            if(head == NULL)
            {
                head = newn;
            }
            else
            {
                newn->next=head;
                head=newn;
            }
            iCount++;
        }


        int Pop()  //delete first
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

    Stack sobj;
    sobj.Push(101);
    sobj.Push(51);
    sobj.Push(21);
    sobj.Push(11);
   
    cout<<"stack elements are \n";
    sobj.Display();
    iret=sobj.Count();
    
    cout<<"total elements "<<iret<<"\n";

    iret=sobj.Pop();
    cout<<"pop elements is :"<<iret<<"\n";
    iret=sobj.Pop();
    cout<<"pop elements is :"<<iret<<"\n";

    cout<<"stack elements are \n";
    sobj.Display();

    iret=sobj.Count();
    cout<<"total elements "<<iret<<"\n";
    

    return 0;

}
