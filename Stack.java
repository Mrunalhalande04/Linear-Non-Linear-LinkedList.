class node
{
    public int data;
    public node next;
    
    public node(int X)
    {
        data=X;
        next=null;
    }
}

class Stack
{

    public node head;
    public int icount;

    public Stack()
    {
        head=null;
       icount=0;
    }

    public void Push(int ino)
    {
         node newn=null;

         newn =new node(ino);

         if(head==null)
         {
            head=newn;
         }

         else
         {
            newn.next=head;
            head=newn;
         }
         icount++;
    }

    public void Pop()
    {
        if(head==null)
         {
                 System.out.println("Stack is empty"); 
            return;
         }

         else if(head.next==null)
         {
            head=null;
            System.gc();
         }

         else 
         {
            node temp=head;
            head=head.next;
            System.gc();
         }
        
        icount--;

    }
    public void Display()
    {
        node temp=head;

        while(temp!=null)
        {
            System.out.println(temp.data);
            temp=temp.next; 
        }
    }


    public int Count()
    {
        return icount;
    }

}
public class Mrunal 
{
    public static void main(String Arg[])
    {
         QueueX qobj=new QueueX();

         qobj.Push(51);
        qobj.Push(21);
        qobj.Push(11);
        qobj.Pop();
        qobj.Display();
        int iret=0;
        iret=qobj.Count();

        System.out.println("Elements are :"+iret);
    }
    
}
