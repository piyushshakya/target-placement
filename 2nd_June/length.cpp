#include "LL_functions.cpp"

int lengthRec(node* head){
    if(head == NULL)
        return 0;
    
    return lengthRec(head->next) + 1;
}

int lengthIter(node* head){
    int l = 0;
    node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        l++;
    }

    return l;
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

    node* newNode = new node(1000);
    cout<<lengthIter(newNode)<<" "<<lengthRec(newNode);
    return 0;
}