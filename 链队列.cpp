/*
**��ͷ�ڵ����� 
*/
#include <stdio.h>
#include <stdlib.h>
#include "E:\��ҵ\C������\INCLUDE\Queue.h"

int main(void)
{
	LinkQueue s;
	ElemType a;
	int len,i;
	
	InitQueue(&s);//��ʼ������ 
	
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

