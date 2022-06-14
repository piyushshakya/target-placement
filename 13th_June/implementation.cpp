#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


Node* insertIntoBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertIntoBST(root->right, d);
    }
    else{
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

void print(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* r = q.front();
        q.pop();

        cout<<r->data<<" : ";
        if(r->left){
            cout<<r->left->data;
            q.push(r->left);
        }
        if(r->right){
            cout<<", "<<r->right->data;
            q.push(r->right);
        }
        cout<<endl;
    }
}

Node* buildBST(vector<int> a, int st, int end){
    if(st > end)
        return NULL;
    
    int mid = st + (end - st)/2;
    Node* root = new Node(a[mid]);

    root->left = buildBST(a, st, mid-1);
    root->right = buildBST(a, mid+1, end);

    return root;
}

bool isPresent(Node* root, int data){
    if(root == NULL)
        return false;
    if(root->data == data) return true;

    if(root->data > data) return isPresent(root->left, data);
    else
        return isPresent(root->right, data); 
}

/*
int main(){
    vector<int> a = {1,2,3,4,6,7,8,9};
    Node* root = buildBST(a, 0, 7);
    print(root);
    
    cout<<"\nsearch : "<<isPresent(root, 5);
    cout<<"\nsearch : "<<isPresent(root, 8);
    cout<<"\nsearch : "<<isPresent(root, 0);

    // takeInput(root);
    // print(root);

    // insertIntoBST(root, 5);
    // insertIntoBST(root, 0);
    // insertIntoBST(root, 10);

    
    return 0;
}
*/