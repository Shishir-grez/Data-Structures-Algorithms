from typing import List, Tuple

def two_sum_all_pairs(nums: List[int], target: int) -> List[Tuple[int, int]]:
    result: List[Tuple[int, int]] = [] 
    
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                result.append((nums[i], nums[j]))  
    
    return result  


nums: List[int] = [2, 7, 11, 15, 2, 7, 3, 8]
target: int = 9
result: List[Tuple[int, int]] = two_sum_all_pairs(nums, target)

if result:
    print("Pairs found:")
    for pair in result:
        print(f"({pair[0]}, {pair[1]})")
else:
    print("No pairs found.")
