#include <stdio.h>
int main(){
    int n,fault=0,hit=0,a=-1,b=-1,c=-1;
    int frames[3] = {-1, -1, -1}; // Array to represent the frames
    int rear = 0; // Pointer to keep track of FIFO
    
    printf("Enter total number of pages: ");
    scanf("%d",&n);
    int arr[n];
    
    printf("Enter page sequence... ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<n;i++){
        if(arr[i]==a||arr[i]==b||arr[i]==c){
            hit++; // Page hit
        } 
        else{
            fault++; // Page fault
            frames[rear]=arr[i]; // Replace the frame using FIFO
            rear=(rear+1) % 3; // Move the rear pointer
            
            a=frames[0];
            b=frames[1];
            c=frames[2]; // Update a, b, c
        }
        // Display the current frames each time..
        printf("Frames: %d %d %d\n", frames[0], frames[1], frames[2]);
    }
    printf("Total Page Faults: %d\n", fault);
    printf("Total Page Hits: %d\n", hit);

    return 0;
}