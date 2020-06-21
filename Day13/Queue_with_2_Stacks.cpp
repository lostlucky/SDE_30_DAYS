#include <iostream>
#include <stack>
using namespace std;

class queue{
	
private:
	stack<int>s1, s2;
	int frontVal;
	
public:
	
	void push(int value){
		cout << value <<" was pushed" << endl;
		if(!s1.empty()) frontVal = value;
		s1.push(value);
	}
	
	void pop(){
		if(s1.empty()){
			cout << "Stack is full";
			return;
		} 
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		int toPop = s2.top();
		s2.pop();
		if(!s2.empty()) frontVal = s2.top();
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		cout << toPop << " was popped" << endl;
	}
	
	void calSize(){
		cout << "Current Size of queue is " << s1.size() << endl;
	}
	
	void front(){
		if(!s1.size()) cout << "Stack Empty" << endl;
		else cout << "Front is " << frontVal << endl;
	}
	
};

int main() {
	
	queue q;
	q.push(1);
	q.push(2);
	q.push(3535);
	q.push(0);
	q.push(23);
	q.pop();
	q.calSize();
	q.front();
	q.front();
	q.pop();
	q.front();
	
	return 0;
}
