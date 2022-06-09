#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class queue{
    stack<int> s1, s2;

    public:
    void push(int data){
        s1.push(data);
    }

    int pop(){
        if(s1.empty()) {
            cout<<"Queue is Empty.";
            return INT_MIN;
        }

        while(!s1.empty()){
            int d = s1.top();
            s1.pop();
            s2.push(d);
        }

        int ans = s2.top();
        s2.pop();

        while(!s2.empty()){
            int d = s2.top();
            s2.pop();
            s1.push(d);
        }

        return ans;
    }

    int front(){
        if(s1.empty()) {
            cout<<"Queue is Empty.";
            return INT_MIN;
        }
        while(!s1.empty()){
            int d = s1.top();
            s1.pop();
            s2.push(d);
        }

        int ans = s2.top();

        while(!s2.empty()){
            int d = s2.top();
            s2.pop();
            s1.push(d);
        }

        return ans;
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout<<"Front : "<<q.front()<<endl;
    cout<<q.pop()<<endl;
    cout<<"Front : "<<q.front()<<endl;
    cout<<q.pop()<<endl;
    cout<<"Front : "<<q.front()<<endl;
    cout<<q.pop()<<endl;
    cout<<"Front : "<<q.front()<<endl;
    cout<<q.pop()<<endl;
    cout<<"Front : "<<q.front()<<endl;
    cout<<q.pop()<<endl;
    cout<<"Front : "<<q.front()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

    return 0;
}
