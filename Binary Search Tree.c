//inoder ,preorder,postorder
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE,*PNODE,**PPNODE;

void Insert(PPNODE head,int no)
{
    PNODE newn=NULL;
    PNODE temp=NULL;

    newn=(PNODE)malloc(sizeof(NODE));
    newn->rchild=NULL;
    newn->lchild=NULL;
    newn->data=no;

    if(*head==NULL)
    {
        *head=newn;
    }

    else
    {
        temp=*head;
        while(1)
        {
            if(no>temp->data)
            {
                if(temp->rchild==NULL)
                {
                    temp->rchild=newn;
                     break;
                }
                temp=temp->rchild;
            }

           else if(no<temp->data)
            {
                if(temp->lchild==NULL)
                {
                    temp->lchild=newn;
                     break;
                }
                temp=temp->lchild;
            }

            else if(no==temp->data)
            {
                printf("duplicate elements cannot be inserted\n");
                free(newn);
                break;
            }
        }
    }
}

void Inorder(PNODE head)
{
    if(head!=NULL)
    {
        Inorder(head->lchild);
        printf("%d\n",head->data);
        Inorder(head->rchild);
    }
}

void preorder(PNODE head)
{
    if(head!=NULL)
    {
        printf("%d\n",head->data);
        preorder(head->lchild);
        preorder(head->rchild);
    }
}

void postorder(PNODE head)
{
    if(head!=NULL)
    {
        postorder(head->lchild);
        postorder(head->rchild);
        printf("%d\n",head->data);
    }
}

int main()
{
    PNODE first=NULL;

    Insert(&first,51);
    Insert(&first,21);
    Insert(&first,101);

    printf("elements in inorder\n");
    Inorder(first);

    printf("elements in preorder\n");
    preorder(first);

    printf("elements in postorder\n");
    postorder(first);

    return 0;
}
