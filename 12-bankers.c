#include<stdio.h>
int main(){
    int n;
    printf("Enter total number of processes: ");
    scanf("%d",&n);
    
    int available[3];
    printf("Enter available value for each resource type (3 values): ");
    for(int i=0;i<3;i++) {
        scanf("%d",&available[i]);
    }
    
    int allocation[n][3];
    int max[n][3];
    int need[n][3];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            printf("Enter allocation value of resource %d for process %d: ",j+1,i+1);
            scanf("%d", &allocation[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            printf("Enter max value of resource %d for process %d: ",j+1,i+1);
            scanf("%d",&max[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    
    int finish[n];
    for(int i = 0; i<n;i++){
        finish[i] = 0;
    }
    
    int safeseq[n];
    int count=0,found=0;
   
    for(int k=0;k<n;k++){
        found=0;
        for(int i=0;i<n;i++){
            if(finish[i]==0){
                int safe=1;
                for(int j=0;j<3;j++){
                    if(need[i][j]>available[j]){
                        safe=0;
                        break;
                    }
                }

                if(safe){
                    for(int j=0;j<3;j++){
                        available[j] += allocation[i][j];
                    }

                    safeseq[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(!found){
            break; // No safe sequence found
        }
    }
    
    if(count<n){
        printf("No safe state!\n");
    } 
    else{
        printf("System is in a safe state. Safe sequence: ");
        for(int i=0;i<n;i++){
            printf("%d ",safeseq[i]);
        }
        printf("\n");
    }
    
    return 0;
}
