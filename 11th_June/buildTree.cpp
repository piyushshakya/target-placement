#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void print(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* t = q.front();
        q.pop();

        cout<<t->data<<" : ";
        if(t->left != NULL){
            cout<<t->left->data<<", ";
            q.push(t->left);
        }

        if(t->right != NULL){
            cout<<t->right->data;
            q.push(t->right);
        }
        cout<<endl;
    }
}

node* takeInput(){
    int rootData;
    cout<<"Enter root data : ";
    cin>>rootData;

    node* root = new node(rootData);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* top = q.front();
        q.pop();

        int leftData, rightData;
        cout<<"Enter Left child of "<<top->data<<" : ";
        cin>>leftData;

        if(leftData == -1){
            top->left = NULL;
        }else{
            node* newNode = new node(leftData);
            top->left = newNode;
            q.push(newNode);
        }
        
        cout<<"Enter Right child of "<<top->data<<" : ";
        cin>>rightData;

        if(rightData == -1){
            top->right = NULL;
        }else{
            node* newNode = new node(rightData);
            top->right = newNode;
            q.push(newNode);
        }
    }

    return root;
}

node* buildTree_InPre_Helper(vector<int> in, int inS, int inE, vector<int> pre, int preS, int preE){
    if(inS > inE) return NULL;

    int rootIndexPre = preS, rootInd_In;
    for(int i = inS; i <= inE; i++)
        if(in[i] == pre[preS]) rootInd_In = i;

    int linS = inS, linE = rootInd_In-1, rinS = rootInd_In+1, rinE = inE;
    int lpreS = preS+1; 

    int lpreE = linE - linS + lpreS;
    int rpreS = lpreE+1, rpreE = preE;

    node* root = new node(pre[preS]);

    root->left = buildTree_InPre_Helper(in, linS, linE, pre, lpreS, lpreE);
    root->right = buildTree_InPre_Helper(in, rinS, rinE, pre, rpreS, rpreE);

    return root;
}

node* buildTree_inorder_preorder(vector<int> in, vector<int> pre){
    int size = in.size();
    return buildTree_InPre_Helper(in, 0, size-1, pre, 0, size-1);
}

int main(){
    node* root = takeInput();
    print(root);
    vector<int> in = {5,2,6,1,7,3,8,9}, pre = {1,2,5,6,3,7,8,9};
    node* r = buildTree_inorder_preorder(in, pre);
    cout<<endl<<endl;
    print(r);
    return 0;
}