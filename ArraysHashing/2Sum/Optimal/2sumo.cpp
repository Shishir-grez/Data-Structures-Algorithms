#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int,int>> twoSum(vector<int>& array,int result)
{
    unordered_map<int,int> map;
    vector<pair<int,int>> pairs;
    int complement = 0;

    for(int i = 0; i < array.size(); i++)
    {
        complement = result - array[i];

    // map[complement] > 0 ensures that in case of duplicates pairing is handled properly

        if(map.find(complement) != map.end() && map[complement] > 0)
        {
            pairs.push_back({complement,array[i]});
            map[complement] --;
        }
        else
        {
        map[array[i]]++;
        }
    }

    return pairs;
}

int main()
{
    vector<int> array = {2,7,11,15,2,7,3,8};
    int target = 9;

    vector<pair<int,int>> result = twoSum(array,target);

    if(!result.empty())
    {
        cout << "Pairs found : " << endl;
        for(const auto& p:result)
        {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    }
    else{
        cout << "No pairs found." << endl;
    }

    return 0;
}