#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int totalSubsets = 1 << n; 
        int maxOR = 0;
        int count = 0;

        for (int mask = 1; mask < totalSubsets; ++mask) {
            int currentOR = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    currentOR |= nums[i];
                }
            }

            if (currentOR > maxOR) {
                maxOR = currentOR;
                count = 1;
            } else if (currentOR == maxOR) {
                count++;
            }
        }

        return count;
    }
};

// Main function
int main() {
    Solution sol;

    vector<int> nums = {1,2,3};

    int result = sol.countMaxOrSubsets(nums);
    cout << "Number of subsets with maximum OR: " << result << endl;

    return 0;
}
