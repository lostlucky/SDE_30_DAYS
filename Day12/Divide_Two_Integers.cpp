class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN){
            if(divisor == -1) return INT_MAX;
            if(divisor == 1) return INT_MIN;
        }
        int a = abs(dividend), b = abs(divisor);
        int ans = 0;
        while(a >= b){
            int x = 0;
            if(a >= (b << 1 << x)) x++;
            ans += 1 << x;
            a -= b << x;
        }
        bool sign = (dividend > 0) ^ (divisor > 0);
        return sign ? -ans : ans;
    }
};
