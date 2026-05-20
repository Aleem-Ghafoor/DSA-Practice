#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        
        int a, i, z;
        unordered_map<int, int> count;
        i = 0;
        a = 0;
        z = 0;

        while(i < arr.size()){

            a |= arr[i];
            count[a]++;
            if(i == (arr.size()-1)){
                a = 0;
                i = z++;
            }
            i++;
        }

          return count.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,4};
    
    int result = sol.subarrayBitwiseORs(nums);
    cout << "\nBitwise ORs of subarray: " << result << endl;

    return 0;
}
