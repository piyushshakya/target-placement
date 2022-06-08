#include <iostream>
#include <vector>
#include <climits>

using namespace std;

template<typename t>
class stack{
    t *arr;
    int nextIndex;
    int capacity;

    public:
    stack(int size){
        this->capacity = size;
        nextIndex = 0;
        arr = new t[size]; 
    }
    
    void push(t data){
        if(nextIndex >= capacity){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            arr[nextIndex++] = data;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            nextIndex--;
        }
    }

    t top(){
        // cout<<"Top Ind : "<<nextIndex<<endl;
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT_MIN;
        }
        
        return arr[nextIndex-1];
        
    }

    bool isEmpty(){
        if(nextIndex <= 0) return true;
        else
            return false;
    }

    int size(){
        return nextIndex;
    }
};

int main(){
    stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
}