//CIRCULAR QUEUE
#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int size;
    int front;
    int rear;
    int *Q;
}queue;
void create(queue*q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int*)malloc(q->size*sizeof(int));
}
void enqueue(queue*q,int value){
    if((q->rear+1)%q->size==q->front){
        printf("Overflow\n");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=value;
    }
}
int dequeue(queue*q){
    int value=-1;
    if(q->rear==q->front){
        printf("Underflow\n");
       // exit(1);
    }
    else{
        //q->front++;
        q->front=(q->front+1)%q->size;
        value=q->Q[q->front];
        q->Q[q->front] = -1;
    }
    return value;
}
void display(queue *q){
    int i=q->front+1;
    do{
        printf("%d ",q->Q[i]);
        i=(i+1)%q->size;
    }while(i!=(q->rear+1)%q->size);
    printf("\n");
}
int main(){
   struct queue* q;
   q=malloc(sizeof(queue));
   int value;
   int i;
   create(q,6);
   for(i=1;i<=5;i++){
   printf("Enter the %d element: ",i);
   scanf("%d",&value);
     enqueue(q,value);
   }
   printf("queue is: ");
   display(q);
   printf("Deleted element: ");
   printf("%d ",dequeue(q));
   return 0;
}
