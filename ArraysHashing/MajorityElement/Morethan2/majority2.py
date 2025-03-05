import sys
from typing import List

def errprint(*args, **kwargs) -> None:
    print(*args, **kwargs, file=sys.stderr)

def majority_element(arr: List[int]) -> int:
    # Voting method
    count: int = 1
    element: int = arr[0]

    for i in range(1, len(arr)):
        errprint(f"\nLoop {i}")
        errprint(f"\t Value of count, element : {count}, {element}.")

        if count == 0:
            element = arr[i]

        if element == arr[i]:
            count += 1
        else:
            count -= 1
    errprint(f"\nManually checking value")
    
    majority : int = int(len(arr) / 2)
    errprint(f"\t Majority count : {majority}")
    
    count = 0
    
    for i in range(len(arr)):
        if arr[i] == element:
            count += 1
            
    errprint(f"\t Counter of element : {count}")
    
    if count >= majority:
        return element

def main():
    # Open error_log.txt in write mode
    with open('error_log.txt', 'w') as error_log:
        sys.stderr = error_log
        
        # Test input array
        arr = [3, 3, 4, 2, 4, 4, 2, 4, 4]
        
        # Print majority element to stderr through errprint function
        result = majority_element(arr)
        print(f"Majority Element: {result}")

if __name__ == "__main__":
    main()
