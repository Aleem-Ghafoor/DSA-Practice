#include <iostream>
using namespace std;

// Provided ListNode structure
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int a = 0, c = 0;

        ListNode* temp = head;

        while(temp != NULL){
            a++;
            temp = temp->next;
        }

        if(a == 1) return NULL;
        if(a == n){
          temp = head;
          head = head->next;
          delete temp;
          return head;
        }

        c = a-n;
        
        a = 0;
        temp = head;
        ListNode* prev;

        while(temp != NULL){

            if(c-1 == a){
               prev = temp;
            }

            if(c == a){ 
              prev->next = temp->next;
              delete temp;
              break;
            
            }

            a++;
            temp = temp->next;

        }

        return head;
    }
};

ListNode* createList(initializer_list<int> vals) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    for (int v : vals) {
        curr->next = new ListNode(v);
        curr = curr->next;
    }
    return dummy->next;
}

// Function to display the linked list
void display(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createList({1, 2, 3});

    cout << "Original List: ";
    display(head);

    int n = 3; // Remove 2nd node from end

    // Create solution object
    Solution sol;
    ListNode* updatedHead = sol.removeNthFromEnd(head, n);

    cout << "Updated List: ";
    display(updatedHead);

    return 0;
}
