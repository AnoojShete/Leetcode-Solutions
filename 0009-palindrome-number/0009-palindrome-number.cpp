class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        else{
            long long n;
            long long temp = x;
            long long sum=0;
            while(temp!=0){
                n = temp%10;
                sum = sum*10 + n;
                temp/=10;
            }
            cout<<sum<<" "<<temp<<" "<<x<<endl;
            return sum == x;
        }
    }
};