#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

  vector<vector<int>> generate(int numRows) {
        
    vector<vector<int>> result;
    vector<int> num = {1}; 

      for(int i = 0; i < numRows; i++){
        result.push_back(num);
        vector<int> sum;
        sum.push_back(1);
        for(int j = 0; j < i; j++)
            sum.push_back(num[j]+num[j+1]);
        sum.push_back(1);
        num = sum;
      }
      return result;
  }

};

int main() {
    Solution sol;
    int nums = 6;
    vector<vector<int>> result;
    
   result = sol.generate(nums);

   for (const auto& row : result) {
          for (int val : row) {
            cout << val << " ";
          }
          cout << endl;
        }
    return 0;
}
