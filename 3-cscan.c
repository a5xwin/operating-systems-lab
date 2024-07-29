#include<stdio.h>
#include<stdlib.h>
int main(){
    int head,n,sum=0,tot,sth;   //sth=smaller than head (value just smaller to head)
    printf("Enter head location: ");
    scanf("%d",&head);
    printf("Enter size of queue: ");
    scanf("%d",&n);
    printf("Enter total number of tracks: ");
    scanf("%d",&tot);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter location of track %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    sth=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>sth && arr[i]<head){
            sth=arr[i];
        }
    }
    
    sum+=abs((tot-1)-head);
    sum+=(tot-1);
    sum+=sth;
    printf("Total seek time: %d",sum);
    return 0;
}