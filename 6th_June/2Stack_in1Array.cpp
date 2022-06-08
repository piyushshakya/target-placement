#include <iostream>

using namespace std;

class stack{
    int capacity;
    int topp1, topp2;
    int *arr;

    public:
    stack(int size){
        arr = new int[size];
        capacity = size;
        topp1 = -1;
        topp2 = size;
    }

    void push1(int element){
        if(topp2 - topp1 > 1){
            arr[++topp1] = element;
        }
        else
            cout<<"Stack Overflow"<<endl;
    }

    void push2(int element){
        if(topp2 - topp1 > 1){
            arr[--topp2] = element;
        }
        else
            cout<<"Stack Overflow"<<endl;
    }
    
    int top1(){
        if(topp1 >= 0)
            return arr[topp1];
        
        cout<<"Stack Empty"<<endl;
        return -1;
    }
    
    int top2(){
        if(topp2 < capacity)
            return arr[topp2];
        
        cout<<"Stack Empty"<<endl;
        return 0;
    }

    void pop1(){
        if(topp1 >= 0)
            topp1--;
        else
            cout<<"Stack Underflow"<<endl;
    }

    void pop2(){
        if(topp2 < capacity)
            topp2--;
        else
            cout<<"Stack Underflow"<<endl;
    }
};

int main(){
    stack s(6);
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push1(4);
    s.push2(15);
    s.push2(16);
    s.push2(17);

    cout<<s.top1()<<" "<<s.top2()<<endl;
    s.pop1();
    cout<<s.top1()<<" "<<s.top2()<<endl;
    s.pop1();
    cout<<s.top1()<<" "<<s.top2()<<endl;
    s.pop2();
    cout<<s.top1()<<" "<<s.top2()<<endl;
    s.pop2();
    cout<<s.top1()<<" "<<s.top2()<<endl;
    s.pop1();
    cout<<s.top1()<<" "<<s.top2()<<endl;
    return 0;
}