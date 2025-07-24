// Last updated: 7/24/2025, 11:28:44 AM
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int orignal=x;
        long reversed=0;
        while(x>0){
            int digit=x%10;
            reversed=reversed*10+digit;
            x=x/10;
        }
        return orignal==reversed?true:false;
    }
};