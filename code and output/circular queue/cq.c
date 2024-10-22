#include <stdio.h>
#include <stdlib.h>
#define size 4

int ch, cq[20], ele, i;
int rear = -1, front=-1;


void insert();
int delete();
void display();

int main(){
    int ch;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.diplay\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: insert(); break;
            case 2: ele = delete();
            if (ele!=-1){printf("Deleted element is %d\n", ele);}
            break;
            case 3: display(); break;
            case 4: exit(0);

        }
    }
}

void insert(){
    if ((rear+1)%size==front){
        printf("Circular queue is full!!\n");
        return;
        }
    if ((front==-1)&&(rear==-1)){
        front = rear = 0;
    }
    else{
        rear = ((rear+1)%size);
    }
    printf("Enter element to be inerted: ");
    scanf("%d", &ele);
    cq[rear]= ele ;
    return;
}

int delete(){
    if ((front==-1)&&(rear==-1)){
        printf("Circular queue is empty!!\n");
        return(-1);
        }
    int ele = cq [front];
    if (front == rear){
        front =-1; rear=-1;
    }
        else{
front =(front +1)%size;
        }
        return (ele);
    
}

void display() {

    if (front == -1) {
        printf("Queue is empty!!\n");
        return;
    }
    printf("Circular queue content:\n");
    int i = front;

    while (1) {
        printf("%d ", cq[i]); 
        if (i == rear) break; 
        i = (i + 1) % size; 
    }
    printf("\n"); 
}
