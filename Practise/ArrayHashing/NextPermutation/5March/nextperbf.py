from typing import List
import sys

def errprint(*args,**kwargs)->None:
    print(*args,**kwargs,file=sys.stderr)

def nextPermutation(arr : List[int],permutations: List[List[int]],visited: List[bool],temp : List[int])->None:
    
    if len(temp) == len(arr):
        errprint(f"\n\t Array to be pushed into permutations : {temp}")
        permutations.append(temp[:])
        errprint(f"\t\tPermutations array now : {permutations}")
        return
    
    for i in range(len(arr)):
        
        if visited[i] == False:
            errprint(f"Value of temp,current element (to be added) : {temp},{arr[i]}")
            temp.append(arr[i])
            visited[i] = True
            nextPermutation(arr,permutations,visited,temp)
            temp.pop()
            visited[i] = False

def generateNextPermutation(arr: List[int])->List[int]:
    permutations : List[List[int]] = []
    visited : List[bool] = [False for _ in range(len(arr))]
    temp : List[int] = []
    
    nextPermutation(arr,permutations,visited,temp)
    permutations.sort()
    
    errprint(f"\n Final Value of permutations is : {permutations}")
    
    result : List[int]
    for index,value in enumerate(permutations):
        if arr == value and index < len(permutations)-1:
            errprint(f"\n Value of arr,value,index and len(permutations) : {arr}, {value}, {index}, {len(permutations)}")
            result = permutations[index+1]
            errprint(f"\t Value of result : {result}")
            break
        elif arr == value and index == len(permutations) - 1:
            errprint(f"\n Value of arr,value,index and len(permutations) : {arr}, {value}, {index}, {len(permutations)}")
            result = permutations[0]
            errprint(f"\t Value of result : {result}")
            break
        else :
            continue
    
    return result

def main()->None:
    with open("brute_error.txt","w") as error_log: 
        sys.stderr = error_log
        # arr : List[int] = [1,2,3,4]
        # arr : List[int] = [1,2,4,3]
        arr : List[int] = [4,3,2,1]
        
        result : List[int] = generateNextPermutation(arr)
        print(f"Next permutation for {arr} is {result}")

if __name__ == "__main__":
    main()