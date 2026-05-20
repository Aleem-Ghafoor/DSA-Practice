#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int totalFruit(vector<int>& f) {
    unordered_map<int, int> b; 
    int a = 0, r = 0, l = 0;    
    int s = 0;                  

    while (r < f.size()) {
        b[f[r]]++; 
        s++;

        while (b.size() > 2) {
            b[f[l]]--;
            s--;
            if (b[f[l]] == 0)
                b.erase(f[l]);
            l++;
        }

        if (s > a) a = s;

        r++;
    }

    return a;
}

int main() {
    vector<int> f = {1, 2, 1};  
    int n = totalFruit(f);
    cout << "The max fruits are: " << n << endl;
    return 0;
}
