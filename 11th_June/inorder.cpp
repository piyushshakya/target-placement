#include "tree.cpp"

void inorderRec(treeNode<int>* root){
    int size = root->children.size();
    int i = 0;
    for(i = 0; i < size/2; i++){
        inorderRec(root->children[i]);
    }

    if(i == size/2)
        cout<<root->data<<" ";


    for(; i < size; i++){
        inorderRec(root->children[i]);
    }
}

void inorder(treeNode<int> * root){
    int size = root->children.size();
    vector<treeNode<int>*> temp(size);

    for(int i = 0; i < size; i++){
        
    }
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main(){
    treeNode<int>* root = takeInput();
    inorderRec(root);

    return 0;
}