#include <iostream>
#include <vector>
using namespace std;

int maxSumSubArray(const vector<int> & arr)
{
    int max_sum = -999;
    int current_sum = 0;
    int start = -1;
    int end = -1;
    int temp = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        current_sum += arr[i];

        if(current_sum <= 0)
        {
            temp = i + 1;
            current_sum = 0;
        }

        if(current_sum > max_sum)
        {
            max_sum = current_sum;
            start = temp;
            end = i;
        }
    }
    cout << "Maximum subarray : ";
    for (int i = start; i <= end; i ++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Max sum is : " << max_sum << endl;
    return max_sum;
    
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_sum = maxSumSubArray(arr);
    return 0;
}