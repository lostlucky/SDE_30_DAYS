class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        vector<int>pascal = {1,1};
        while(--rowIndex){
            int curr = 1;
            for(int i = 1;i < pascal.size();i++){
                int currNow = pascal[i];
                pascal[i] += curr;
                curr = currNow;
            }
            pascal.push_back(1);
        }
        return pascal;
    }
};
