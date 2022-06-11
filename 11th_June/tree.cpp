#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class treeNode{
    public:
    T data;
    vector<treeNode<T>*> children;

    treeNode(T data){
        this->data = data;
    }
};

treeNode<int> *takeInputRec(){
    int rootData;
    cout<<"Enter data : ";
    cin>>rootData;

    treeNode<int>* root = new treeNode<int>(rootData);

    int n;
    cout<<"Enter no. of children of "<<rootData<<" : ";
    cin>>n;

    for(int i = 0; i < n; i++){
        treeNode<int>* child = takeInputRec();
        root->children.push_back(child);
    }

    return root;
}

treeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data : ";
    cin>>rootData;

    treeNode<int> * root = new treeNode<int>(rootData);

    queue<treeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        treeNode<int>* p = q.front();
        q.pop();
        int n;
        cout<<"Enter no. of children of "<<p->data<<" : ";
        cin>>n;

        for(int i = 0; i < n; i++){
            int data;

            cout<<"Enter "<<i+1<<"th child of "<<p->data<<" : ";
            cin>>data;

            treeNode<int>* child = new treeNode<int>(data);
            p->children.push_back(child);

            q.push(child);
        }
    }

    return root;
}

void printTree(treeNode<int>* root){
    if(root == NULL) return;

    cout<<root->data<<" : ";

    for(int i = 0; i < root->children.size(); i++){
        cout<<root->children[i]->data<<", ";
    }

    cout<<endl;

    for(int i = 0; i < root->children.size(); i++)
        printTree(root->children[i]);
}


/*
int main(){
    treeNode<int> * root = takeInput();
    printTree(root);

    return 0;
}
*/