#include "../LL_functions.cpp"

node* reverse(node* head, int k){
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    
    node* curr = head, *prev = NULL, *next = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        
        count++;
    }

    if(next != NULL){
        head->next = reverse(next, k);
    }

    return prev;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    node* head = insert(v);

    head = reverse(head, 3);
    print(head);

    return 0;
}