#include <iostream>
using namespace std;

class Node{
     public:
        int data;
        Node* next;
         
        Node(int val){
            data = val;
            next = NULL;
            
        }
};

  class  CircularList{
        Node* head;
        Node* tail;
    
    public:
        CircularList(){
            head = tail =NULL;
        }
        
        // insert At head Values
    void insertAtHead(int val){
        Node* newNode = new Node(val);
        
        if(tail == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode-> next = head;
            head = newNode;
            tail->next = head;
            
        }
        
    }
    
    // Insert at Tail Values
    void insertAtTail(int val){
         Node* newNode = new Node(val);
        
        if(tail == NULL){
            head = tail = newNode;
            tail->next = head;
        }else{
            newNode-> next = head;
            tail-> next = newNode;
            
            tail = newNode;
            
        }
    }
    
    // delete at Head Values
    void deleteAtHead(){
        if(head ==NULL)
        return;
        else if(head == tail){ //single node
            delete head;
            head = tail = NULL;
        }else{ // 2 or more node
            Node* temp = head;
            
            head = head -> next ;
            tail -> next = head;
            
            temp->next = NULL;
            delete temp;
            
        }
    }
    
    // delete At Tail values
    void deleteAtTail(){
         if(head ==NULL)
        return;
        else if(head == tail){ //single node
            delete head;
            head = tail = NULL;
        }else{ // 2 or more node
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }
           
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
            
        }
    }
    //printing values
    void print(){
        if(head == NULL) return ;
        
        cout << head->data << "->";
        Node* temp = head->next;
        
        while(temp != head){
            cout << temp->data << " ->";
            temp = temp->next;
        }
        cout << temp->data << " head" << endl;
    }
    
    
};
int main() {
        CircularList cll;
        
        // cll.insertAtHead(1);
        // cll.insertAtHead(2);
        // cll.insertAtHead(3);
       
        
        cll.insertAtTail(1);
        cll.insertAtTail(2);
        cll.insertAtTail(3);
        
        
        // cll.deleteAtHead();
        // cll.deleteAtTail();
        
     cll.print();
    return 0;
}
