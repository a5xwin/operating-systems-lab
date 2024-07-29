#include <stdio.h>
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
    int p[np], ff[np];  //fitfound;
    
    /*ff[i] = -1 means process p[i] has not been allocated to any memory block.
    ff[i] !=-1 means process p[i] has been allocated to memory block at index ff[i]*/
    
    for(int i=0;i<np;i++){
        printf("Enter size of process %d: ",i+1);
        scanf("%d",&p[i]);
        ff[i]=-1; // initially all processes are not allocated
    }
    
    for(int i=0;i<np;i++){
        int bestidx = -1;   
        int lowest = -1;    //CHANGED
        
        for(int j=0;j<nb;j++){
            if(b[j]>=p[i]){
                int temp=b[j]-p[i];
                if(temp>lowest){    //CHANGED
                    lowest=temp;
                    bestidx=j;
                }
            }
        }
        
        if(bestidx!= -1){
            ff[i]=bestidx;
            b[bestidx]=0;
        }
    }
    
    for(int i=0;i<np;i++){
        if(ff[i]!=-1){
            printf("Process %d allocated to block %d\n",i+1,ff[i]+1);
        } 
        else{
            printf("Process %d not allocated to any block\n",i+1);
        }
    }
    return 0;
}