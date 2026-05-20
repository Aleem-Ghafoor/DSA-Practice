#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
      int maxVal, count = 0;
      vector<int> maxcount;
        maxVal = *max_element(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){

            if(maxVal == nums[i]){
                count++;
                if(nums[i+1] != maxVal){
                    maxcount.push_back(count);
                    count = 0;
                    continue;
                }
            }
        }
        maxVal = *max_element(maxcount.begin(), maxcount.end())

        return maxVal;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 3, 2};
    
    int result = sol.longestSubarray(nums);
    cout << "Longest subarray length with maximum bitwise AND: " << result << endl;

    return 0;
}
