    #include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> two_sum(const std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> num_map; // Hash map to store {target - num: index}

    for (int i = 0; i < nums.size(); ++i)
    {
        if (num_map.find(nums[i]) != num_map.end())
        {                                 // Check if the current number exists in the map
            return {num_map[nums[i]], i}; // Return the indices
        }
        num_map[target - nums[i]] = i; // Store the difference and index
    }

    return {}; // No solution found
}

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = two_sum(nums, target);
    std::cout << "Indices of the two numbers: [" << result[0] << ", " << result[1] << "]\n";

    return 0;
}
