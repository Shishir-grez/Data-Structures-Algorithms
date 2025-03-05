from typing import List
from copy import deepcopy
import sys

def errprint(*args,**kwargs):
    print(*args,**kwargs,file=sys.stderr)

def nextPermutation(arr: List[int])-> List[int]:
    piv : int
    index : int = len(arr) - 2
    
    while(arr[index] > arr[index + 1]) and index > 0:
        index -= 1
    
    if index == 0:
        result : List[int] = deepcopy(arr)
        result.sort()
        errprint(f"Value of arr,result : {arr}, {result}")
        return result
    
    errprint(f"Value of arr,piv is {arr}, {index}")
    
    piv = index
    
    index = len(arr) - 1
    
    while(arr[piv] > arr[index]):
        index -= 1
        
    result : List[int] = deepcopy(arr)
    
    errprint(f"\tValue of piv,swap_to_element is {piv}, {index}")
    
    result[piv],result[index] = result[index],result[piv]
    
    errprint(f"\n\t\t Value after swapping is {result}")
    
    result[piv+1:] = reversed(result[piv+1:])
    
    errprint(f"\t\t Value after reversing after piv : {result}")
    
    return result
    
def main() -> None:
    with open("optimized_err.txt","w") as error_log:
        sys.stderr = error_log
        arr : List[int] = [1,2,3,4]
        # arr : List[int] = [1,2,4,3]
        # arr : List[int] = [4,3,2,1]
        
        result : List[int] = nextPermutation(arr)
        print(f"Next permutation for {arr} is {result}")

if __name__ == "__main__":
    main()
    
    