#include <stdio.h>
#include <string.h>

typedef struct{
    char name[20];
    int sb;   // sb = starting block
    int nob;  // nob = number of blocks
} File;

int main(){
    int n;
    printf("Enter number of files: ");
    scanf("%d",&n);

    File f[n];
    for(int i=0;i<n;i++){
        printf("Enter file name %d: ",i+1);
        scanf("%s",f[i].name);
        printf("Enter starting block of file %d: ",i+1);
        scanf("%d",&f[i].sb);
        printf("Enter number of blocks in file %d: ",i+1);
        scanf("%d",&f[i].nob);
    }
    
    char s[20];
    int found=0;

    printf("Enter the file name to be searched: ");
    scanf("%s",s);

    for(int i=0;i<n;i++){
        if(strcmp(f[i].name,s)== 0){
            found=1;
            printf("\nNAME\tSB\tNOB\tBLOCKS OCCUPIED\n");
            printf("%s\t%d\t%d\t", f[i].name, f[i].sb, f[i].nob);
            for(int j=0;j<f[i].nob;j++){
                printf("%d ",f[i].sb+j);
            }
            printf("\n");
            break;
        }
    }
    
    if(found==0) {
        printf("File Not Found\n");
    }
    return 0;
}