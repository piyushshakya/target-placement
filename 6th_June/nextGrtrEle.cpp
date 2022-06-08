#include <bits/stdc++.h>

using namespace std;

vector<int> ngtr(vector<int> arr){
    int n = arr.size();

    vector<int> nge(n);
    stack<int> s;
    s.push(arr[n-1]);
    nge[n-1] = -1;

    for(int i = n-2; i >= 0; i--){
        while(s.size() > 0 && arr[i] >= s.top())
            s.pop();
        
        if(s.empty())
            nge[i] = -1;
        else
            nge[i] = s.top();

        s.push(arr[i]);
    }

    return nge;
}

int main(){
    vector<int> res, ele = {6, 8, 0, 1, 3};
    res = ngtr(ele);

    for(int i : res){
        cout<<i <<" ";
    }

    return 0;
}