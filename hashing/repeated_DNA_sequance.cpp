#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        unordered_map<string, int> val;
        int n = s.size();
        vector<string> value;
        string ans;

        for(int i = 0; i < n; i++){
            if(i > 9){
                val[ans]++;
                ans.erase(ans.begin());
            }
            ans += s[i];
        }

        if(ans.size() == 10){
           val[ans]++;
        }

        int i = 0;
        for(auto l : val){
          if(l.second > 1){
              value.push_back(l.first);
          }
        }

        return value;
    }
};

int main() {
    Solution sol;

    // Test case
    string s = "AAAAAAAAAAAAAAAAA";
    vector<string> result = sol.findRepeatedDnaSequences(s);

    // Output result
    int i = 0;
    cout << "Repeated DNA sequences:\n";
    for (const string& seq : result) {
        cout << ++i << "-" << seq << endl;
    }

    return 0;
}
