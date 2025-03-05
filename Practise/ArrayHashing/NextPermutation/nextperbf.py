from typing import List

def nextPermutation(nums : List[int], temp : List[int], permutations : List[List[int]], visited : List[bool]) -> None :
    # Stopping condition : 
    if(len(nums) == len(temp)):
        permutations.append(temp[:])
        return
    
    
    for i in range(0,len(nums)):
        
        if (visited[i] == False):
            
            # Make a choice : 
            temp.append(nums[i])
            visited[i] = True
            
            # Recurse
            nextPermutation(nums,temp,permutations,visited)
            
            # Redo a choice
            temp.remove(nums[i])
            visited[i] = False
            
def genNextPermutation(nums : List[int]) -> List[int] :
    temp : List[int] = []
    permutations : List[List[int]] = []
    visited : List[bool]
    result : List[int] = []
    
    visited = [False for _ in range(len(nums))]
    
    nextPermutation(nums,temp,permutations,visited)
    
    permutations.sort()
    
    # print(permutations)
    for i in range(len(permutations)):
        if((nums == permutations[i]) and i < len(permutations) - 1):
            result = permutations[i+1][:]
            break
        elif ((nums == permutations[i]) and i == len(permutations) - 1):
            result = permutations[0][:]
    
    return result

def main():
    # some : List[int] = [1,2,3,4]
    # some : List[int] = [1,2,4,3]
    some : List[int] = [4,3,2,1]
    
    result : List[int] = genNextPermutation(some)
    
    print(result)
    
if __name__ == "__main__":
    main()
    
    
    