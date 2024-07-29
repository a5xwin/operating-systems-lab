#include<stdio.h>
#include<stdlib.h>

int main(){
    int head,n,sum=0;
    
    printf("Enter head track location: ");
    scanf("%d",&head);
    
    printf("Enter size of queue request: ");
    scanf("%d",&n);
    
    int arr[n];
    
    for(int i=0;i<n;i++){
        printf("Enter location of track %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    sum+=abs(head-arr[0]);
    
    for(int i=0;i<n-1;i++){
        sum+=abs(arr[i]-arr[i+1]);
    }

    printf("Total seek time: %d",sum);
    return 0;
}