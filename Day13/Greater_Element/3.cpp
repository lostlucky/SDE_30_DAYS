class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        if(s.size() == 10 and s > to_string(INT_MAX)) return -1;
        int ans = stoi(s);
        return ans > n ? ans : -1;
    }
};
