#include "tree.cpp"

int height(treeNode<int>* root){
    if(root == NULL)
        return 1;
    
    int h = 0;
    for(int i = 0; i < root->children.size(); i++){
        h = max(h, height(root->children[i]));
    }

    return h+1;
}

int diameter(treeNode<int>* root){
    if(root == NULL) return 0;

    int max1 = 0, max2 = 0;
    for(int i = 0; i < root->children.size(); i++){
        int h = height(root->children[i]);
        if(max1 < h){
            max2 = max1;
            max1 = h;
        }
        int d = diameter(root->children[i]);
    }
    
    int d = 0;
    for(int i = 0; i < root->children.size(); i++){
        d = max(d, diameter(root->children[i]));
    }

    return max(d, max1+max2+1);
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main(){
    treeNode<int>* root = takeInput();
    printTree(root);
    cout<<"\nHeight : "<<height(root);
    cout<<"\nDiameter : "<<diameter(root);
    return 0;
}