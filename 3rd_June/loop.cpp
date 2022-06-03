#include "../LL_functions.cpp"

bool detectLoop(node* head){
    if(head == NULL || head->next == NULL) return false;
    node* fast = head, *slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
            return true;
    }

    return false;
}

void removeLoop(node* head){
    if(head == NULL || head->next == NULL) return;

    node* slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast) break;
    }

    int count = 1;
    while(slow->next != fast){
        slow = slow->next;
        count++;
    }

    slow = head;
    for(int i = 0; i < count; i++){
        slow = slow->next;
    }
    fast = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    // now slow and fast are at the starting of the loop
    // move fast at the end of the loop 
    while(fast->next != slow)
        fast = fast->next;
    
    fast->next = NULL;

    // return head;
}

int main(){
    // vector<int> v = {1,2,3,4,5,6,7,8};
    node* head = new node(50);
    head->next = new node(20);
    head->next->next = new node(15);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    if(detectLoop(head)){
        cout<<"LOOP FOUND \n";
        removeLoop(head);
        print(head);
    }
    return 0;
}

