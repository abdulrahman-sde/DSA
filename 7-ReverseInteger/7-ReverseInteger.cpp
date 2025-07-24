// Last updated: 7/24/2025, 11:28:46 AM
class Solution {
public:
    int reverse(int c) {
        int orignal=c;
        long x=c;
        if(x < 0){
            x=-x;
        }
        long reverse = 0;
        while (x > 0) {
            int digit = x % 10;
            if (reverse > INT_MAX/10){
                return 0;
            }
            reverse=reverse*10+digit;
            x=x/10;
        }
        return orignal<0?reverse*-1:reverse;
    }
};