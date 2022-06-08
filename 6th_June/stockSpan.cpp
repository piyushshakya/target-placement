#include <bits/stdc++.h>

using namespace std;

vector<int> span(vector<int> arr){
    int n = arr.size();
    vector<int> bge(n);
    stack<int> s;
    s.push(0);
    bge[0] = 1;

    for(int i = 1; i < n; i++){
        while(s.size() > 0 && arr[i] > arr[s.top()])
            s.pop();
        if(s.empty())
            bge[i] = i+1;
        else
            bge[i] = i - s.top();
        
        s.push(i);
    }  

    return bge;
}

int main(){
    vector<int> res, ele = {6, 8, 0, 1, 3};
    res = span(ele);

    for(int i : res){
        cout<<i <<" ";
    }

    return 0;
}