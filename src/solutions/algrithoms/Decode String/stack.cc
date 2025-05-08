class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                int index = i;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    i++;
                }
                stk.push(s.substr(index, i - index));
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                int index = i;
                while (i < n && s[i] >= 'a' && s[i] <= 'z') {
                    i++;
                } 
                stk.push(s.substr(index, i - index));
            } else if (s[i] == '[') {
                stk.push("[");
                i++;
            } else {
                stringstream ss;
                stack<string> stk1;
                while (stk.top() != "[") {
                    stk1.push(stk.top());
                    stk.pop();
                }
                while (!stk1.empty()) {
                    ss << stk1.top();
                    stk1.pop();
                }
                stk.pop();
                string times = stk.top();
                stk.pop();
                stringstream new_ss;
                for (int k = 0; k < stoi(times); k++) {
                    new_ss << ss.str();
                }
                stk.push(new_ss.str());
                i++;
            }
        }
        stringstream ss;
        stack<string> stk1;
        while (!stk.empty()) {
            stk1.push(stk.top());
            stk.pop();
        }
        while (!stk1.empty()) {
            ss << stk1.top();
            stk1.pop();
        }
        return ss.str();
    }
};