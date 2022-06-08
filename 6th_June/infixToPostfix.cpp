#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int precedence(char c){
    if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfix(string exp){
    stack<string> post;
    stack<char> oper;
    string res;
    for(char ch : exp){
        // cout<<ch<<" ";
        if(ch == '('){
            oper.push(ch);
        }
        else if(ch == ')'){
            while(oper.top() != '('){
                string v2 = post.top();
                post.pop();
                string v1 = post.top();
                post.pop();
                char op = oper.top();
                oper.pop();
                string x = v1 + v2 + op + "";
                post.push(x);
            }
            oper.pop();
        }
        else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') 
        || (ch >= '1' && ch >= '9')){
            post.push(""+ch);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(oper.size() > 0 && oper.top() != '(' 
            && precedence(ch) <= precedence(oper.top())){
                string v2 = post.top();
                post.pop();
                string v1 = post.top();
                post.pop();
                char op = oper.top();
                oper.pop();
                string x = v1 + v2 + op + "";
                post.push(x);
            }
            oper.push(ch);
        }
    }

    while(oper.size() > 0){
        string v2 = post.top();
        post.pop();
        string v1 = post.top();
        post.pop();
        char op = oper.top();
        oper.pop();
        string x = v1 + v2 + op + "";
        post.push(x);
    }

    // cout<<"size"<<post.size()<<endl;
    string ans = post.top();
    post.pop();

    return ans;
}

int main(){
    vector<string> s = {"a+b*(c^d-e)^(f+g*h)-i", "A*(B+C)/D", "1*(2-3)/4+5"};
    string exp = "a+b/c";
    cout<<"a+b  "<<infixToPostfix(exp)<<endl;
    for(string i : s){
        cout<<i<<" : "<< infixToPostfix(i)<<endl;
    }

    return 0;
}