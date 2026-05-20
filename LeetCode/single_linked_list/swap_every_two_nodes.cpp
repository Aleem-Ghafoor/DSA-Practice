#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;

    for (int i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }

    return head;
}

// Function to display the linked list
void displayList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr)
            cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

// Class with swapPairs() — you will implement this yourself
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
  
        if(head == NULL) return NULL;      
        vector<int> arr;

        ListNode* temp = head;
        int length = 0;

        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
            length++;
        }

        if(length == 1) return head;

        ListNode* newhead = new ListNode();
        ListNode* temp2 = newhead;
        int n = 0, x = 0, r = 0;

        while(true){

            n += 2;
            r++;
            if(n > length) break;

            for(int i = n-1; i >= x; i--){
                temp2->val = arr[i];
                if(r == length/2 && i == x) break;
                ListNode* newnode = new ListNode;
                temp2->next = newnode;
                temp2 = temp2->next;
            }
            x += 2;
        } 
        
        temp = head;
        int y = 0;

        while(temp != NULL){
          
            if(y == x){
               temp2->next = temp;
               break;
            }
            temp = temp->next;
            y++;
        }
        return newhead;
    }
};

int main() {
    vector<int> values = {1, 44, 66};
    ListNode* head = createList(values);

    cout << "Original List: ";
    displayList(head);

    Solution sol;
    head = sol.swapPairs(head); // You will implement this logic

    cout << "After Swapping Pairs: ";
    displayList(head);

    return 0;
}
