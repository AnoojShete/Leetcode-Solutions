class Solution {
public:
    bool isSymm(string s, int n) {
        int sum = 0;
        for(int i = 0; i < n / 2; ++i) {
            sum += s[i] - '0';
        }
        for(int i = n / 2; i < n; ++i) {
            sum -= s[i] - '0';
        }
        cout << "sum = " << sum << endl;
        return sum == 0;
    }
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int num = low; num <= high; ++num) {
            string s = to_string(num);
            int len = s.length();
            if(len % 2 != 0) continue;
            if(isSymm(s, len)) {
                cout << s << endl;
                count++;
            }
        }
        return count;
    }
};