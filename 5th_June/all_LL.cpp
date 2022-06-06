#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node{
    public:

    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class list{
    node* head;
    
    public:

};


void print(node* head){
    node* temp = head;
    cout<<"\n Linked List : ";
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"null"<<endl;
}

node* insertUsingVector(vector<int> v){
    node* head = new node(-1);
    node* tail = head;

    for(int i : v){
        node* newNode = new node(i);
        tail->next = newNode;
        tail = tail->next;
    }

    return head->next;
}

node* insertAtBegin(node* head, int data){
    node* newNode = new node(data);
    newNode->next = head;

    return newNode;
}

node* insertAtEnd(node* head, int data){
    node* newNode = new node(data);

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

node* insertAtK(node* head, int data, int k){
    if(k == 0)
        return insertAtBegin(head, data);
    
    node* temp = head;
    for(int i = 0; i < k-1; i++){
        temp = temp->next;
        
        if(temp == NULL)
            return head;
    }

    node* newNode = new node(data);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

node* removeAtBegin(node* head){
    node* t = head;
    head = head->next;
    delete t;

    return head->next;
}

node* removeAtEnd(node* head){
    node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node* remove = temp->next;

    temp->next = NULL;

    delete remove;
    return head;
}

node* removeAtK(node* head, int k){
    if(k == 0) return head->next;

    node* temp = head;

    for(int i = 0; i < k-1; i++){
        temp = temp->next;
    }

    node *t = temp->next;
    temp->next = t->next;

    delete t;

    return head;
}

int length(node* head){
    node* temp = head;
    int len = 0;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }

    return len;
}

node* swap(node* head, int d1, int d2){
    if(head == NULL || d1 == d2)
        return head;

    node* prev1 = NULL, *curr1 = NULL, *prev2 = NULL, *curr2 = NULL;
    
    node* temp = head;
    while(temp != NULL){
        if(temp->data == d1){
            curr1 = temp;
            break;
        }
        prev1 = temp;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        if(temp->data == d2){
            curr2 = temp;
            break;
        }
        prev2 = temp;
        temp = temp->next;
    }

    if(curr1 == curr2 || curr1 == NULL || curr2 == NULL)
        return head;
    
    if(prev1 == NULL){
        head = curr1;
    }
    else{
        prev1->next = curr1;
    }

    if(prev2 == NULL){
        head = curr2;
    }
    else{
        prev2->next = curr2;
    }

    node* t = curr1->next;
    curr1->next = curr2->next;
    curr2->next = t;

    return head;
}

node* reverseIterative(node* head){
    node* next = NULL, *prev = NULL, *curr = head;

    while(next != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;

        curr = next;
    }

    return prev;
}

node* reverseRecursive1(node* head){
    if(head == NULL || head->next == NULL)
        return head;
    
    node* rev = reverseRecursive1(head->next);
    node* tail = rev;
    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = head;
    tail = tail->next;
    tail->next = NULL;

    return rev;
}

node* reverseRecursive2(node* head){
    if(head == NULL || head->next == NULL)
        return head;

    node *rev = reverseRecursive2(head->next);

    head->next->next = head;
    head->next = NULL;

    return rev;
}

bool detectLoop(node* head){
    node* fast = head, *slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }

    return false;
}

node* removeLoop(node* head){
    node* fast = head, *slow = head;

    while(fast != NULL && slow != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

// count no. of nodes in loop
    int count = 0;
    while(fast != slow){
        count++;
        slow = slow->next;
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


    while(fast->next != slow)
        fast = fast->next;
    fast->next = NULL;

    return head;
}



// merge k sorted linked list
node* merge(node* h1, node* h2){
    if(h1 == NULL && h2 == NULL) return NULL;

    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;

    if(h1->data <= h2->data){
        h1->next = merge(h1->next, h2);
        return h1;    
    }

    h2->next = merge(h1, h2->next);
    return h2;
}

node* mergeK_1(vector<node*> list){
    while(list.size() > 1){
        list.push_back(merge(list[0], list[1]));
        list.erase(list.begin());
        list.erase(list.begin());
    }

    return list[0];
}

// method 2 using min Heap, merge k 

struct compare{
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

node* mergeK_2(vector<node*> list){
    int k = list.size();

    priority_queue<node*, vector<node*>, compare> pq;

    for(auto i : list){
        pq.push(i);
    }

    if(pq.empty()) return NULL;

    node* res = new node(0);
    node* temp = res;
    while(!pq.empty()){
        node* t = pq.top();
        pq.pop();
        
        if(t->next) pq.push(t->next);

        temp->next = t;
        temp = temp->next;
    }

    return res->next;
}



// merge sort

node* middle(node* head){
    node* fast = head, *slow = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node* mergeSort(node* head){
    if(head == NULL || head->next == NULL) return head;

    node* mid = middle(head);

    node* h1 = head, *h2 = mid->next;
    mid->next = NULL;

    return merge(mergeSort(h1), mergeSort(h2));
}


node* reverseK_Nodes(node* head, int k){
    if(head == NULL || head->next == NULL || k == 1) return head;

    int count = 0;
    node* next = NULL, *curr = head, *prev = NULL;

    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
         
        count++;
    }

    if(next != NULL){
        head->next = reverseK_Nodes(next, k);
    }

    return prev;
}

node* addNosLL(node* d1, node* d2){
    d1 = reverseRecursive2(d1);
    d2 = reverseRecursive2(d2);

    int sum = 0, carry = 0;
    node* res = new node(0);
    node* temp = res;

    while(d1 != NULL && d2 != NULL){
        sum = carry;
        if(d1 != NULL){
            sum += d1->data;
            d1 = d1->next;
        }
        if(d2 != NULL){
            sum += d2->data;
            d2 = d2->next;
        }
        carry = sum/10;

        sum %= 10;
        node* newNode = new node(sum);
        
        temp->next = newNode;
        temp = temp->next;
    }

    while(d1 != NULL){
        sum = d1->data + carry;
        carry = sum/10;
        
        node* newNode = new node(sum%10);
        temp->next = newNode;
        temp = temp->next;
        
        d1 = d1->next;
    }
    
    while(d2 != NULL){
        sum = d2->data + carry;
        carry = sum/10;

        node* newNode = new node(sum%10);
        temp->next = newNode;
        temp = temp->next;

        d2 = d2->next;
    }

    if(carry){
        node* newNode = new node(carry);
        temp->next = newNode;
        temp = temp->next;
    }
    return reverseRecursive2(res->next);
}



node* rotateK(node* head, int k){
    node* temp = head;
    int size = 1;
    while(temp->next != NULL){
        temp = temp->next;
        size++;
    }

    k = k%size;
    temp->next = head;

// anti - clockwise
    for(int i = 0; i < size - k; i++)
        temp = temp->next;
    
// clockwise 
    // for(int i = 0; i < k; i++)
    //     temp = temp->next;

    head = temp->next;
    temp->next = NULL;

    return head;
}

int main(){
    vector<int> v  = {9,9,9,9,9,9,9,9,9}, x = {1};
    node* head = insertUsingVector(v);
    node* h2 = insertUsingVector(x);

    print(reverseK_Nodes(addNosLL(head, h2), 8));

    return 0;
}