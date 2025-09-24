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

class QueueX
{

    public node head;
    public int icount;

    public QueueX()
    {
        head=null;
       icount=0;
    }

    public void Enqueue(int ino)
    {
         node newn=null;
         node temp=head;

         newn =new node(ino);

         if(head==null)
         {
            head=newn;
         }

         else
         {
            while(temp.next!=null)
            {
                temp=temp.next;
            }
            temp.next=newn;
         }
         icount++;
    }

    public void Dequeue()
    {
        if(head==null)
         {
           System.out.println("Queue is empty");
            return ;
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

         qobj.Enqueue(51);
        qobj.Enqueue(21);
        qobj.Enqueue(11);
        qobj.Dequeue();
        qobj.Display();
        int iret=0;
        iret=qobj.Count();

        System.out.println("Elements after pushing are :"+iret);
    }
    
}
