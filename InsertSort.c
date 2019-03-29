#include <stdio.h>

void InsertSort(int *a, int length){
    for(int i=1; i<length; i++){
        int ins=a[i];
        for(int j=i-1; j>=0; j--){
            if(ins<a[j]){
                a[j+1]=a[j];
                if(j==0){
                    a[0]=ins;
                }
            }else{
                a[j+1]=ins;
                break;
            }
        }
    }
}

int main(int argc, char **argv){
    int a[8] = {3,1,5,7,2,4,9,6};  
    InsertSort(a,8);  
    for(int i=0; i<8; i++){
        printf("%d", a[i]);
    }

    return 0;
}
