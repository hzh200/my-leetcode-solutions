class Solution {
public:
    int nthUglyNumber(int n) {
        n--;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        q.push(2), q.push(3), q.push(5);
        int index = 0;
        long long ele, cur, prev = 1;
        while (index < n) {
            while (prev != -1 && q.size() > 1 && q.top() == prev) {
                q.pop();
            }
            ele = q.top();
            q.pop();
            cur = ele * 2;
            if (index == n) {
                return cur;
            }
            q.push(cur);
            while (prev != -1 && q.size() > 1 && q.top() == prev) {
                q.pop();
            }
            cur = ele * 3;
            q.push(cur);
            while (prev != -1 && q.size() > 1 && q.top() == prev) {
                q.pop();
            }
            cur = ele * 5;
            q.push(cur);
            cout << ele << " ";
            prev = ele;
            index++;
        }
        return prev;
    }
};