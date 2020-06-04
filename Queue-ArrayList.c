#include <stdio.h>

// 数组型连续队列

struct queue{
    int data[100];  // 队列主体
    int head;
    int tail;
}queue;

int main(){
    struct queue q;
    int i;

    // 初始化队列
    q.head = 1;
    q.tail = 1;
    for(i=1;i<9;i++){
        // 依次向队列插入9个数
        scanf("%d",&q.data[tail++]); // 形成队尾插入元素的形式
    }

    while(q.head<q.tail){
        // 打印队首并将队首出队
        printf("%d",q[head++]);

        // 先将新队首的数添加到队尾
        q.data[q.tail]= q.data[q.head];
        q.tail++;
        再将队首元素出队
        q.head++;
    }

    getchar();getchar();
    return 0;
}