#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return {seen[complement], i};  // Return indices
            }
            seen[nums[i]] = i;  // Store current value and index
        }

        return {}; // No match found
    }
};

int main() {
    Solution sol;
    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter target value: ";
    cin >> target;

    vector<int> result = sol.twoSum(nums, target);

    if (result.empty()) {
        cout << "No pair found that adds up to the target.\n";
    } else {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
        cout << "Values: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    }

    return 0;
}
