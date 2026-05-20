#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Function to display a linked list
void display(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// You can implement this later
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        vector<ListNode*> temp;
        int a = 0, listcount = 0;

        for(auto l: lists){
          if(l == NULL) continue;
          temp.push_back(l);
          listcount++;
        }

        if(listcount == 1) return temp[0];
        if(listcount == 0) return NULL;

// merge remaning          
        for(int i = 1; i < listcount; i++){

            ListNode* current = temp[0]; 

            ListNode* l2 = temp[i];

            ListNode* dummy = new ListNode();
            ListNode* merged = dummy;

          while(current != NULL && l2 != NULL){

            if(l2->val >= current->val){

                merged->next = current;
                current = current->next;

            }
            else if(l2->val <= current->val){ 
                   
                merged->next = l2;
                l2 = l2->next;
            }

               merged = merged->next;

          }
             
            if(l2 != NULL){
              merged->next = l2;
            }
            if(current != NULL){
              merged->next = current;
            }

            temp[0] = dummy->next;
        }

        return temp[0];
    }
};

int main() {
    // Sample input: [[1,4,5], [1,3,4], [2,6]]
    vector<vector<int>> listValues = {
        {-1, 1},
        {-3, 1, 4},
        {-2, -2, 8},
        {-2, 77, 90},
        {-88, -22, 0, 1}
    };

    // Convert each vector<int> to ListNode*
    vector<ListNode*> lists;
    for (const auto& vals : listValues) {
        lists.push_back(createList(vals));
    }

    // Display all individual lists
    cout << "Input Linked Lists:" << endl;
    for (auto l : lists) {
        display(l);
    }

    // Merge all k lists
    Solution sol;
    ListNode* mergedHead = sol.mergeKLists(lists);

    // Display result
    cout << "\nMerged Linked List:" << endl;
    display(mergedHead);

    return 0;
}
