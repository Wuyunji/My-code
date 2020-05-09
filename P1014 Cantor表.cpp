#include <stdio.h>

int main(void)
{
	int i,n,f1=1,f2=3,f;
	scanf("%d",&n);
	
	for(i=1;;i++)
	{
		if(n>=f1&&n<=f2)
		{
			if((i+1)%2==0)
			{
				if(n==f1)
					printf("%d/1",i);
				else
					printf("%d/%d",n-f1,i+2-(n-f1));
			}
			else
			{
				if(n==f2)
					printf("1/%d",i+1);
				else
					printf("%d/%d",i+2-(n-f1),n-f1);
			}
			break;
		}
		f=2*f2-f1+1;
		f1=f2;
		f2=f;
	}
	
	return 0;
}
