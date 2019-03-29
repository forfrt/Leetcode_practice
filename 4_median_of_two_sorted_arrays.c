#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int *nums1B=nums1, *nums2B=nums2;
    int *nums1E=nums1+nums1Size-1;
    int *nums2E=nums2+nums2Size-1;
    int *curB=NULL, *curE=NULL;


    for(int i=nums1Size+nums2Size; i>0; i-=2) {
        if((nums1B==nums1+nums1Size) || (nums2B!=nums2+nums2Size && *nums1B>*nums2B)) {
            curB=nums2B++;
            printf("B is nums2's %d\n", *curB);
        } else {
            curB=nums1B++;
            printf("B is nums1's %d\n", *curB);
        }

        if((nums1E==nums1-1) || (nums2E!=nums2-1 && *nums2E>*nums1E)) {
            curE=nums2E--;
            printf("E is nums2's %d\n", *curE);
        } else {
            curE=nums1E--;
            printf("E is nums1's %d\n", *curE);
        }

    }

    return (*curB+*curE)/2.0;
}

int main(int argc, char **argv) {
    int nums1[2]= {1, 3};
    int nums2[1]= {2};
    printf("The median is: %f\n", findMedianSortedArrays(nums1, 2, nums2, 1));

    int nums3[]= {1, 2};
    int nums4[]= {3, 4};
    printf("The median is: %f\n", findMedianSortedArrays(nums3, 2, nums4, 2));
}
