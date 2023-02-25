#include <stdio.h>
#include <math.h>

int main(void) {
  double sum[5] = {0,0,0,0,0};
  int marks[20][5];
  int i,j;
  double average[5];
  int floatPoint[5];
  for(i = 0; i < 20; i++){
    for(j = 0; j < 5; j++){
      scanf("%d",&marks[i][j]);
      sum[j] += marks[i][j];
    }
  }

  for(i = 0; i < 5; i++){
    average[i] = sum[i]/20 ;
    floatPoint[i] = (int)(average[i] * 100)%100;
    printf("%d",(int)floor(average[i]));
        if(floatPoint[i] != 0 && floatPoint[i] %10 != 0){
            printf(".%d",floatPoint[i]);
        }
        else if(floatPoint[i] != 0 && floatPoint[i] %10 == 0){
             printf(".%d",floatPoint[i]/10);
        }
        printf("\n");
  }
  return 0;
}