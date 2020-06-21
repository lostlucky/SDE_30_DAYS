#include <iostream>
#include <queue>
using namespace std;

class stack{
	
private:
	queue<int>q;
	int topVal;
	
public:
	
	void push(int value){
		topVal = value;
		q.push(value);
		cout << value << " was pushed" << endl;
	}
	
	void pop(){
		int n = q.size();
		if(!n) cout << "Stack is empty" << endl;
		else{
			int val;
			while(--n){
				val = q.front();
				q.pop();
				q.push(val);
				if(n == 1) topVal = val;
			}
			val = q.front();
			q.pop();
			cout << val << " was popped" << endl;
		}
	}
	
	void calSize(){
		cout << "Current size of stack is "<< q.size() << endl;
	}
	
	void top(){
		if(!q.size()) cout << "Stack Empty" << endl;
		else cout << topVal << endl;
	}
	
};

int main() {
	
	stack s;
	s.push(1);
	s.push(2);
	s.push(3535);
	s.push(0);
	s.push(23);
	s.pop();
	s.calSize();
	s.top();
	s.top();
	s.pop();
	s.top();
	
	return 0;
}
