#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermuation(vector<int> &nums,vector<int> &temp,vector<vector<int>> &permutations,vector<bool> &visited)
{
    //Stopping condition
    if(temp.size() == nums.size())
    {
        permutations.push_back(temp);
        return;
    }

    // Traverse the decision space 
    for(int i = 0; i < nums.size(); i++)
    {
        // Traverse if not traversed 
        if(!visited[i])
        {
            // Make a choice
            temp.push_back(nums[i]);
            visited[i] = true;

            //Recurse
            nextPermuation(nums, temp, permutations, visited);

            //undo the choice
            temp.pop_back();
            visited[i] = false;
        }
    }

}

vector<int> genNextPermutation(vector<int> &nums)
{
    vector<int> temp;
    vector<bool> visited;
    for (int i = 0; i < nums.size();i++)
    {
        visited.push_back(false);
    }
    vector<vector<int>> permutations;

    vector<int> result;

    nextPermuation(nums, temp, permutations, visited);

    sort(permutations.begin(), permutations.end());

    for (int i = 0; i < permutations.size();i++)
    {
        if((nums == permutations[i]) && i < permutations.size() - 1)
        {
            result = permutations[i + 1];
            break;
        }
        else if((nums == permutations[i]) && i == permutations.size() - 1)
        {
            result = permutations[0];
        }
        return result;
    }
}

int main()
{
    // vector<int> some = {1, 2, 3, 4};
    // vector<int> some = {1,2,4,3};
    vector<int> some = {4,3,2,1};

    vector<int> result;
    result = genNextPermutation(some);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}