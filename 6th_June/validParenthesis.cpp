#include <bits/stdc++.h>

using namespace std;

bool matches(char c, char b){
    if((c == '(' && b == ')') || (c == '{' && b == '}') 
       || (c == '[' && b == ']'))
        return true;
    return false;
}

bool isValidParenthesis(string exp){
    if(exp.size() == 0) return true;
    
    stack<char> s;
    
    for(char ch : exp){
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);    
        }
        else{
            if(!s.empty() && matches(s.top(), ch))
                s.pop();
            else
                return false;
        }
    }
    if(s.empty())     
        return true;
    return false;
}

bool isRedundantBracket(string exp){
    stack<char> s;

    for(auto ch : exp){
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
            s.push(ch);
        else{ // either ) or any alphabet
            if(ch == ')'){
                bool isRedundent = true;
                while(s.top() != '('){
                    int top = s.top();
                    s.pop();

                    if(top == '+' || top == '-' || top == '*' || top == '/' || top == '%' || top == '^')
                        isRedundent = false;
                }

                if(isRedundent == true)
                    return true;
                
                s.pop();
            }
        }
    }

    return false;
}

int main(){
    vector<string> list = {"[]", "[[]{}([]{})]", "[]]", "[][", "[", "]["};

    for(auto exp : list){
        if(isValidParenthesis(exp))
            cout<<exp<<" : Balanced"<<endl;
        else
            cout<<exp<<" : Not Balanced" <<endl;
    }

    return 0;
}