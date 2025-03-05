import sys
from typing import List

def errprint(*args,**kwargs)->None:
    print(*args,**kwargs,file=sys.stderr)
    
def majority_element(arr : List[int])-> List[int]:
    element1 :int = arr[0]
    skip : int
    for i in range(1,len(arr)):
        errprint(f"Values of element1, current_element : {element1},{arr[i]}")
        if arr[i] == element1:
            continue
        element2 : int = arr[i]
        skip = i
        break  
    count1 : int = 1
    count2 : int = 1
    
    for i in range(2,len(arr)):
        errprint(f"\nLoop {i}")
        errprint(f"\tValues of element1,count1,element2,count2 : {element1},{count1},{element2},{count2}")
        
        if i == skip: 
            errprint(f"Skipping here, value of i, skip : {i}, {skip}")
            continue
        
        if count1 == 0 and arr[i] != element2:
            element1 = arr[i]
            count1 += 1
            continue
        
        if count2 == 0 and arr[i] != element1:
            element2 = arr[i]
            count2 += 1
            continue
        
        if arr[i] == element1:
            count1 += 1
            continue
        
        if arr[i] == element2:
            count2 += 1
            continue
        
        if arr[i] != element1 and arr[i] != element2:
            count1 -= 1
            count2 -= 1
            
    errprint(f"\nFinal Values : ")
    errprint(f"\tValues of element1,count1,element2,count2 : {element1},{count1},{element2},{count2}")  
    
    errprint(f"\nManually checking values")  
    # manually check is values are majority element : 
    count1, count2 = 0, 0
    for i in range(len(arr)):
        if arr[i] == element1:
            count1 += 1
        if arr[i] == element2:
            count2 += 1
    errprint(f"\tFinal Counter element1, element2 : {count1}, {count2}")
    majority : int = int(len(arr)/3) + 1
    
    return_list : List[int] = []
    
    if count1 >= majority:
        return_list.append(element1)
        
    if count2 >= majority:
        return_list.append(element2) 
    
    return return_list   

def main():
    with open("error_log.txt","w") as error_log:
        sys.stderr = error_log
        
        # arr : List[int] = [11, 33, 33, 11, 33, 11]
        arr: List[int] = [1, 1, 1, 3, 3, 2, 2, 2, 1, 4]

        # Call the majority_element function
        result : List[int] = majority_element(arr)
        
        # Print the result of the majority element to stderr (error_log.txt)
        print(f"Majority Elements: {result}")
        
if __name__ == "__main__":
    main()
        
    
    