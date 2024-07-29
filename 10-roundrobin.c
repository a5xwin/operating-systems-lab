#include <stdio.h>
#include <stdlib.h>

struct process{
    int pid,at,bt,tempbt,ct,tat,wt,completed;
}temp,cp;
int front=-1,rear=-1;
struct process queue[100];

void sort(struct process p[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

void enqueue(struct process p){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[front]=p;
    } 
    else{
        rear++;
        queue[rear]=p;
    }
}

struct process dequeue(){
    struct process toReturn = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return toReturn;
}

int isEmpty(){
    return front==-1 && rear==-1;
}

int isInqueue(struct process p){
    int tempf=front, flag=0;
    while (tempf!=rear){
        if(queue[tempf].pid==p.pid){
            flag=1;
            break;
        }
        tempf++;
    }
    if(flag==0 && queue[tempf].pid == p.pid){
        flag=1;
    }
    return flag;
}

void calculate_tat_wt(struct process p[100],int n){
    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
}

void display(struct process p[], int n) {
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    int tot_tat=0,tot_wt=0;
    for(int i=0;i<n;i++){
        tot_tat+=p[i].tat;
        tot_wt+=p[i].wt;
    }
    float avg_tat = (float) tot_tat / n;
    float avg_wt = (float) tot_wt / n;
    printf("\nThe average Turnaround Time (TAT) is %f", avg_tat);
    printf("\nThe average Waiting Time (WT) is %f", avg_wt);
    printf("\n");
}

void rr(struct process p[100],int n,int tq){
    int currentct=0;
    enqueue(p[0]);
    int i=1;
    while(isEmpty()==0){
        cp = dequeue();
        if(cp.tempbt <= tq){
            currentct += cp.tempbt;
            cp.tempbt = 0;
            cp.ct = currentct;
            cp.completed = 1;
        } 
        else{
            cp.tempbt -= tq;
            currentct += tq;
            while(i<n && p[i].at <= currentct && p[i].completed == 0){
                if(isInqueue(p[i]) == 0){
                    enqueue(p[i]);
                }
                i++;
            }
            enqueue(cp);
        }
        for(int j=0;j<n;j++){
            if(p[j].pid == cp.pid){
                p[j] = cp;
                break;
            }
        }
    }
    calculate_tat_wt(p, n);
    display(p, n);
}

int main(){
    int n, tq;
    struct process p[100];
    printf("Enter the time quantum: ");
    scanf("%d",&tq);
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter pid: ");
        scanf("%d",&p[i].pid);
        printf("Enter arrival time: ");
        scanf("%d",&p[i].at);
        printf("Enter burst time: ");
        scanf("%d",&p[i].bt);
        p[i].tempbt=p[i].bt;
        p[i].completed=0;
    }
    
    sort(p,n);
    rr(p,n,tq);
    
    return 0;
}