class Solution {
public:
    bool isCollision(char a, char b) {
        return (a == 'R' && b == 'L' ) || (a == 'S' && b == 'L') || (a == 'R' && b == 'S');
    }
    int countCollisions(string directions) {
        stack<char> st;
        int count = 0;
        for(auto ch : directions) {
            while(!st.empty() && isCollision(st.top(), ch)) {
                char top = st.top(); st.pop();
                if(top == 'S' || ch == 'S') count++;
                else count += 2;
                ch = 'S';
            }
            st.push(ch);
        }
        return count;
    }
};