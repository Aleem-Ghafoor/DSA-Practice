#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){

        int add = 0;
        int n, arr[2];
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* head = new ListNode();
        ListNode* temp3 = head;

        while(temp1 != NULL && temp2 != NULL){

          add = temp1->val + temp2->val;

            n = 0;
            if(add == 0) arr[n] = add;

            while(add != 0){

              if(add == 0) break;
                arr[n] = add%10;
                add = add/10;
                n++;
                
            }

            temp3->val = arr[0];
          if(temp1->next != NULL && temp2->next != NULL){
            ListNode* node = new ListNode();
            temp3->next = node;
            temp3 = temp3->next;
          }

          if(n == 2){
            temp1 = temp1->next;
            if(temp1 != NULL)
              temp1->val = temp1->val + arr[1];

              temp2 = temp2->next;

            if(temp1 == NULL && temp2 == NULL){
              if(n == 2){
                ListNode* node = new ListNode();
                temp3->next = node;
                temp3 = temp3->next;
                temp3->val = arr[1];
              }
            }       
              
          }
          else{
            temp1 = temp1->next;        
            temp2 = temp2->next;
          }     
        }

      if(n == 2){  

        if(temp1 != NULL){

          add = temp1->val;

          while(true){ 

            n = 0;
            if(add == 0) arr[n] = add;

            while(add != 0){

              if(add == 0) break;
              arr[n] = add%10;
              add = add/10;
              n++;

            }
            
            if(n != 2){

              temp1->val = arr[0];
              temp3->next = temp1;
              break;

            }
            else{

              temp1->val = arr[0];
              temp3->next = temp1;
              temp3 = temp3->next;

            }

            temp1 = temp1->next;

            if(temp1 != NULL)
              add = temp1->val + arr[1];

            if(n == 2 && temp1 == NULL){

              ListNode* newnode = new ListNode();
              newnode->val = arr[1];
              temp3->next = newnode;
              break;

            }

          }

        }

        if(temp2 != NULL){

          while(true){ 

            add = temp2->val + arr[1];
            n = 0;
            if(add == 0) arr[n] = add;

            while(add != 0){

              if(add == 0) break;
              arr[n] = add%10;
              add = add/10;
              n++;

            }
            
            if(n != 2){

              temp2->val = arr[0];
              temp3->next = temp2;
              break;

            }
            else{

              temp2->val = arr[0];
              temp3->next = temp2;
              temp3 = temp3->next;

            }

            temp2 = temp2->next;
            if(n == 2 && temp2 == NULL){

              ListNode* newnode = new ListNode();
              newnode->val = arr[1];
              temp3->next = newnode;
              break;

            }

          }

          
        }

      }
      else{
         if(temp1 != NULL){
          temp3->next = temp1;
        }
        else if(temp2 != NULL)
          temp3->next = temp2;
      }
        return head;
    }   

};

// Helper function to create linked list from initializer list
ListNode* createList(initializer_list<int> vals) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    for (int v : vals) {
        curr->next = new ListNode(v);
        curr = curr->next;
    }
    return dummy->next;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    // Example lists: 342 + 465 = 807
    ListNode* l1 = createList({1,6,0,3,3,6});
    ListNode* l2 = createList({6,3,0,8,9,3,6,9,6,1});
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}
