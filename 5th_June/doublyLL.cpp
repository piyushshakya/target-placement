#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(){
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class doubly{
    node* head;
    node* tail;
    public:
    doubly(){
        head = NULL;
        tail = NULL;
    }

    void insertAtBegin(int data){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            tail = head;
            return;
        }

        head->prev = newNode;
        newNode->next = head;
        head = head->prev;
    }

    void insertAtEnd(int data){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            tail = head;

            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
    }

    void removeAtBegin(){
        node* t = head;

        head = head->next;
        head->prev = NULL;
        delete t;
    }

    void removeAtEnd(){
        node* t = tail;
        tail = tail->prev;
        tail->next = NULL;

        delete t;
    }

    void reverse(){
        node* temp = tail;
        cout<<"\nDoubly LL : ";
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->prev;
        }
        cout<<"null";
    }

    void print(){
        node* temp = head;
        cout<<"\nDoubly LL : ";
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"null";
    }
};

int main(){
    doubly *h = new doubly();
    h->insertAtBegin(6);
    h->insertAtBegin(5);
    h->insertAtEnd(7);
    h->insertAtEnd(8);
    h->insertAtBegin(4);
    h->insertAtEnd(9);

    h->print();
    h->reverse();

    h->removeAtBegin();
    h->removeAtEnd();

    h->print();
    h->reverse();

    return 0;
}