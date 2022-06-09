#include <iostream>

using namespace std;

class node{
    public:
    int data;
    int priority;
    node* next;

    node(int data){
        this->data = data;
        this->priority = 0;
        next = NULL;
    }

    node(int data, int p){
        this->data = data;
        this->priority = p;
        next = NULL;
    }
};

class priority_queue{
    node* head;
    node* tail;

    public:
    priority_queue(){
        head = NULL;
        tail = NULL;
    }

    void push(int data, int p){
        node* newNode = new node(data, p);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }

        node* temp = head;
        node* prev;
        while(temp != NULL && temp->priority <= p){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            tail->next = newNode;
            tail = tail->next;
        }
        else{
            if(temp == head){
                newNode->next = head;
                head = newNode;

            }
            else{
                newNode->next = prev->next;
                prev->next = newNode;
            }
        }
    }

    int pop(){
        if(head == NULL){
            cout<<"PQ is empty."<<endl;
            return -1;
        }
        
        int ans = head->data;
        head = head->next;
        return ans;
    }

    int top(){
        if(head == NULL){
            cout<<"PQ is empty."<<endl;
            return -1;
        }
        
        int ans = head->data;
        return ans;
    }
};

int main(){
    priority_queue pq;
    pq.push(1,3);
    pq.push(3,4);
    pq.push(5,11);
    pq.push(4,5);
    pq.push(2,2);

    cout<<"Top : "<<pq.top()<<endl;
    cout<<pq.pop()<<endl;
    cout<<"Top : "<<pq.top()<<endl;
    cout<<pq.pop()<<endl;
    cout<<"Top : "<<pq.top()<<endl;
    cout<<pq.pop()<<endl;
    cout<<"Top : "<<pq.top()<<endl;
    cout<<pq.pop()<<endl;
    cout<<"Top : "<<pq.top()<<endl;
    cout<<pq.pop()<<endl;
    cout<<"Top : "<<pq.top()<<endl;
    cout<<pq.pop()<<endl;
    // cout<<"Top : "<<pq.top()<<endl;
    // cout<<pq.pop()<<endl;
    return 0;
}