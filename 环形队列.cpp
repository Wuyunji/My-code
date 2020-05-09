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

void InitQueue(CqQueue **s);//��ʼ������ 
int EnterQueue(CqQueue *s,ElemType e);//���� 
int OutQueue(CqQueue *s, ElemType *e);//���� 
int GetQueue(CqQueue *s,ElemType *e);//ȡ����Ԫ��
int EmptyQueue(CqQueue *s);//�ж϶����Ƿ�Ϊ�� 
int LenQueue(CqQueue *s);//��������е�Ԫ�� 
void DestroyQueue(CqQueue *s);//���ٶ��� 

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
			printf("����"); 
			system("pause");
		}
		scanf("%c",&e);
	}
	
	len=LenQueue(s);
	
	for(i=0;i<len;i++)
	{
		if(EmptyQueue(s))
		{
			printf("�ӿ�");
			system("pause"); 
		}
		OutQueue(s,&e);
		printf("%c",e);
	}
	
	DestroyQueue(s);
	
	return 0;
}

void InitQueue(CqQueue **s)
{//��ʼ������ 
	*s=(CqQueue *)malloc(sizeof(CqQueue));
	(*s)->front=(*s)->rear=-1;
}

int EnterQueue(CqQueue *s,ElemType e)
{//���� 
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
{//���� 
	if(EmptyQueue(s))
	{
		return 0;
	}
	s->front=(s->front+1)%MAXSIZE;
	*e=s->data[s->front];
	return 1;
}

int GetQueue(CqQueue *s,ElemType *e)
{//ȡ����Ԫ�� 
	if(EmptyQueue(s))
	{
		return 0;
	}
	*e=s->data[s->front];
}

int EmptyQueue(CqQueue *s)
{//�ж϶����Ƿ�Ϊ�� 
	return(s->rear==s->front);
}

void DestroyQueue(CqQueue *s)
{//���ٶ��� 
	free(s);
}

int LenQueue(CqQueue *s)
{//��������е�Ԫ�� 
	return (s->rear+MAXSIZE-s->front)%MAXSIZE;
}

	
	
