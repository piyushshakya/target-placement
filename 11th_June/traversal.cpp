#include "tree.cpp"

void DFS(treeNode<int>* root){
    if(root == NULL) return;
    cout<<root->data<<" ";

    for(int i = 0; i < root->children.size(); i++){
        DFS(root->children[i]);
    }
}

void BFS(treeNode<int>* root){
    if(root == NULL) return;

    queue<treeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        treeNode<int> * f = q.front();
        q.pop();

        cout<<f->data<<" ";
        for(int i = 0; i < f->children.size(); i++){
            q.push(f->children[i]);
        }
    }
    cout<<endl;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main(){
    treeNode<int>* root = takeInput();
    BFS(root);
    DFS(root);

    return 0;
}