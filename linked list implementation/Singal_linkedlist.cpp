#include<iostream>
using namespace std;

class Node{
  private:
    int n;
    Node* next;
  public:

void insertdata(Node* &head, int n){

       Node* newhead = new Node();
       
        newhead->n = n;
        newhead->next = NULL;

       if(head == NULL){
            head = newhead;
       }
       else{
            
        Node* temp = head; 
            
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newhead;
       }
}

// search perticular value

void search(Node* &head){

    int n, a = 0;

    cout << "\nEnter the number: ";
    cin >> n;

    Node* temp = head;
  
    while(temp != NULL){
        a++;

        if(temp->n == n){
            cout << "The number " << temp->n << " at " << a << " place. " << endl;
            return;
        }
        
        temp = temp->next;
    }
        cout << "Not found!";
}

//find length

void length(Node* &head){
      int a = 0;
      Node* temp = head;

      while(temp != NULL){
          a++;
          temp = temp->next;
      }
      cout << "\nThe length is: " << a << endl;
}

//update head

 void change_head(Node* &head, Node* &newhead){
    int n;

    cout << "\nEnter the value: ";
    cin >> newhead->n;

    newhead->next = head->next;
    
    cout << "\nFirst place value changed from " << head->n << " to " << newhead->n << endl;

    while(head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp; 
    }
} 

//arrang in order

void ordered_form(Node* &head){

    Node* temp;
    Node* t = head;
    Node* te = head;
    while(t != NULL){
            temp = t->next;

        while(temp != NULL){

            if(t->n > temp->n){
                
                int copy = t->n;
                t->n = temp->n;
                temp->n = copy;

            }
                temp = temp->next;
        }

        t = t->next;
    }

    display(head);
}

// delete list

void del(Node* &head){
    int n, a = 0;

        cout << "\nEnter the number to remove list: ";
        cin >> n;

        Node* temp = head;
        Node* perv = NULL;

        while(temp != NULL){
            a++;
            if(temp->n == n){
                
                if(temp == head){
                    head = head->next;
                    delete temp;
                }
                else{
                    perv->next = temp->next;
                    delete temp;
                }

                cout << a << " place Delete successfully!";
                return;
            }
            perv = temp;
            temp = temp->next;

        }
}

// display
void display(Node* &head){
       Node* temp = head;
       while(temp != NULL){
       cout << "\nThe value is: " << temp->n;
       temp = temp->next;
       } 
}

//list
int list(){
    int choice;

    while(true){
       cout << "\n----------Chose from the following----------\n";
       cout << "\n1-Find length";
       cout << "\n2-Find value";
       cout << "\n3-Change head";
       cout << "\n4-Delete List";
       cout << "\n5-View List";
       cout << "\n6-Place in ordered form";
       cout << "\n7-Exit";
       cout << "\n\nEnter the choice: ";
       cin >> choice;
       
       if(choice > 0 && choice < 8) break;
       else cout << "\nInvalid number!";
    }

    return choice;
}

};

int main(){
    int n, a = 0;
    Node* head = NULL;
    Node* newhead = new Node();
    
    cout << "\nPress -1 to stop!";
    while(true){
         cout << "\n" << ++a << "-Enter the value: ";
         cin >> n;
         if(n == -1) break;

         head->insertdata(head, n);
    }
    
        a = 0;
        int choice = 0;
        
do{
    choice = head->list();

    switch(choice){
        case 1:
            head->length(head);
        break;
        case 2:
            head->search(head);
        break;
        case 3:
            head->change_head(head, newhead);
            a++;
        break;
        case 4:
            if(a > 0)
               head->del(newhead);
            else
               head->del(head);
        break;
        case 5:
            if(a > 0)
               head->display(newhead);
            else
               head->display(head);
        break;
        case 6:
            if(a > 0)
                head->ordered_form(newhead);
            else 
                head->ordered_form(head);
        break;
        case 7:
        break;
        default:
            cout << "Invalid Number!";
    }
}while(choice != 7);
    return 0;
}
