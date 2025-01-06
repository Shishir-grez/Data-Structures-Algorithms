#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int> &nums)
{
    int n = nums.size(), i = n - 2;

    // Step 1: Find the pivot
    while (i >= 0 && nums[i] >= nums[i + 1]) // Start from n - 2 to -1 , -1 is descending order
        i--;

    if (i >= 0) 
    {
        // Step 2: Find rightmost successor and swap
        int j = n - 1;
        while (nums[j] <= nums[i]) // Start from n - 1 to some index in the array
            j--;
        std::swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the suffix
    std::reverse(nums.begin() + i + 1, nums.end()); // swap the rest after pivot 

    // If no pivot was found, it means we have the last permutation
    // Reset the array to the first permutation (sorted order)
    if (i == -1)
    {
        std::sort(nums.begin(), nums.end());
    }
}

int main()
{
    std::vector<int> nums = {3, 2, 1};
    nextPermutation(nums);

    // Output the next permutation
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    return 0;
}
