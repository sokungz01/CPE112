#include<stdio.h>
int main(){
    int i,j,n,sum=0;
    scanf("%d",&n);
    int arr[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            if(i == j) sum+=arr[i][j];
        }
    }
    printf("%d",sum);
}