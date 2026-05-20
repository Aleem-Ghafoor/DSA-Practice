#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> find;
        int a = 0, i = 0;
        vector<string> st;
        
        while(a < s.length()){
            if(find.count(s[a])){
                st.push_back(s.substr(i, a - i));
                i++;
                find.clear();
                a = i;      
            }
            find[s[a]]++;
            a++;
        }
                st.push_back(s.substr(i, a - i));            

        vector<int> length;
        a = 0;
        for(string s : st){
           length.push_back(s.length());
           a++;
        }
           int largest = *max_element(length.begin(), length.end());
           
        return largest;
    }
};

int main(){
 
  Solution sol;
  string s;

  cout << "\nEnter the string: ";
  cin >> s;

  int length = sol.lengthOfLongestSubstring(s);

  cout << "\nThe length of string without duplicate is: " << length << endl;

  return 0;
}