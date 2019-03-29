import os
import sys

class Solution(object):
    def twoSum(self, nums, target):
        if len(nums)<=1:
            return False
        buff_dict={}

        for i in range(len(nums)):
            if nums[i] in buff_dict:
                return [buff_dict[nums[i]], i+1]
            else:
                buff_dict[target-nums[i]]=i+1

def main(argv):
    nums=[1, 3, 6, 8, 14, 19, 20, 23, 25]
    target=23

    solution=Solution()
    res=solution.twoSum(nums, target)

    for i in res:
        print i

if __name__=='__main__':
    reload(sys)
    sys.setdefaultencoding('utf-8')
    main(sys.argv)

