import sys
from typing import List

def errprint(*args,**kwargs)->None:
    print(*args,**kwargs,file=sys.stderr)
    
def ksum(arr : List[int],target : int) -> int:
    count : int = 0
    left : int = 0
    right : int = 0
    ksum : int = 0
    while (left <= len(arr) - 1) and (right <= len(arr) - 1):
        if left == right:
            errprint(f"Value of left , right : {left} {right}")
            ksum = arr[left]
            errprint(f"\tValue of sum : {ksum}")
            
        else:
            errprint(f"Value of left , right : {left} {right}")
            ksum += arr[right]
            errprint(f"\tValue of sum : {ksum}")
            
        if ksum > target:
            if(left == len(arr) - 1):
                break
            left += 1
            right = left
            
        elif ksum == target:
            errprint(f"\n\t\tValue of left, right, sum when updating count : {left},{right},{ksum}")
            count += 1
            if(right == len(arr) - 1):
                if(left == len(arr) - 1):
                    break
                else:
                    left += 1
            
                    right = left
            else:
                right += 1
            
        else:
            if(right == len(arr) - 1):
                if(left == len(arr) - 1):
                    break
                else:
                    left += 1
                    right = left
            else:
                right += 1
            
    return count

def main() -> None:
    with open("error_code.txt","w") as error_file:
        sys.stderr = error_file
        # arr : List[int] = [3, 1, 2, 4]
        arr : List[int] = [-1, 2, 3, -2, 1]
        target : int = 5
        # target : int = 6
        count : int = ksum(arr,target)
        print(f"No of subarrays of sum {target} in {arr} are {count}")

if __name__ == "__main__":
    main()
    