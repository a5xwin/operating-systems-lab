#include<stdio.h>
int main(){
    int nb,np;
    
    printf("Enter total number of blocks: ");
    scanf("%d",&nb);
    int b[nb];
    for(int i=0;i<nb;i++){
        printf("Enter size of block %d: ",i+1);
        scanf("%d",&b[i]);
    }
    
    printf("Enter total number of processes: ");
    scanf("%d",&np);
    int p[np];
    for(int i=0;i<np;i++){
        printf("Enter size of process %d: ",i+1);
        scanf("%d",&p[i]);
    }
    
    for(int i=0;i<nb;i++){
        for(int j=0;j<np;j++){
            if(p[j]<=b[i]){
                printf("Process %d allocated to block %d\n",j+1,i+1);
                p[j]=10000;
                break;
            }
        }
    }
    
    for(int j=0;j<np;j++){
        if(p[j]!=10000){
            printf("Process %d not allocated to any block\n",j+1);
        }
    }
    
    return 0;
}