from typing import List,Dict

def twoSum(arr : List[int],target : int)->List[List[int]]:
    hash_map : Dict[int,int] = {}
    return_list : List[List[int]] = []
    
    for i in range(len(arr)):
        hash_map[target-arr[i]] = i # a + b = c, to find a we store c - b
        
        if arr[i] in hash_map:
            return_list.append([hash_map[arr[i]],i]) # return indices , hash_map[a/ c-b],i
    
    if(len(return_list) == 0):
        return[[-1,-1]]
    else:
        return return_list   

def main():
    # arr = [2, 7, 11, 15, 5 , 4, 8]
    arr = [11, 15, 8]
    target = 9
    result = twoSum(arr, target)
    
    if result == [[-1, -1]]:
        print("No valid pairs found.")
    else:
        print("Pairs that sum to the target:")
        for pair in result:
            print(f"Indices: {pair[0]} and {pair[1]}, Values: {arr[pair[0]]} + {arr[pair[1]]} = {target}")

if __name__ == "__main__":
    main()
