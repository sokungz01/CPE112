#include<stdio.h>
#include<math.h>
int main(){
    int i,j;
    int MAKRS[20][5];
    double student_avg_score[20];
    int student_floating_point[20];

    for(i = 0 ; i < 20 ; i++){
        student_avg_score[i] = 0;
        for(j=0; j < 5; j++){
            scanf("%d",&MAKRS[i][j]);
            student_avg_score[i] += MAKRS[i][j];
        }
        student_avg_score[i] /= 5;
        student_floating_point[i] = student_avg_score[i]*100;
        student_floating_point[i] %= 100;
    }
    
    for(i = 0 ; i < 20 ; i ++){
        printf("%d",(int)floor(student_avg_score[i]));
        if(student_floating_point[i] != 0 && student_floating_point[i] %10 != 0){
            printf(".%d",student_floating_point[i]);
        }
        else if(student_floating_point[i] != 0 && student_floating_point[i] %10 == 0){
             printf(".%d",student_floating_point[i]/10);
        }
        printf("\n");
    }
}