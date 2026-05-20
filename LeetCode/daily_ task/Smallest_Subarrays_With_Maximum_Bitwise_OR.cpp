#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {

        vector<int> result; 
        int a, b, count; 

        for(int i = 0; i < nums.size(); i++){
            a = 0;
            b = 0;
            count = 0;
            for(int j = i; j < nums.size(); j++){
                a |= nums[j];
            }

            for(int k = i; k < nums.size(); k++){
                if(a == 0){
                    result.push_back(1);
                }
                if(a == b) break;
                b |= nums[k];
                count++;
            }
            if(a != 0)
            result.push_back(count);
          }
        return result;
  }
};

int main() {
    Solution sol;
    vector<int> nums = {0};

    vector<int> result = sol.smallestSubarrays(nums);

    cout << "\nResult: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
