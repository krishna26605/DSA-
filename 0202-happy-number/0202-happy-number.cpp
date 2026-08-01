class Solution {
public:

    int func(int n){
        int sum=0;
        int d;
        while(n>0){
            d= n%10;
            n= n/10;
            sum=sum+d*d;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        while(slow!=1){
            slow=func(slow);
            fast=func(fast);
            fast=func(fast);

            if(slow==fast && fast!=1){
                return false;
            }
        }
        return true;
    }
};