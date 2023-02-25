#include <stdio.h>
int main()
{
    int array[100][100];
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&array[i][j]);
        }
    }
    int Right=m,Down=n,Left=0,Up=0;
    while(Left < Right && Up < Down){

        for(int i=Left;i<Right;i++){
            printf("%d ",array[Up][i]);
        }
        Up++;

        for(int i=Up;i<Down;i++){
            printf("%d ",array[i][Right-1]);
        }
        Right--;

        if(Up < Down){
            for(int i=Right-1;i>=Left ;i--){
                printf("%d ",array[Down-1][i]);
            }
            Down--;
        }
        if(Left < Right){
            for(int i=Down-1;i>=Up;i--){
                printf("%d ",array[i][Left]);
            }
            Left++;
        }
    }
    return 0;
}