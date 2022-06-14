#include "implementation.cpp"

Node* findBST(Node* root, int d){
    if(root == NULL) return NULL;

    if(root->data == d) return root;

    if(d > root->data) return findBST(root->right, d);
    else
        return findBST(root->left, d);
}
Node* lca(Node* root, int d1, int d2){
    if(root == NULL) return NULL;

    Node* left = findBST(root->left, d1);
    Node* right = findBST(root->right, d2);

    if(left && right) return root;
    if(left != NULL && right == NULL) return left;
    if(left == NULL && right != NULL) return right;

    return NULL;
}


int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    Node* root = buildBST(a, 0, 8);
    print(root);

    Node* l = lca(root, 2, 7);
    cout<<"LCA of 2, 7 : "<<l->data<<endl;
    print(root);
    return 0;
}