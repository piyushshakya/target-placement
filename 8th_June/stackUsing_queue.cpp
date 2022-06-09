#include <iostream>
#include <queue>

using namespace std;

class stack{
    queue<int> q1, q2;

    public:
    void push(int data){
        while(!q1.empty()){
            int d = q1.front();
            q1.pop();
            q2.push(d);
        }

        q1.push(data);

        while(!q2.empty()){
            int d = q2.front();
            q2.pop();
            q1.push(d);
        }
    }

    int pop(){
        if(q1.empty()){
            cout<<"Stack is Empty."<<endl;
            return -1;
        }

        int res = q1.front();
        q1.pop();

        return res;
    }

    int top(){
        if(q1.empty()){
            cout<<"Stack is Empty."<<endl;
            return -1;
        }

        return q1.front();
    }
};


int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout<<"Top : "<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<"Top : "<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<"Top : "<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<"Top : "<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<"Top : "<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<"Top : "<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<"Top : "<<s.top()<<endl;
    cout<<s.pop()<<endl;
    return 0;
}