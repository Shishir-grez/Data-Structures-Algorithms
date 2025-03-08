import sys
from typing import List

def errprint(*args,**kwargs)->None:
    print(*args,**kwargs,file=sys.stderr)
    
def ksum(arr : List[int],target : int) -> int:
    count : int = 0
    left : int = 0
    right : int = 0
    ksumxor : int = 0
    while (left <= len(arr) - 1) and (right <= len(arr) - 1):
        if left == right:
            ksum = 0
            errprint(f"Value of left , right : {left} {right}")
            ksum ^= arr[left]
            errprint(f"\tValue of sum : {ksum}")
            
        else:
            errprint(f"Value of left , right : {left} {right}")
            ksum ^= arr[right]
            errprint(f"\tValue of sum : {ksum}")
            
        if ksum == target:
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
            
        elif (right == len(arr) - 1):
            if(left == len(arr) - 1):
                break
            else:
                left += 1
                right = left
        else:
            if(left == len(arr) - 1):
                break
            else:
                right += 1
            
    return count

def main() -> None:
    with open("error_kcode.txt","w") as error_file:
        sys.stderr = error_file
        arr : List[int] = [4, 2, 2, 6, 4]
        target : int = 6
        count : int = ksum(arr,target)
        print(f"No of subarrays of sum {target} in {arr} are {count}")

if __name__ == "__main__":
    main()
    