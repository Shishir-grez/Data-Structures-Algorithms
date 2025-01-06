from typing import List

def nextPermutation(nums: List[int], permutations: List[List[int]], temp: List[int], visited: List[bool]) -> None:
    if len(temp) == len(nums):  # Solution
        permutations.append(temp[:])  # Add a copy of temp to permutations
        return

    for i in range(len(nums)):  # To Choose From
        if not visited[i]:  # Constraint
            temp.append(nums[i])  # Make a choice
            visited[i] = True
            nextPermutation(nums, permutations, temp, visited)
            visited[i] = False  # Undo the choice
            temp.pop()

def main() -> None:
    nums: List[int] = [4, 3, 2, 1]
    permutations: List[List[int]] = []
    temp: List[int] = []
    visited: List[bool] = [False, False, False, False]

    nextPermutation(nums, permutations, temp, visited)

    permutations.sort()

    found: bool = False

    for i in range(len(permutations)):
        if permutations[i] == nums and i + 1 < len(permutations):
            nums = permutations[i + 1]
            found = True
            break

    if not found:
        nums = permutations[0]

    print(*nums)

if __name__ == "__main__":
    main()
