class Solution {
public:
    bool isValid(string s) {
        if(s.size() & 1) return 0;
        stack<char>stk;
        for(auto x:s){
            if(x == '(' or x == '{' or x == '[') stk.push(x);
            else{
                
                if(stk.empty()) return 0;
                if(x == ')'){
                    if(stk.top() != '(') return 0;
                    else stk.pop();
                }
                
                if(x == '}'){
                    if(stk.top() != '{') return 0;
                    else stk.pop();
                }
                
                if(x == ']'){
                    if(stk.top() != '[') return 0;
                    else stk.pop();
                }
                
            }
        }
        return stk.empty();
    }
};
