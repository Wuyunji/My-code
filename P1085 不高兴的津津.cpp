#include <stdio.h>

int main(void)
{
	int i,maxi,max,a[7][3];
	for(i=0;i<7;i++)
	{
		scanf("%d %d",&a[i][0],&a[i][1]);
		a[i][2]=a[i][0]+a[i][1];
	}
	max=a[0][2];
	maxi=0;
	for(i=1;i<7;i++)
	{
		if(a[i][2]>=8)
		{
			if(a[i][2]>max)
			{
				max=a[i][2];
				maxi=i+1;
			}
		}
	}
	printf("%d",maxi);
	return 0;
}
