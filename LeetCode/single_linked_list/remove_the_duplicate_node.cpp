#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to create a statically initialized list: 1 -> 2 -> 3 -> 4 -> 5
ListNode* createList() {
    ListNode* node7 = new ListNode(4);
    ListNode* node6 = new ListNode(4, node7);
    ListNode* node5 = new ListNode(3, node6);
    ListNode* node4 = new ListNode(2, node5);
    ListNode* node3 = new ListNode(1, node4);
    ListNode* node2 = new ListNode(1, node3);
    ListNode* node1 = new ListNode(1, node2);
    return node1; // head
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

// rotateRight function (you will implement this)
class Solution {
public:
    ListNode* rotateRight(ListNode* head) {
         if(head == NULL || head->next == NULL) return head;
                ListNode* temp = head;
        int a = 0;
        while(temp != NULL){
            ListNode* temp2 = temp->next;
            a = 0;
            while(temp2 != NULL){
              if(temp->val == temp2->val){
                temp2->val = -1;
                a++;
              }
              temp2 = temp2->next;
            }
            if(a > 0) temp->val = -1;
            temp = temp->next;
        }

        temp = head;
        ListNode* newhead = new ListNode();
        ListNode* temp2 = newhead;
        a = 0;
        while(temp != NULL){
            ListNode* newnode = new ListNode();
            if(temp->val == -1){
                temp = temp->next; 
                continue;
            }
            a++;
            if(temp == NULL) break;
            if(temp != NULL && temp->val != -1){
              temp2->next = newnode;
              temp2 = temp2->next; 
              temp2->val = temp->val;
              cout << endl << temp2->val << endl;
            }
            temp = temp->next;
        }
        if(a == 0) return NULL;
        return newhead->next;
    }
};

int main() {
    ListNode* head = createList();

    cout << "Original List: ";
    displayList(head);

    Solution sol;
    head = sol.rotateRight(head);

    cout << "After Rotation: ";
    displayList(head);

    return 0;
}
