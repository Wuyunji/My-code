#include <stdio.h>

int main(void)
{
	int n,i;
	scanf("%d",&n);
	for(i=2;i<=n/2;i++)
	{
		if(!(n%i))
		{
			printf("%d",n/i);
			return 0;
		}
	}
}
