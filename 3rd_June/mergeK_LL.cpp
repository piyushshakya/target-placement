// Leetcode solution (Simple Solution)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* h1, ListNode* h2){
        if(h1 == NULL && h2 == NULL) return NULL;
        
        if(h1 == NULL) return h2;
        if(h2 == NULL) return h1;
        
        if(h1->val < h2->val){
            h1->next = merge(h1->next, h2);
            return h1;
        }
        
        h2->next = merge(h1, h2->next);
        return h2;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() < 1) return NULL;
        
        while(lists.size() > 1){
            lists.push_back(merge(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        
        return lists[0];
    }








// GFG solution (Using MinHeap)

// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
  struct compare{
        bool operator()(Node* a, Node* b){
            return a->data >= b->data; 
        }
    };
    
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
        if(K == 0) return NULL;
        
        priority_queue<Node*, vector<Node*>, compare> pq;
        
        Node* res = new Node(0);
        Node* tail = res;
        
        for(int i = 0; i < K; i++)
            if(arr[i] != NULL)
                pq.push(arr[i]);
        
        if(pq.empty()) return NULL;
            
        while(!pq.empty()){
            Node* f = pq.top();
            pq.pop();
            
            tail->next = f;
            tail = tail->next;
            
            if(f->next)
                pq.push(f->next);
        }
        
        return res->next;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends