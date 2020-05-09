#include <stdio.h>

int main(void)
{
	int n,i,j,t;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>=a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			for(j=i;j<n;j++)
			{
				a[j]=a[j+1];
			}
			n--;
			i--;
		}
	}
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}

	return 0;
}
