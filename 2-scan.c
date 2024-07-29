#include<stdio.h>
#include<stdlib.h>

int main(){
    int head,n,sum=0,tot,smallest;
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
    smallest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            smallest=arr[i];
        }
    }
    sum+=abs((tot-1)-head);
    sum+=abs(smallest-(tot-1));
    printf("Total seek time: %d",sum);
    return 0;
}