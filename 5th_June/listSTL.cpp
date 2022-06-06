#include <iostream>
#include <vector>
#include <list>

using namespace std;

class ll{
    public:
    list<int> l;

    void print(){
        cout<<"\nList : ";
        for(auto i: l){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    void insertAtBegin(int data){
        l.push_front(data);
    }

    void insertAtEnd(int data){
        l.push_back(data);
    }

    void removeAtBegin(){
        l.pop_front();
    }

    void removeAtBack(){
        l.pop_back();
    }

    void reverse(){
        l.reverse();
    }

};

list<int> merge(list<int> l1, list<int> l2){
    list<int> l;
    while(l1.size() != 0 && l2.size() != 0){
        if(l1.front() < l2.front()){
            l.push_back(l1.front());
            l1.pop_front();
        }
        else{
            l.push_back(l2.front());
            l2.pop_front();
        }
    }

    while(l1.size() != 0){
        l.push_back(l1.front());
        l1.pop_front();
    }

    while(l2.size() != 0){
        l.push_back(l2.front());
        l2.pop_front();
    }

    return l;
}

list<int> merge_k(vector<list<int>> v){
    while(v.size() > 1){
        v.push_back(merge(v[0], v[1]));
        v.erase(v.begin());
        v.erase(v.begin());
    }

    return v[0];
}

int main(){
    ll *head = new ll();
    head->insertAtBegin(6);
    head->insertAtBegin(5);
    head->insertAtBegin(4);
    head->insertAtBegin(3);
    head->insertAtBegin(2);
    head->insertAtBegin(1);
    head->insertAtEnd(7);

    head->print();

    return 0;
}