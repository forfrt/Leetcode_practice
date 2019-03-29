#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target) {
    for(int i=0; i<numsSize && *(nums+i)<target; i++) {
        for(int j=0; j<i; j++) {
            if(*(nums+j)+*(nums+i)==target) {
                int *res=(int *)malloc(sizeof(int)*2);
                *res=j;
                *(res+1)=i;
                return res;
            }
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    int nums[4]= {2, 7, 11, 15};
    int target=13;

    int *res=twoSum(nums, 4, target);

    if(res) {
        for(int i=0; i<sizeof(res)/sizeof(res[0]); i++) {
            printf("%d", *(res+i));
        }
    }

    return 0;

}
