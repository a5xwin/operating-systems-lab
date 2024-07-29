#include <stdio.h>
typedef struct{
    int pid,at,bt,ct,wt,tat,prio;        
} Process;

void swap(Process *a,Process *b){
    Process temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n,pt=0; //pt=present time
    printf("Enter the total number of processes: ");
    scanf("%d",&n);
    Process p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter Arrival time of p%d: ",i+1);
        scanf("%d",&p[i].at);
        printf("Enter Burst time of p%d: ",i+1);
        scanf("%d",&p[i].bt);
        printf("Enter Priority of p%d: ",i+1);
        scanf("%d",&p[i].prio);
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].prio<p[j+1].prio){
                swap(&p[j],&p[j+1]);
            }
        }
    }
    
    printf("PID AT BT CT TAT WT\n");
    for(int i=0;i<n;i++){
        if (pt<p[i].at){
            pt=p[i].at;
        }
        pt += p[i].bt;
        p[i].ct= pt;
        p[i].tat= p[i].ct-p[i].at;
        p[i].wt= p[i].tat-p[i].bt;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    float avgwt = 0.0;
    float avgtat = 0.0;

    for(int i=0;i<n;i++){
        avgwt += p[i].wt;
        avgtat += p[i].tat;
    }
    printf("\nAverage Waiting Time = %f\n", avgwt / n);
    printf("Average Turnaround Time = %f\n", avgtat / n);
    return 0;
}