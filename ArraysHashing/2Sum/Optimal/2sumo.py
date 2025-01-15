from typing import List,Tuple,Dict

def two_sum_all_pairs(nums : List[int],target : int) -> List[Tuple[int,int]] :
    map : Dict[int,int] = {}
    result : List[Tuple[int,int]] = []
    
    for num in nums:
        complement : int = target - num
        
        if complement in map and map[complement] > 0:
            result.append((complement,num))
            map[complement] -= 1
        else:
            map[num] = map.get(num,0) + 1
    
    return result

nums: List[int] = [2,7,11,15,2,7,3,8]
target :int = 9
result : List[Tuple[int,int]] = two_sum_all_pairs(nums,target)

if result:
    print("Found pairs : ")
    for pair in result:
        print(f"({pair[0]},{pair[1]})")

else:
    print("No pairs found")