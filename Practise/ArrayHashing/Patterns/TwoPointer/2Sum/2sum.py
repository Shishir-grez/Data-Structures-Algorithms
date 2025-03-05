from typing import List, Dict

def two_sum(arr : List[int], target : int) -> List[int]:
    num_map : Dict[int,int] = {}
    
    for i,num in enumerate(arr):
        # Ans found condition
        
        if num in num_map:
            return[num_map[num],i]
        
        num_map[target - num] = i
    
    return []
    # Ans not found    
arr : List[int] = [2,7,11,15]
target : int = 9
print(f"Indicises of two numbers : {two_sum(arr,target)}")