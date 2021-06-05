class Solution {
public:
    bool isPalindrome(long long x) {
        bool res = false;
        long long tmp = x, revX = 0;
        
        if(x < 0) return res;
        
        while(tmp > 0) {
            revX = (revX * 10) + (tmp % 10);
            tmp /= 10;
        }
        if(x == revX) res = true;
        
        return res;
    }
};