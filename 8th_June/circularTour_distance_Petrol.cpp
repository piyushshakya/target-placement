// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n){
        int sum = 0, start = 0, bal = 0;
        for(int i = 0; i < n; i++){
            sum += p[i].petrol - p[i].distance;
            
            if(sum < 0){
                bal += sum;
                sum = 0;
                start = i+1;
            }
        }
        
        if(bal + sum < 0) return -1;
        return start;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[10000];

        for(int i=0; i<n; i++)
            cin>>p[i].petrol>>p[i].distance;

        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends