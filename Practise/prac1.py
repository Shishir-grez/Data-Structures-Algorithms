from typing import List

def nextPermutation(nums : List[int]) -> None:
    i : int = len(nums) - 2
    n : int = len(nums)
    
    while (i >= 0 and nums[i] >= nums[i+1]):
        i -= 1
    
    if i >= 0:
        swap : int = n - 1
        
        while(nums[i] >= nums[swap]):
            swap -= 1
        
        nums[i],nums[swap] = nums[swap],nums[i]
        
    nums[i+1:].reverse()

    if i == -1 :
       nums.sort() 

nums : List[int] = [3,2,1]
nextPermutation(nums)
print(nums)