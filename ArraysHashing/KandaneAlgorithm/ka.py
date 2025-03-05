from typing import List
import sys
def maxSubarraySum(arr : List[int]) -> int:
    max_sum : int = -sys.maxsize - 1
    current_sum : int = 0
    
    start : int = 0
    end : int 
    temp : int = 0
    for i in range(len(arr)):   
        current_sum += arr[i]
        if current_sum <= 0 : 
            temp = i + 1
            current_sum = 0
        if current_sum > max_sum: 
            max_sum = current_sum
            start = temp
            end = i
    
    print("The subarray is: [", end="")
    for i in range(start, end + 1):
        print(arr[i], end=" ")
    print("]") 
    
    return max_sum  


arr : List[int]= [-2, 1, -3, 4, -1, 2, 1, -5, 4]
maxSum : int = maxSubarraySum(arr)
print("The maximum subarray sum is:", maxSum)
