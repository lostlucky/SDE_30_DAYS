class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>map(128, 0);
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head;
        for(auto ch:t) map[(int) ch]++;
        while(end < s.size()){
            if(map[s[end++]]-- > 0) counter--;
            while(counter == 0){
                if(d > end - begin){
                    head = begin;
                    d = end - head;
                }
                if(map[s[begin++]]++ == 0) counter++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
