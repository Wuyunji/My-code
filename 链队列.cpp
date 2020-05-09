/*
**无头节点链队 
*/
#include <stdio.h>
#include <stdlib.h>
#include "E:\作业\C程序题\INCLUDE\Queue.h"

int main(void)
{
	LinkQueue s;
	ElemType a;
	int len,i;
	
	InitQueue(&s);//初始化队列 
	
	scanf("%c", &a);
	while(a!='#')
	{
		EnterQueue(&s, a);
		scanf("%c", &a);
	}
	
	len = LenQueue(&s);
	for(i=0; i<len; i++)
	{
		if(OutQueue(&s, &a))
		printf("%c", a);
	}
	
	DestroyQueue(&s);
	
	return 0;
}

