#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> twoSumAllPairs(const vector<int>& nums, int target) {
    vector<pair<int, int>> result; 

    // Brute force: Check all pairs
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                result.push_back({nums[i], nums[j]}); 
            }
        }
    }
    
    return result; 
}

int main() {
    vector<int> nums = {2, 7, 11, 15, 2, 7, 3, 8};
    int target = 9;

    vector<pair<int, int>> result = twoSumAllPairs(nums, target);

    if (!result.empty()) {
        cout << "Pairs found: " << endl;
        for (const auto& p : result) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    } else {
        cout << "No pairs found." << endl;
    }

    return 0;
}
