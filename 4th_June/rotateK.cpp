#include "../LL_functions.cpp"

node* rotate(node* head, int k){
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    
    int size = 1;
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        size++;
    }

    k = k % size;

    temp->next = head;

    for(int i = 0; i < size-k; i++){
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    return head;
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    node* head = insert(v);

    head = rotate(head, 4);
    print(head);

    return 0;
}