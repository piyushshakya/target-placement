#include "LL_functions.cpp"

node* reverse(node* head){
    node* prev = NULL, *next, *curr = head;

    while(next != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        
        curr = next;
    }
    head = prev;

    return head;
}

node* reverse_rec1(node* head){
    if(head->next == NULL || head == NULL) return head;

    node* temp = reverse_rec1(head->next);
    
    // node* t = temp;
    // while(t->next != NULL){
    //     t = t->next;
    // }
    // t->next = head;
    // head->next = NULL;

// OR 
    head->next->next = head;
    head->next = NULL;

    
    return temp;
}

node* reverse_rec2(node* head){
    if(head->next == NULL || head == NULL) return head;

    node* temp = reverse_rec1(head->next);
    
    node* t = temp;
    while(t->next != NULL){
        t = t->next;
    }
    t->next = head;
    head->next = NULL;

// OR 
    // head->next->next = head;
    // head->next = NULL;

    return temp;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    node *head = insert(v);
    print(head);

    head = reverse(head);
    head = reverse_rec1(head);
    print(head);

    return 0;
}