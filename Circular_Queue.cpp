#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int currSize, cap;
    int f, r;
    
    public:
    CircularQueue(int size){
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0; 
        r = -1;
    }     
void push(int data){
    if(currSize == cap){
        cout << "CQ is full\n";
        return;
    }
    r = (r + 1) % cap;
    arr[r]  = data;
    currSize++;
}
void pop(){
    if(currSize == 0){
        cout << "CQ is empty\n";
        return;
    }
    f = (f + 1 ) % cap;
    currSize--;
}
int front(){
    if(currSize == 0){
        cout << "CQ is empty\n";
        return -1;
    }
    return arr[f];
}
bool empty(){
    return currSize = 0;
}
void printArr(){
    for(int i=0; i<cap; i++){
        cout << arr[i] << " ";
        
    }
    cout << endl;
}
};
int main() {
   CircularQueue CQ(3);
    CQ.push(1);
CQ.push(2);
CQ.push(3);
CQ.pop();
CQ.push(4);

CQ.printArr();
// cout << CQ.front() << endl; // This will print 1

    return 0;
    
}
