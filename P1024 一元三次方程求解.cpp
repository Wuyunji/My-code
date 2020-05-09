#include <stdio.h>

#define f(i) (((a*(i)+b)*(i)+c)*(i)+d)

int main(void)
{
	double a,b,c,d,i,x1,x2,r,l;
	int cnt=0;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	for(i=-100;i<100;i++)
	{
		x1=f(i);
		x2=f(i+1);
		if(!x1)
		{
			printf("%.2lf ",i);
			cnt++;
		}
		else if(x1*x2<0)
		{
			l=i;
			r=i+1;
			while(r-l>0.001)
			{
				if(f((r+l)/2)*f(r)<0)
					l=(r+l)/2;
				else if(f((r+l)/2)*f(r)>0)
					r=(r+l)/2;
				else
					break; 
			}
			printf("%.2lf ",l);
			cnt++;
		}
		if(!(cnt-3))
			break;
	}
	return 0;
} 
