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

// Create list from hardcoded values
ListNode* createList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    return head;
}

// Display the linked list
void display(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k == 1) return head;

        ListNode* temp = head;
        int a = 0, n = 0;
        vector<int> arr;

        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
            a++;
        }
        int x = 0, r = 0;
        n = 0;
        ListNode* head2 = new ListNode();
        ListNode* temp2 = head2;

      while(true){
        n += k;
        r++;
        if(n > a) break;

        for(int i = n-1; i >= x; i--){         
            temp2->val = arr[i];
            if(r == a/k && i == x) break;
            ListNode* newnode = new ListNode();
            temp2->next = newnode;
            temp2 = temp2->next;          
        }
          x += k;
      }

        temp = head;
        int y = 1;

        while(temp != NULL){
            if(y > x){
                temp2->next = temp;
                break;
            }
            temp = temp->next;
            y++;
        }
            
        return head2;
    }
};

// Main function
int main() {
    int k = 3;
    ListNode* head = createList();

    cout << "Original List:\n";
    display(head);

    Solution sol;
    ListNode* newHead = sol.reverseKGroup(head, k);

    cout << "\nReversed in groups of " << k << ":\n";
    display(newHead);

    return 0;
}
