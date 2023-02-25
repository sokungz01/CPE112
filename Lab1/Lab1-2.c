#include <stdio.h>
int main(){
    int array[100][100],even[100],odd[100],NumEven=0,NumOdd=0;
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           scanf("%d",&array[i][j]);
           if(array[i][j]%2==0){
            even[NumEven] = array[i][j];
            NumEven++;
           }
           else{
            odd[NumOdd] = array[i][j];
            NumOdd++;
           }
        }
    }
    if(NumOdd == 0) printf("None");
    for(int i=0;i<NumOdd;i++){
        printf("%d ",odd[i]);
    }
    printf("\n");
    if(NumEven == 0) printf("None");
    for(int i=0;i<NumEven;i++){
        printf("%d ",even[i]);
    }
    return 0;
}
