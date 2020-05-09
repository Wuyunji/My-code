#include <stdio.h>

int main(void)
{
	int i,j,l,m,cnt=0;
	scanf("%d %d",&l,&m);
	int a[l+1],b[m][2];
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&b[i][0],&b[i][1]);
	}
	for(i=0;i<l+1;i++)
	{
		a[i]=1;
	}
	for(i=0;i<m;i++)
	{
		for(j=b[i][0];j<=b[i][1];j++)
		{
			a[j]=0;
		} 
	}
	for(i=0;i<l+1;i++)
	{
		if(a[i])
			cnt++;
	}
	printf("%d",cnt);
}
