/*
**��ͷ�ڵ����� 
*/

typedef char ElemType;
typedef struct QNode
{
	ElemType data;
	struct QNode *next;
}QNode;

typedef struct 
{
	QNode *front;
	QNode *rear;
}LinkQueue;

void InitQueue(LinkQueue *s);//��ʼ������ 
void EnterQueue(LinkQueue *s, ElemType a);//����� 
int OutQueue(LinkQueue *s, ElemType *a);//������ 
int LenQueue(LinkQueue *s);//���ض��еĽ����� 
int GetFront(LinkQueue *s, ElemType *a);////ȡ����Ԫ��
int EmptyQueue(LinkQueue *s);//�ж϶����Ƿ�Ϊ�� 
void DestroyQueue(LinkQueue *s);//��������

void InitQueue(LinkQueue *s)
{//��ʼ������ 
	s->front=(QNode *)malloc(sizeof(QNode));
	s->rear=s->front=NULL;
}

void EnterQueue(LinkQueue *s, ElemType a)
{//����� 
	QNode *p; 
	p=(QNode *)malloc(sizeof(QNode));
	p->data=a;
	p->next=NULL;
	if(EmptyQueue(s))
	{
		s->front=s->rear=p;
	}
	else
	{
		s->rear->next=p;
		s->rear=p;
	}
}

int OutQueue(LinkQueue *s, ElemType *a)
{//������ 
	QNode *p;
	if(EmptyQueue(s))
	{
		return 0;
	}
	p=s->front;
	if(s->front==s->rear)
	{	
		s->front=s->rear=NULL;
	}
	else
	{
		s->front=s->front->next;
	}
	*a=p->data;
	free(p);
	return 1;
}

int LenQueue(LinkQueue *s)
{//���ض��еĽ����� 
	int len=1;
	QNode *q=s->front; 
	if(EmptyQueue(s))
		return 0;
	if(s->front==s->rear)
		return 1;
	while(q->next!=NULL)
	{
		len++;
		q=q->next;
	}
	return len;
}

void DestroyQueue(LinkQueue *s)
{//���ٶ��� 
	QNode *temp;
	while(!EmptyQueue(s))
	{
		temp=s->front->next;
		free(s->front);
		s->front=temp;
	}
}

int GetFront(LinkQueue *s, ElemType *a)
{//ȡ����Ԫ�� 
	if(EmptyQueue(s))
	{
		return 0;
	}
	*a=s->rear->data;
	return 1;
}

int EmptyQueue(LinkQueue *s)
{//�ж϶����Ƿ�Ϊ�� 
	return(s->rear==NULL); 
}

