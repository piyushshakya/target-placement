#include "../LL_functions.cpp"

class cl{
    node* head;
    node* tail;

    public:
    cl(){
        head = NULL;
        tail = NULL;
    }

    void print(){
        node* temp = head;
        cout<<"\nLinked List : ";
        // int size = 0;
        do{
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }while(temp->next != head);
        // cout<<size;
    }

    void insertAtBegin(int data){
        if(head == NULL){
            head = new node(data);
            head->next = head;
            
            tail = head;
            return;
        }


        node* newNode = new node(data);
        newNode->next = head;
        head = newNode;

        tail->next = head;
    }

    void insertAtEnd(int data){
        // node *tail = head;
        // while(tail->next != head){
        //     tail = tail->next;
        // }

        node* newNode = new node(data);
        tail->next = newNode;
        tail = tail->next;
        tail->next = head;
    }

    void insertAtK(int data, int k){
        node* temp = head;
        for(int i = 0; i < k-1; i++){
            temp = temp->next;
        }

        node* newNode = new node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void removeAtBegin(){
        node* temp = head;

        head = head->next;
        tail->next = head;

        delete temp;
    }

    void removeAtEnd(){
        node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }

        temp->next = tail->next;
        tail = temp;

        delete temp;
    }

    void removeAtK(int k){
        node* temp = head;
        for(int i = 0; i < k-1; i++){
            temp = temp->next;
        }

        node* t = temp->next;
        temp->next = temp->next->next;

        delete t;
    }
};

int main(){
    cl *head = new cl();
    head->insertAtBegin(6);
    head->insertAtBegin(5);
    head->insertAtBegin(4);
    head->insertAtBegin(3);
    head->insertAtBegin(2);
    head->insertAtBegin(1);
    head->insertAtEnd(7);

    head->insertAtK(100, 10);
    head->print();

    return 0;
}