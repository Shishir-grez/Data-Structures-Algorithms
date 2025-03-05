from typing import List
from copy import deepcopy
import sys

def threeSum(arr : List[int])->List[List[int]]:
    return_list : List[List[int]] = []
    print("Size of return_list ideal : 0, actual : ",len(return_list),file=sys.stderr)
    
    temp_arr = deepcopy(arr)
    print("If temp_arr and arr are equal, ideal : True, actual : ",(arr == temp_arr),file=sys.stderr)
    
    piv : int
    left : int
    right : int
    
    temp_arr.sort() # O(NLogN)
    # Might also check here using for loop ? 
    print("Array : ",temp_arr,file=sys.stderr)
    for i in range(len(temp_arr)):
        piv = i
        if piv == 0:
            left = 1
        else:
            left = 0
        if piv == (len(temp_arr) - 1):
            right = (len(temp_arr) - 2)
        else:
            right = (len(temp_arr) - 1)
            
        print(f"Loop No : {i}",file=sys.stderr)
        print(f"\t piv,left,right (Indices): {piv},{left},{right}",file=sys.stderr)
        
        while(right > left):
            temp_sum : int = temp_arr[i] + temp_arr[left] + temp_arr[right]
            
            print(f"\t\t sum of piv,left,right (Indices) : {piv},{left},{right} is {temp_sum}",file=sys.stderr)
            
            if temp_sum == 0:
                append_list : List[int] = [piv,left,right] 
                # prevent duplicates
                # sort to prevent duplicates 
                append_list.sort()
                print(f"\t\t\t value of append_list[sum = 0]",append_list,file=sys.stderr)
                if append_list in return_list:
                    print("\t\t\t Duplicate! Skip!",file=sys.stderr)
                    break
                else:
                    return_list.append(append_list)
                    break
            
            if temp_sum < 0:
                left = left + 1
                if (left == piv):
                    left += 1
                continue
            
            if temp_sum > 0:
                right = right - 1
                if(right == piv):
                    right -= 1
                continue
    
    return return_list          
      
error_file = open('error_log.txt', 'w')  # Open the error log file for writing
sys.stderr = error_file  # Redirect stderr to the error file
  
arr : List[int] = [-1, 0, 1, 2, -1, -4]
ans : List[List[int]] = threeSum(arr)

for it in ans:
    print("[", end="")
    for i in it:
        print(i, end=" ")
    print("]", end=" ")
print()
error_file.close()
    