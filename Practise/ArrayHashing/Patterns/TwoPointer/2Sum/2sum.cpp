#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> two_sum(const vector<int>& arr,int target)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < arr.size() ; i++)
    {
        // Stopping condition / answer
        if(umap.find(arr[i]) != umap.end())
        {
            return {umap[arr[i]], i};
        }

        umap[target - arr[i]] = i;
    }

    // No answer
    return {};
}

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = two_sum(nums, target);
    std::cout << "Indices of the two numbers: [" << result[0] << ", " << result[1] << "]\n";

    return 0;
}

