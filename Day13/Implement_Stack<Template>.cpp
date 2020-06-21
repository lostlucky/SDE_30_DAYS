#include <bits/stdc++.h>
using namespace std;

template<class T>
struct ListNode{
    
    T val;
    ListNode<T> *next;
    
    ListNode(T val){
        this -> val = val;
        next = NULL;
    }
    
};

template<class T>
class stk{
    
private:
    int maxSize;
    ListNode<T> *top, *dummyHead;
    
public:
    
    stk(int size){
        maxSize = size;
        if(DatatypeFind(T) == "string") dummyHead = new ListNode<T>( "0" ); // Assuming an function which supports finding datatypes from templates
        else dummyHead = new ListNode<T>(0);
    	top = dummyHead;
    }
    
    void pop(){
        if(top == dummyHead) cout << "Stack Empty" << endl;
        
        else{
            T ret = top -> val;
            ListNode<T> *temp = top -> next;
            top -> next = NULL;
            delete top;
            top = temp;
            cout << ret << " was  popped " << endl;
        }
    }
    
    void push(T value){
        if(maxSize == 0) cout << "Stack Full" << endl;
        else{
            maxSize--;
            ListNode<T> *temp = new ListNode<T>(value);
            temp -> next = top;
            top = temp;
            cout << value << " was inserted " << endl;
        }
    }
    
};

int main() {
    
    stk<double> s(3);
    s.pop();
    s.push(1.0);
    s.push(200.1301);
    s.push(1.44);
    s.push(0.0);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    
	return 0;
}
