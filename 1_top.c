
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int _[100001] = {0}, *index_plus_one = _ + 50000;

    for (int i = 0; i < numsSize; i++) {
        int rest = target - nums[i];

        if (index_plus_one[rest]) {
            int *ans = malloc(sizeof(int) * 2);
            ans[0] = i;
            ans[1] = index_plus_one[rest] - 1;
            return ans;
        } else
            index_plus_one[nums[i]] = i + 1;
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
