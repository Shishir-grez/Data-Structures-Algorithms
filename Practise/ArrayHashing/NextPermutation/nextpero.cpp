#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextPermutation(vector<int> &nums)
{
    int piv;
    int i = nums.size() - 1;
    vector<int> result;
    while(nums[i] > nums[i+1])
    {   
        if(i == -1)
        {
            result = nums;
            sort(result.begin(), result.end());
            return result;
        }
        i--;
    }

    piv = i;

    i = nums.size() - 1;

    while(nums[piv] > nums[i])
    {
        i--;
    }

    swap(nums[piv], nums[i]);

    result = nums;

    reverse(result.begin() + piv + 1, result.end()); // reverse instead of sort reverse in O(n) and sort is O(nlogn)

    return result;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4};
    // vector<int> nums = {1, 2, 4, 3};
    vector<int> nums = {4, 3, 2, 1};

    vector<int> result = nextPermutation(nums);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;
    return 0;
}