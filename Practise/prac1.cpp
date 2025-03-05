#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums, int start, vector<vector<int>>& permutations)
{
    if (start == nums.size() - 1) //
    {
        permutations.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++)
    {
        swap(nums[i], nums[start]);
        nextPermutation(nums, start + 1, permutations);
        swap(nums[i], nums[start]);
    }
}

void generatePermutation(vector<int>& nums)
{
    vector<vector<int>> permutations;
    nextPermutation(nums, 0, permutations);

    
}