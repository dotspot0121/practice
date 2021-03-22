#include <stdio.h>
#define LEN 100005

typedef struct pp{
  char name[100];
  int t;
}P;

P Q[LEN];
int head, tail, n;

void enqueue(P x){
    if(isFull()){
        //error
    }else if(tail+1==LEN){
        tail=0;
    }
    Q[tail]=x;
    tail++;
}

P dequeue(){
    P x;
    if(isEmpty()){
        //error
    }else if(head+1==LEN){
        head=0;
    }
    x=Q[head];
    ++head;
    return x;
}

void initialize(){
    head = tail = 0;
}

int isEmpty(){
    return head == tail;
}

int isFull(){
    return head == (tail+1)%LEN;
}


int main(){
    int elaps = 0, c;
    int i, q;
    P u;
  
    //input
    scanf("%d %d", &n, &q);

    for ( i = 1; i <= n; i++){
        scanf("%s", Q[i].name);
        scanf("%d", &Q[i].t);
    }
  
    //process & output
    while(isEmpty()!=0){
        if(Q[head].t<=q){
            u=dequeue();
            elaps+=u.t;
            printf("%s %d\n",u.name,elaps);
        }else{
            u=dequeue();
            u.t-=q;
            enqueue(u);
            elaps+=q;
        }
    }

  
    return 0;
}
