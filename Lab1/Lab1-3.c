#include <stdio.h>
#include <stdlib.h>
int main(){
    int arrSize,i,j,temp_val=0;
    scanf("%d",&arrSize);
    int *arr = calloc(arrSize,sizeof(int));
    int *sort = calloc(arrSize,sizeof(int));
    for(i = 0 ; i < arrSize ; i++){
        scanf("%d",&arr[i]);
        sort[i] = arr[i];
    }
    //Ascending sort
    for (i = 0; i < arrSize; i++) { 
        for (j = i + 1; j < arrSize; j++) { 
            if (*(sort + i) > *(sort + j)) { 
                temp_val = *(sort + i); 
                *(sort + i) = *(sort + j); 
                *(sort + j) = temp_val; 
            } 
        } 
    } 
    arr[1] = sort[arrSize-2];
    arr[arrSize-2] = sort[1];
    for(i = 0 ; i < arrSize ; i ++){
        printf("%d ",sort[i]);
    }
    free(arr);
    free(sort);
    return 0;
}