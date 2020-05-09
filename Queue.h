/*
**无头节点链队 
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

void InitQueue(LinkQueue *s);//初始化队列 
void EnterQueue(LinkQueue *s, ElemType a);//入队列 
int OutQueue(LinkQueue *s, ElemType *a);//出队列 
int LenQueue(LinkQueue *s);//返回队列的结点个数 
int GetFront(LinkQueue *s, ElemType *a);////取队首元素
int EmptyQueue(LinkQueue *s);//判断队列是否为空 
void DestroyQueue(LinkQueue *s);//销毁链队

void InitQueue(LinkQueue *s)
{//初始化队列 
	s->front=(QNode *)malloc(sizeof(QNode));
	s->rear=s->front=NULL;
}

void EnterQueue(LinkQueue *s, ElemType a)
{//入队列 
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
{//出队列 
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
{//返回队列的结点个数 
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
{//销毁队列 
	QNode *temp;
	while(!EmptyQueue(s))
	{
		temp=s->front->next;
		free(s->front);
		s->front=temp;
	}
}

int GetFront(LinkQueue *s, ElemType *a)
{//取队首元素 
	if(EmptyQueue(s))
	{
		return 0;
	}
	*a=s->rear->data;
	return 1;
}

int EmptyQueue(LinkQueue *s)
{//判断队列是否为空 
	return(s->rear==NULL); 
}

