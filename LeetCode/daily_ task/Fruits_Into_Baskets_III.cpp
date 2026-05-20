#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate number of unplaced fruit types
int totalFruit(vector<int>& fruits, vector<int>& baskets) {
    
    vector<bool> used(baskets.size(), false);
    int unplaced = 0;

    for (int fruit : fruits) {
        bool placed = false;
        for (int i = 0; i < baskets.size(); ++i) {
            if (!used[i] && baskets[i] >= fruit) {
                used[i] = true;
                placed = true;
                break;
            }
        }
        if (!placed) unplaced++;
    }

    return unplaced;
}

// Main function
int main() {
    vector<int> fruits = {4 , 2, 5};
    vector<int> baskets = {3, 5, 4};

    int result = totalFruit(fruits, baskets);

    cout << "\nNumber of unplaced fruit types: " << result << endl;

    return 0;
}
