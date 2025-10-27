#define SIZE 10
#include <stdio.h>

struct CircularQueue
{
    int data[SIZE];
    int front, rear;
} CQ;

int isEmpty()
{
    return CQ.front == -1;
}
int isFUll()
{
    return (CQ.rear + 1) % SIZE == CQ.front;
}

void enqueue(int info)
{
    if (isFUll())
    {
        printf("CQueue is full\n");
        return;
    }
    if (CQ.front == -1)
        CQ.front += 1;
    CQ.rear = (CQ.rear + 1) % SIZE;
    CQ.data[CQ.rear] = info;
}
int dequeue()
{
    int item;
    if (isEmpty())
    {
        printf("\nCQueue is empty\n");
        return -1;
    }
    item = CQ.data[CQ.front];
    if (CQ.front == CQ.rear)
        CQ.front = CQ.rear = -1;
    else
        CQ.front = (CQ.front + 1) % SIZE;
    return item;
}
void traverse()
{
    if (isEmpty())
    {
        printf("CQueue is Empty\n");
        return;
    }
    printf("front=%d, rear=%d\n", CQ.front, CQ.rear);
    int i = CQ.front;
    while (i != CQ.rear)
    {
        printf("%d ", CQ.data[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d ", CQ.data[i]);
    printf("\n");
}
int main()
{
    CQ.front = CQ.rear = -1;
    int ch, info;
    do
    {
        printf("\n1.........Enqueue"
               "\n2.........Dequeue"
               "\n3.........Traverse"
               "\n4.........IsEmpty"
               "\n5.........IsFull"
               "\n6.........Exit"
               "\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter info: ");
            scanf("%d", &info);
            enqueue(info);
            break;
        case 2:
            info = dequeue();
            if (info != -1)
                printf("Removed Element: %d", info);
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("The Circular Queue is %s\n", (isEmpty() ? "This queue is empty" : "This queue is not empty"));
            break;
        case 5:
            printf("The Circular Queue is %s\n", (isFUll() ? "This queue is full" : "This queue is not full"));
            break;
        case 6:
            printf("\nThis code is executed by RIYA with Roll No. 2400320100920\n");
            break;
        default:
            printf("Invalid Choice! Try again\n");
        }
    } while (ch != 6);
}