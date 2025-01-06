from typing import List

def nextPermutation(nums: List[int]) -> None:
    n : int = len(nums)
    i : int = n - 2

    # Step 1: Find the pivot
    while i >= 0 and nums[i] >= nums[i + 1]:
        i -= 1

    if i >= 0:
        # Step 2: Find rightmost successor and swap
        j : int = n - 1
        while nums[j] <= nums[i]:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]

    # Step 3: Reverse the suffix
    nums[i + 1:] = reversed(nums[i + 1:])

    # If no pivot was found, it means we have the last permutation
    # Reset the array to the first permutation (sorted order)
    if i == -1:
        nums.sort()

# Example usage
nums: List[int] = [3, 2, 1]
nextPermutation(nums)


# Output the next permutation
print(nums)  # Output: [1, 2, 3]
