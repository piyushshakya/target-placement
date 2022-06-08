#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void stackUsingQ(vector<int> v){
    queue<int> q1, q2;

    for(int i : v){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(i);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }

    while(!q1.empty()){
        cout<<q1.front()<<" ";
        q1.pop();
    }
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    stackUsingQ(v);
    return 0;
}