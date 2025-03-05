from typing import List
import sys
def maxSumSubarray(arr : List[int])->int:
    max_sum : int = -sys.maxsize
    current_sum : int = 0
    
    start : int = 0
    temp : int = 0
    end : int = 0
    
    for i in range(len(arr))    :
        current_sum += arr[i]
        
        if current_sum <= 0:
            current_sum = 0
            temp = i + 1
        
        if current_sum > max_sum:
            max_sum = current_sum
            start = temp
            end = i
    print(f"Print the subarray : [{arr[start:end+1]}]")
    return max_sum       

arr : List[int]= [-2, 1, -3, 4, -1, 2, 1, -5, 4]
maxSum : int = maxSumSubarray(arr)
print("The maximum subarray sum is:", maxSum)