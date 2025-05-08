class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                    if (stk.empty()) {
                        len = i + 1;
                    } else {
                        len = max(len, i - stk.top());
                    }
                } else {
                    stk.push(i);
                }
            } 
        }
        return len;
    }
};