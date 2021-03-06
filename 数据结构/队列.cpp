//
//  队列.cpp
//  数据结构
//
//  Created by Xuchu on 15/12/22.
//  Copyright © 2015年 Xuchu. All rights reserved.
//

# include <stdlib.h>
# include <stdio.h>

typedef struct Queue
{
    int * pBase;
    int front;
    int rear;
}QUEUE;

void init(QUEUE *);
bool en_queue(QUEUE *,int val);
void traverse_queue(QUEUE *);
bool full_queue(QUEUE *);
bool out_queue(QUEUE *,int * pVal);
bool empty_queue(QUEUE * pQ);
bool out_queue(QUEUE * pQ,int * pVal);
int main(void)
{
    QUEUE Q;
    int val;
    
    init(&Q);
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    en_queue(&Q, 6);
    en_queue(&Q, 7);
    traverse_queue(&Q);
    out_queue(&Q, &val);
    out_queue(&Q, &val);
    traverse_queue(&Q);
    return 0;
}

void init(QUEUE *pQ)
{
    pQ->pBase=(int *)malloc(sizeof(int)*6);
    pQ->front=0;
    pQ->rear=0;
}

bool en_queue(QUEUE * pQ,int val)
{
    if (full_queue(pQ)) {
        return false;
    }
    else
    {
        pQ->pBase[pQ->rear]=val;
        pQ->rear=((pQ->rear+1)%6);
        return true;
    }
}

bool full_queue(QUEUE * pQ)
{
    if ((pQ->rear+1)%6==pQ->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void traverse_queue(QUEUE * pQ)
{
    int i=(pQ->front)%6;
    while (i!=pQ->rear)
    {
        printf("%d  ",pQ->pBase[i]);
        i=(i+1)%6;
    }
    printf("\n");
    return;
//    for (i=pQ->front; i<=pQ->rear; i++)   不能这样写
//    {
//        printf("%d\n",pQ->pBase[i]);
//    }
}
bool empty_queue(QUEUE * pQ)
{
    if (pQ->front==pQ->rear) {
        return true;
    }
    else
        return false;
}
bool out_queue(QUEUE * pQ,int * pVal)
{
    if(empty_queue(pQ))
    {
        return false;
    }
    else
    {
        *pVal=pQ->pBase[pQ->front];
        pQ->front=(pQ->front+1)%6;
        printf("出队元素%d\n",*pVal);
        return true;
    }
}