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
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
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
    ListNode* rotateRight(ListNode* head, int k) {
    
if(head == NULL) return NULL;

        int length = 0, a = 0;

        ListNode* temp = head;
        ListNode* newhead = new ListNode();
        ListNode* temp2 = newhead;
        ListNode* temp3 = head;

        while(temp != NULL){
            temp = temp->next;
            length++;
        }

        if(length == k) return head;
        while(true){
            if(k > length) k = k-length;
            if(k == length) return head;
            if(k < length) break;
        }

        temp = head;
        while(temp != NULL){
            if(a == length-k) temp2->next = temp;
            if(a >= length-k && temp2 != NULL) temp2 = temp2->next;
            temp = temp->next;
            a++;
        }

        a = 0;
        while(temp3 != NULL){
            if(a <= length-k){
              temp2->next = temp3;
              temp2 = temp2->next;
            }
            if(a == length-k-1 && temp2 != NULL) temp2->next = NULL;
            temp3 = temp3->next;
            a++;
        }

        return newhead->next;
    }
};

int main() {
    ListNode* head = createList();

    cout << "Original List: ";
    displayList(head);

    int k = 6; // You can change this value to test different rotations
    cout << "Rotating list to the right by " << k << " positions..." << endl;

    Solution sol;
    head = sol.rotateRight(head, k);

    cout << "After Rotation: ";
    displayList(head);

    return 0;
}
