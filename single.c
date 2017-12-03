#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
    struct node *next;
}NODE;

typedef struct slist
{
	NODE *st;
}SLIST;

void init(SLIST *t)
{
    t->st=NULL;
}

NODE *createNode(int d)
{
	NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}
NODE *getLastNode(SLIST *t)
{
    NODE *a=t->st;
    while(a->next!=NULL)
    {
        a=a->next;
    }
    return a;
}

void addEnd(SLIST *t,int d)
{
    NODE *a=createNode(d);
    NODE *b;
    if(t->st==NULL)
        t->st=a;
    else   
    {
        b=getLastNode(t);
        b->next=a;
    }
}  

void addBeg(SLIST *t,int d)
{
    NODE *a=createNode(d);
    a->next=t->st;
    t->st=a;
}

void display(SLIST *t)
{
    NODE *a=t->st;
    while(a!=NULL)
    {
        printf("%4d",a->data);
        a=a->next;
    }
}

int count(SLIST *t)
{
	int cnt=0;
    NODE *a=t->st;
    while(a!=NULL)
    {
        cnt++;
        a=a->next;
    }
    return cnt;
}

int sum(SLIST *t)
{
    int tot=0;
    NODE *a=t->st;
    while(a!=NULL)
    {
        tot=tot + a->data;
        a=a->next;
    }
    return tot;
}
                 
int findMax(SLIST *t)
{
    NODE *a=t->st;
    int max=a->data;
    for(a=a->next;a!=NULL;a=a->next)
    {
        if(a->data>max)
        max=a->data;
    }
    return max;
}

int findMin(SLIST *t)
{
    NODE*a=t->st;
    int min=a->data;
    for(a=a->next;a!=NULL;a=a->next)
    {
        if(a->data<min)
            min=a->data;
    }
    return min;
}

NODE *search(SLIST *t,int sv)
{
    NODE*a=t->st;
    while(a!=NULL)
    {
        if(a->data==sv)
            break;
        a=a->next;
    }
    return a;
}
 
void findAndReplace(SLIST*t,int sv,int rv)
{
    NODE*a=t->st;
    while(a!=NULL)
    {
        if(a->data==sv)
            a->data=rv;
            a=a->next;
    }
    return;
}
     
void copyList(SLIST*d,SLIST*s)
{   
    NODE*a=d->st,*b;
    NODE*c=s->st;
    if(s->st==NULL)
    	return;
    if(d->st!=NULL)
        init(d);
    while(c!=NULL)
    {
    	b=createNode(c->data);
        if(d->st==NULL)
            d->st=b;
        else
            a->next=b;
        a=b;
        c=c->next;
    }
}
         
void appendList(SLIST *d,SLIST*s)
{   
    NODE*a=d->st,*b;
    NODE*c=s->st;
    if(s->st==NULL)
        return;
    if(d->st!=NULL){
    while(a->next!=NULL)
    {
        a=a->next;
    }
    }     
    while(c!=NULL)
    {
        b=createNode(c->data);
        if(d->st==NULL)
            d->st=b;
        else
        	a->next=b;
        a=b;
        c=c->next;
    }
}

int main()
{
    SLIST p;
    init(&p);
    int opt,d,a,b;
    while(1)
    {
        printf("\nSingle Linked List:\n");
        printf("\nMenu\n1.Add at end\n2.Add at beg\n3.Display\n4.Count\n5.Sum\n6.Find Max\n7.Find Min\n8.Search\n9.Find And Replace\n10.Exit\nopt:");
        scanf("%d",&opt);
        if(opt==10)
            break;
        switch(opt)
        {
            case 1:
                printf("Enter data:");
                scanf("%d",&d);
                addEnd(&p,d);
                break;
            case 2:
                printf("Enter data:");
                scanf("%d",&d);
                addBeg(&p,d);
                break;
            case 3:
                if(p.st==NULL)
                    printf("List is Empty!!");
                else
                    display(&p);
                break;
            case 4:
                printf("No. of Elements:%d",count(&p));
                break;
            case 5:
                printf("Data sum:%d",sum(&p));
                break;
            case 6:
                b=findMax(&p);
                printf("max value:%d",b);
                break;
            case 7:
                b=findMin(&p);
                printf(" min value:%d",b);
                break;     
            case 8:
                printf("enter value to search");
                scanf("%d",&a);
                if(search(&p,a)==NULL)
                   	printf("not found");
                else
                   	printf(" found");
                break;
            case 9:
                printf("enter search value");
                scanf("%d",&a);
                printf("enter replace value");
                scanf("%d",&b);
                findAndReplace(&p,a,b);
                break;
        	default:
        		printf("\nInvalid Choice...Re-enter!!!!!!!!!!!");
        		break;        
		}
	}
	return 0;
}                                                
                                                       
                                                    
            
                 
