#include<stdio.h>
int main()
{
	int l,r,mid,n,sv,i;
	printf("\nEnter the number of elements ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter array data : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	i=0;
	printf("\nEnter search value : ");
	scanf("%d",&sv);
	l=0;r=n-1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(sv<mid)
		{
			r=mid-1;
		}
		else
		{
			if(mid>sv)
			{
				l=mid+1;
			}
			else
				l=r+1;
		}
	}
	if(a[mid]!=sv)
		printf("\nNot");
	printf(" Found ");
	return 0;
}
