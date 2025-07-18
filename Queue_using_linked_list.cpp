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
class Queue {
    Node* head;
    Node* tail;
    
public:
    Queue() {
        head = tail = NULL;
    }
    void push(int data){
        Node* newNode = new Node(data);
        
        if(empty()){
            head = tail = newNode;
            
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        
    }
    void pop(){
        if(empty()){
            cout << "LL is emtpy\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    int front() {
        if (empty()) {
            cout << "LL is emtpy\n";
            return -1;
        }
        return head->data;
    }

    bool empty(){
        return head == NULL;
    }
};
int main() {
    Queue q;
    // Write C++ code here
    q.push(1);
    q.push(2);
    q.push(3);
    
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
