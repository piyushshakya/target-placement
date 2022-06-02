#include "LL_functions.cpp"

node* swapNodes(node* head, int d1, int d2){
    if(head == NULL) return head;

    node* prev1 = NULL, *curr1 = NULL, *prev2 = NULL, *curr2 = NULL;

    node* temp = head;
    int found = 0;

    while(temp->next != NULL){
        if(temp->data == d1){
            curr1 = temp;
            break;
        }
        prev1 = temp;
        temp = temp->next;
    }

    temp = head;
    while(temp->next != NULL){
        if(temp->data == d2){
            curr2 = temp;
            break;
        }
        prev2 = temp;
        temp = temp->next;
    }

    if(curr1 == curr2 || curr1 == NULL || curr2 == NULL)
        return head;

    if(prev1 == NULL){ // head
        head = curr2;
    }
    else{
        prev1->next = curr2;
    }

    if(prev2 == NULL){ // head
        head = curr1;
    }
    else{
        prev2->next = curr1;
    }

    node* t = curr1->next;
    curr1->next = curr2->next;
    curr2->next = t;

    return head;
}


int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    node *head = insert(v);
    print(head);

    head = swapNodes(head, 1, 2);
    print(head);
    head = swapNodes(head, 2, 5);
    print(head);
    head = swapNodes(head, 1, 2);
    print(head);

    return 0;
}