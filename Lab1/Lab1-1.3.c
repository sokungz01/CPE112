#include <stdio.h>
int main(){
    int mark[20][5],ans=0;
    for(int i=0;i<20;i++){
        int sum=0;
        for(int j=0;j<5;j++){
            scanf("%d",&mark[i][j]);
            sum+=mark[i][j];
        }
        sum/=5;
        if(sum<50) ans++;
    }
    printf("%d",ans);
    return 0;
}
