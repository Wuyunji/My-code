#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef char ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
	int front;
	int rear; 
}CqQueue;

void InitQueue(CqQueue **s);//初始化队列 
int EnterQueue(CqQueue *s,ElemType e);//进队 
int OutQueue(CqQueue *s, ElemType *e);//出队 
int GetQueue(CqQueue *s,ElemType *e);//取队首元素
int EmptyQueue(CqQueue *s);//判断队列是否为空 
int LenQueue(CqQueue *s);//计算队列中的元素 
void DestroyQueue(CqQueue *s);//销毁队列 

int main(void)
{
	CqQueue *s;
	ElemType e;
	int len,i;
	
	InitQueue(&s);
	
	scanf("%c",&e);
	while(e!='#')
	{
		if(!EnterQueue(s,e))
		{
			printf("队满"); 
			system("pause");
		}
		scanf("%c",&e);
	}
	
	len=LenQueue(s);
	
	for(i=0;i<len;i++)
	{
		if(EmptyQueue(s))
		{
			printf("队空");
			system("pause"); 
		}
		OutQueue(s,&e);
		printf("%c",e);
	}
	
	DestroyQueue(s);
	
	return 0;
}

void InitQueue(CqQueue **s)
{//初始化队列 
	*s=(CqQueue *)malloc(sizeof(CqQueue));
	(*s)->front=(*s)->rear=-1;
}

int EnterQueue(CqQueue *s,ElemType e)
{//进队 
	if((s->rear+1)%MAXSIZE==s->front)
	{
		return 0;
	}
	if(EmptyQueue(s))
	{
		s->front=s->rear=0;
	}
	s->rear=(s->rear+1)%MAXSIZE;
	s->data[s->rear]=e;
	return 1;
}

int OutQueue(CqQueue *s, ElemType *e)
{//出队 
	if(EmptyQueue(s))
	{
		return 0;
	}
	s->front=(s->front+1)%MAXSIZE;
	*e=s->data[s->front];
	return 1;
}

int GetQueue(CqQueue *s,ElemType *e)
{//取队首元素 
	if(EmptyQueue(s))
	{
		return 0;
	}
	*e=s->data[s->front];
}

int EmptyQueue(CqQueue *s)
{//判断队列是否为空 
	return(s->rear==s->front);
}

void DestroyQueue(CqQueue *s)
{//销毁队列 
	free(s);
}

int LenQueue(CqQueue *s)
{//计算队列中的元素 
	return (s->rear+MAXSIZE-s->front)%MAXSIZE;
}

	
	
