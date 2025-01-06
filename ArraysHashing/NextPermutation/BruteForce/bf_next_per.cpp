#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//  Choice
//  Constraints
//  Solution

void nextPermutation(vector<int> &nums, vector<vector<int>> &permutations, vector<int> &temp,vector<bool>& visited)
{
    if(temp.size() == nums.size()){ // Solution
        permutations.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) // To Choose From
    {
        if(visited[i] == false) // Constraint
        {
            temp.push_back(nums[i]); // Make A choice
            visited[i] = true;
            nextPermutation(nums, permutations, temp, visited);
            visited[i] = false; // Undo the choice
            temp.pop_back();
        }
    }
}

int main()
{
    vector<int> nums = {4,3,2,1};
    vector<vector<int>> permutations;
    vector<int> temp;
    vector<bool> visited = {false, false, false, false};

    nextPermutation(nums, permutations, temp, visited);

    sort(permutations.begin(), permutations.end());

    bool found = false;

    for (int i = 0; i < permutations.size(); i++)
    {
        if(permutations[i] == nums && i + 1 < permutations.size())
        {
            nums = permutations[i + 1];
            found = true;
            break;
        }
    }
    if(!found)
    {
        nums = permutations[0];
    }

    for (int i = 0; i < nums.size();i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}