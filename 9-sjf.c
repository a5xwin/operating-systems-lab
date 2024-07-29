#include <stdio.h>
typedef struct{
    int pid,at,bt,ct,wt,tat,completed;        
} Process;

int main(){
    int n,pt=0,completed=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    Process p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter arrival time for process %d: ",p[i].pid);
        scanf("%d",&p[i].at);
        printf("Enter burst time for process %d: ",p[i].pid);
        scanf("%d",&p[i].bt);
        p[i].completed = 0;
    }
    printf("PID AT BT CT TAT WT\n");
    while(completed<n){
        int idx = -1; //keeps track of p with the smallest bt that is ready to execute.
        int minbt = __INT_MAX__;

        for(int i=0;i<n;i++){
            if(!p[i].completed && p[i].at <= pt && p[i].bt< minbt){
                minbt=p[i].bt;
                idx = i;
            }
        }
        
        if(idx!=-1){
            pt += p[idx].bt;
            p[idx].ct = pt;
            p[idx].tat = p[idx].ct-p[idx].at;
            p[idx].wt = p[idx].tat-p[idx].bt;
            p[idx].completed = 1;
            completed++;

            printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[idx].pid,p[idx].at,p[idx].bt,p[idx].ct,p[idx].tat,p[idx].wt);
        } 
        else{
            pt++; // Increment time if no process is available to execute
        }
    }
    
    float avgwt=0.0;
    float avgtat=0.0;
    
    for(int i=0;i<n;i++){
        avgwt+=p[i].wt;
        avgtat+=p[i].tat;
    }
    
    printf("Average waiting time = %d\n",avgwt/n);
    printf("Average turnaround time = %d\n",avgtat/n);
    return 0;
}