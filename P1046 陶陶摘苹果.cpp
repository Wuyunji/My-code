#include <stdio.h>

int main(void)
{
	int a[10],i,h,cnt=0;
	for(i=0; i<10; i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&h);
	for(i=0; i<10; i++)
	{
		if(a[i]<=h+30)
			cnt++;
	}
	printf("%d",cnt);
	return 0;
}
