#include "implementation.cpp"

void succPre(Node* root, Node* &succ, Node* &pre, int key){
    if(root == NULL) return;

    if(root->data == key){
        if(root->left != NULL){
            Node* temp = root->left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            pre = temp;
        }

        if(root->right != NULL){
            Node* temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            succ = temp;
        }

        return;
    }

    else if(key > root->data){
        pre = root;
        succPre(root->right, succ, pre, key);
    }   
    else{
        succ = root;
        succPre(root->left, succ, pre, key);
    }
}

void inOrder_SucPre(Node* root, vector<int> &ans){
    if(root == NULL) return ;

    inOrder_SucPre(root->left, ans);
    ans.push_back(root->data);
    inOrder_SucPre(root->right, ans);
}

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    Node* pre = NULL, *succ = NULL;
    Node* root = buildBST(a, 0, 8);
    succPre(root, succ, pre, 9);
    print(root);
    cout<<endl;


    cout<<"\nPredecor : ";
    (pre != NULL) ? cout<<pre->data : cout<<"NULL ";
    
    cout<<"\nSuccesor : ";
    (succ != NULL) ? cout<<succ->data : cout<<"NULL";

    vector<int> inorder;
    inOrder_SucPre(root, inorder);

    int ind = -1;
    int k = 9;
    for(int i = 0; i < inorder.size(); i++){
        if(inorder[i] == k)
            ind = i;
    }

    if(ind == -1)
        cout<<"\nsucc & pre not exist";
    else if(ind == 0)
        cout<<"\nsucc : "<<inorder[ind+1]<<"\nPre not exist.";
    else if(ind == inorder.size()-1)
        cout<<"\nsucc not exist"<<"\nPre : "<<inorder[ind-1];
    else{
        cout<<"\nSucc : "<<inorder[ind+1]<<"\nPre : "<<inorder[ind-1];
    }

    return 0;
}