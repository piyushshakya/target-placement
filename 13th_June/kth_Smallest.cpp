#include "implementation.cpp"

int kthSmallest(Node* root, int &k){
    if(root == NULL) return 0;

    int left = kthSmallest(root->left, k);
    if(left != 0) return left;

    k--;
    if(k == 0) return root->data;

    int right = kthSmallest(root->right, k);
    if(right != 0)
        return right;
    
    return 0;
}

int main(){
    vector<int> a = {1, 2, 8,7,6,3,4,5,6,9,8,7,6};
    Node* root = buildBST(a, 0, 12);

    print(root);
    int k = 6;
    cout<<"Kth smallest : "<<kthSmallest(root, k);
    return 0;
}