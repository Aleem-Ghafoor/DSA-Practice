#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    void find(vector<vector<int>>& fruits, int& sum, int startRow, int startCol, vector<pair<int, int>> directions, bool& pin) {
    int i = startRow;
    int j = startCol;
    int n = fruits.size();
    sum += fruits[i][j]; 

    while (true) {
        vector<tuple<int, int, int>> options;

        for (auto [di, dj] : directions) {
            int newI = i + di;
            int newJ = j + dj;

            if (newI >= 0 && newI < n && newJ >= 0 && newJ < n) {
                options.push_back({fruits[newI][newJ], newI, newJ});
            }
        }

        if (options.empty()) break;

        auto [val, newI, newJ] = *max_element(options.begin(), options.end());
        if (newI == fruits.size() - 1 && newJ == fruits[0].size() - 1) {
          cout << pin;
          if (pin) {
            sum += val;
            pin = false;
          }
        } 
        else 
            sum += val;

          cout << endl << sum << endl;

        i = newI;
        j = newJ;
    }
  }


     int maxCollectedFruits(vector<vector<int>>& fruits) {
        int sum1 = 0, sum2 = 0, sum3 = 0;
        bool pin = true;

        find(fruits, sum1, 0, 0, { {1, 1}, {1, 0}, {0, 1} }, pin);   
        find(fruits, sum2, 0, fruits.size()-1, { {1, -1}, {1, 0}, {1, 1} }, pin);    
        find(fruits, sum3, fruits.size()-1, 0, { {-1, 1}, {0, 1}, {1, 1} }, pin); 

        return sum1 + sum2 + sum3;
    }
};

int main() {
   
    Solution sol;
    vector<vector<int>> fruits = {  
                                    {1,2,3,4},
                                    {5,6,7,8},
                                    {9,10,11,12},
                                    {13,14,15,16}
                                  }; 
    int maxFruits = sol.maxCollectedFruits(fruits);

    cout << "Maximum number of fruits: " << maxFruits << endl;
    return 0;
}
