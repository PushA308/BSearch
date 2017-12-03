#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}NODE;
typedef struct tree
{
	NODE *rt;
	NODE *parent;
	NODE *curr;
}TREE;
void init(TREE *t)
{
	t->rt=NULL;
	t->parent=t->curr=NULL;
}
NODE *createNode(int d)
{
	NODE *a=(NODE*)malloc(sizeof(NODE));
	a->data=d;
	a->left=a->right=NULL;
	return a;
}
void createBST(TREE *t)
{
	int d;
	NODE *a;
	while(1)
	{
		printf("\nEnter data");
		scanf("%d",&d);
		if(d==0)
			break;
		if(t->rt==NULL)
		{
			t->rt=createNode(d);
			continue;
		}
				a=t->rt;
				while(1)
				{
					if(d<a->data)
					{
						if(a->left==NULL)
						{
							a->left=createNode(d);
							break;
						}
						a=a->left;
					}
					else
					{
						if(a->right==NULL)
						{
							a->right=createNode(d);
							break;
						}
						a=a->right;
					}
				}
		
	}
}
void inOrder(NODE *t)
{
	if(t!=NULL)
	{
		inOrder(t->left);
		printf("%4d",t->data);
		inOrder(t->right);
	}
}
void search(TREE *t,int v)
{
	NODE *a=t->rt;
	while(a!=NULL)
	{
		if(v<a->data)
		{
			a=a->left;
		}
		else
		{
			if(v>a->data)
			{
				a=a->right;
			}
			else
			{
				printf("\nFound");
				return;
			}
		}
	}
	printf("\nNot found");
}
int main()
{
	TREE t;
	int d;
	init(&t);
	createBST(&t);
	printf("\nTREE :- ");
	inOrder(t.rt);
	while(1)
	{
		printf("\nEnter value to search : ");
		scanf("%d",&d);
		if(d==0)
			break;
		search(&t,d);
	}
	return 0;
}
