#include <stdio.h>
typedef struct{
    int pid,at,bt,ct,wt,tat;        
} Process;

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

    int tot_tat,tot_wt=0;
    for(int i=0;i<n;i++){
        tot_wt += p[i].wt;
        tot_tat += p[i].tat;
    }

    float avg_tat=(float) tot_tat /n;
    float avg_wt=(float) tot_wt /n;

    printf("\nAverage Waiting Time = %f\n", avg_wt);
    printf("Average Turnaround Time = %f\n", avg_tat);
    return 0;
}