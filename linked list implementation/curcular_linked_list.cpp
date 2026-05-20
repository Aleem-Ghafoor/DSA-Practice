#include<iostream>
#include<unordered_map>
using namespace std;

struct List{

      int num;
      List* next;

      List() : num(0), next(nullptr) {}
};

class Circular{
    public:

    List* solution(List* head){

        List* temp = head->next;
        unordered_map<List*, int> find;

        while(true){

                if(find.count(temp->next)){
                    cout << "\n\nThe circle starts from " << temp->next->num << " and end at " << temp->num << endl;
                    break;
                }
                find[temp]++;
                temp = temp->next;
        }
          return temp;
    }

    void creat_list(List* head){
   
        List* temp = head;
        int n = 0;
        cout << "\npress -1 to stop!\n";

      while(true){

        cout << "\nEnter the list element: ";
        cin >> n;
        
        if(n == -1){
          temp->next = head->next->next->next->next;
          break;
        }

        List* newnode = new List();

        if(head == NULL){
          temp->next = newnode;
          temp = temp->next;
          temp->num = n;
        }
        else{
          temp->next = newnode;
          temp = temp->next;
          temp->num = n;
        }
      }
    }
};

int main(){

    List* head = new List();
    List* find;
    Circular cur;

    cur.creat_list(head);
    find = cur.solution(head);

  return 0;
}