#include "../LL_functions.cpp"

node* middle(node* head){
    if(head == NULL || head->next == NULL) return head;
    
    node* slow = head, *fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

node* merge(node* h1, node* h2){
    if(h1 == NULL && h2 == NULL) return NULL;
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    
    node* tail = new node(0);
    node* head = tail;

    while(h1 != NULL && h2 != NULL){
        if(h1->data <= h2->data){
            tail->next = h1;
            h1 = h1->next;
        }
        else{
            tail->next = h2;
            h2 = h2->next;
        }
        
        tail = tail->next;
    }
    
    while(h1 != NULL){ 
        tail->next = h1;
        h1 = h1->next;
        tail = tail->next;
    }
    while(h2 != NULL){
        tail->next = h2;
        h2 = h2->next;
        tail = tail->next;
    }
    
    return head->next;
}

node* mergeSort(node* head) {
    if(head == NULL || head->next == NULL) return head;
    
    node* mid = middle(head);
    node* h1 = head, *h2 = mid->next;
    mid->next = NULL;
    
    node* res = merge(mergeSort(h1), mergeSort(h2));
    return res;
}

int main(){
    vector<int> v = {9,8,7,4,5,6,8,7,6,3,4};
    node* head = insert(v);
    print(mergeSort(head));

    return 0;
}