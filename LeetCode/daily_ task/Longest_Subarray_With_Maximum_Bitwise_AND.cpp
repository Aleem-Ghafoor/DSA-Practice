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
            }
            else{
                if(count > 0){
                    maxcount.push_back(count);
                    count = 0;
                }
            }
        }

        if (count > 0) {
            maxcount.push_back(count);
        }

        return maxcount.empty() ? 0 : *max_element(maxcount.begin(), maxcount.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4};
    
    int result = sol.longestSubarray(nums);
    cout << "\nLongest subarray length with maximum bitwise AND: " << result << endl;

    return 0;
}
