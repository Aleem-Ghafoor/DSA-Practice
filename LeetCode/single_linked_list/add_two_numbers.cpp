#include <iostream>
#include <cmath>
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

        int a = 0, value = 0;
        ListNode* temp = l1;

        while(temp != NULL){
            value = temp->val;
            while(value != 0){
                value = value/10;
                a++;      
            }
                 
            temp = temp->next;

        } 

        int d = 0;
        ListNode* t = l2;

        while(t != NULL){
            value = t->val;
            while(value != 0){
                value = value/10;
                d++;      
            }
            t = t->next;

        }

        if(a == 0 && d == 0) return new ListNode(0);
        if(a == 0) return l2;
        if(d == 0) return l1;

// arr1        
        
        int arr1[a];
        int b = 0;
        temp = l1;

        while(temp != NULL){
        
            if(b == a) break;

            while(temp->val != 0){
                arr1[b] = temp->val%10;
                temp->val = temp->val/10;

                cout << "\narr: " << arr1[b];
                b++;
            }

            temp = temp->next;

        }
        
        long long c  = 0;

        for(int i = a-1; i >= 0; i--)
            c += arr1[i] * pow(10, i);
     
//arr2
        
        int arr2[d];
        int e = 0;
        t = l2;

        while(t != NULL){
        
            if(e == d) break;

            arr2[e] = t->val;
            e++;
            t = t->next;

        }

        long long f  = 0;

        for(int i = d-1; i >= 0; i--)
            f += arr2[i] * pow(10,i);
      
//final sum
        long long sum = 0;

        sum = c + f;
    
    if(sum != 0){
        b = 0;
        int n = 0;
        long long sum2 = 0;
        sum2 = sum;

        while(sum2 != 0){
  
          n = sum2%10;
          sum2 = sum2/10;
          b++;

        }
    }
    else
        return new ListNode(0);
        cout << endl;
        int arr3[b];

        e = 0;

        while(sum != 0){
           
          arr3[e] = sum%10;
          sum = sum/10;
          e++;

        }

        ListNode* head = new ListNode();
        ListNode* tm = head;
        e = 0;
        for(int i = 0; i < b; i++){

               tm->val = arr3[i];

               if(e == b-1) break;
               ListNode* newnode = new ListNode();
               tm->next = newnode;
               tm = tm->next;
               e++;

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
    ListNode* l1 = createList({87, 90, 8});
    ListNode* l2 = createList({1, 4, 6});

    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}
