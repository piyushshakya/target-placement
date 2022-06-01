#include <iostream>
#include <vector>

using namespace std;

// representation
class node{
public:
    int data;
    node *next;

    node(int data){
        this->data = data;
        next = NULL;
    }

};

node* insert(vector<int> v){
    node* head = NULL, *tail = NULL;
    for(int i: v){
        node* newNode = new node(i);
        if(head == NULL && tail == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

void print(node* head){
    if(head == NULL) return;
    node* temp = head;

    cout<<"\nLinked List : ";
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"null";
}


// insertion
node* insertAtBegin(node* head, int data){
    node* newNode = new node(data);
    newNode->next = head;
    head = newNode;

    return head;
}

node* insertAt(node* head, int data, int idx){
    if(idx == 0)
        return insertAtBegin(head, data);
    
    node* temp = head;
    for(int i = 0; i < idx-1; i++){
        temp = temp->next;
    }
    node* newNode = new node(data);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

node* insertAtEnd(node* head, int data){
    node* temp = head;
    while(temp ->next != NULL){
        temp = temp->next;
    }
    node* newNode = new node(data);
    temp->next = newNode;

    return head;
}

// deletion
node* removeAtBegin(node* head){
    if(head->next == NULL) return NULL;

    node* a = head;
    head = head->next;
    delete a;
    return head;
}

node* removeAt(node* head, int idx){
    if(idx == 0) return removeAtBegin(head);

    node* temp = head;
    for(int i = 0; i < idx-1; i++){
        temp = temp->next;
    }

    node* t = temp->next;
    temp->next = t->next;

    delete t;

    return head;
}

node* removeAtEnd(node* head){
    node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    temp->next = NULL;

    return head;
}


int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    node *head = insert(v);
    print(head);
    // node* head = NULL;
    head = insertAtBegin(head, 11);
    head = insertAtBegin(head, 12);
    head = insertAtEnd(head, 13);
    head = insertAt(head, -11, 2);
    head = insertAtBegin(head, 14);
    print(head);

    head = removeAt(head, 5);
    head = removeAtBegin(head);
    head = removeAtEnd(head);
    print(head);

    return 0;
}