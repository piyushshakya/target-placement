#include "../LL_functions.cpp"

node* reverse(node* head){
    if(head == NULL || head->next == NULL)
        return head;
    
    node* temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return temp;
}
node* addTwoLists(node* first, node* second)
{
    first = reverse(first);
    second = reverse(second);
    
    int sum = 0, carry = 0;
    node* res = new node(0);
    node* temp = res;
    while(first != NULL && second != NULL){
        sum = 0;
        if(first){
            sum += first->data;
            first = first->next;
        }
        if(second){
            sum += second->data;
            second = second->next;
        }
        
        sum += carry;
    
        carry = sum/10;
        sum = sum%10;
        
        node* newNode = new node(sum);
        temp->next = newNode;
        
        temp = temp->next;
    }
    
    while(first != NULL){
        sum = carry + first->data;
        carry = sum/10;
        sum %= 10;
        
        node* newNode = new node(sum);
        temp->next = newNode;
        temp = temp->next;
        
        first = first->next;
    }
    
    while(second != NULL){
        sum = carry + second->data;
        carry = sum/10;
        sum %= 10;
        
        node* newNode = new node(sum);
        temp->next = newNode;
        temp = temp->next;
        
        second = second->next;
    }
    
    if(carry){
        node* newNode = new node(carry);
        temp->next = newNode;
        temp = temp->next;
    }
    res = res->next;
    res = reverse(res);
    return res;
}

int main(){
    vector<int> a = {6,5,4,6,7}, b = {9,8,7,6};
    print(addTwoLists(insert(a), insert(b)));

    return 0;
}