#include <iostream>
#include <climits>

using namespace std;

class node{
    public:
    int data;
    node* next;
 
    node(int data){
        this->data = data;
        next = NULL;
    }
};
 
class queue{
    node* head;
    node* tail;

    public:
    queue(){
        head = NULL;
        tail = NULL;
    }
    void push(int data){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
    }

    int front(){
        if(head == NULL){
            cout<<"\nQueue is Empty."<<endl;
            return INT_MIN;
        }
        return head->data;
    }

    void pop(){
        if(head == NULL){
            cout<<"\nQueue is Empty."<<endl;
            return ;
        }
        // node* t = head->next;
        head = head->next;

        // delete t;
    }

    int size(){
        int length = 0;
        node* temp = head;

        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        return length;
    }

    bool isEmpty(){
        if(size() == 0) return true;
        return false;
    }

    void print(){
        node* temp = head;
        cout<<"\nQueue : ";
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    cout<<"hi1";
    queue q;
    cout<<"hi2";
    q.push(1);
    cout<<"hi2";
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);

    cout<<"hi3";
    cout<<"hi3";
    q.print();
    cout<<"Size : "<<q.size()<<endl;
    cout<<"Empty : "<<q.isEmpty()<<endl;
    cout<<"Front : "<<q.front()<<endl;
    q.pop();
    cout<<"Front : "<<q.front()<<endl;
    q.pop();
    cout<<"Front : "<<q.front()<<endl;
    q.pop();
    cout<<"Front : "<<q.front()<<endl;
    q.pop();
    cout<<"Front : "<<q.front()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout<<"Front : "<<q.front()<<endl;
    
    cout<<"Empty : "<<q.isEmpty()<<endl;

    return 0;
}