// Time Limit Exceed
// c++ 优先队列没有删除元素的函数
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> ps;
        for (auto building : buildings) {
            ps.push_back(make_pair(building[0], -building[2]));
            ps.push_back(make_pair(building[1], building[2]));
        }

        sort(ps.begin(), ps.end(), [](pair<int, int> p1, pair<int, int> p2) -> bool {
            if (p1.first != p2.first) {
                return p1.first < p2.first;
            }
            return p1.second < p2.second;
        });

        // for (auto point: ps) {
        //     cout << point.first << " " << point.second << endl;
        // }

        priority_queue<int, vector<int>, less<int>> queue;
        int prev = 0;
        queue.push(prev);
        vector<vector<int>> ans;
        for (pair<int, int> point: ps) {
            if (point.second < 0) {
                queue.push(-point.second);
            } else {
                vector<int> tmp;
                while (true) {
                    int ele = queue.top();
                    queue.pop();
                    if (ele == point.second) {
                        break;
                    }
                    tmp.push_back(ele);
                }
                for (int ele: tmp) {
                    queue.push(ele);
                }
            }
            int cur = queue.top();
            if (prev != cur) {
                vector<int> an;
                an.push_back(point.first);
                an.push_back(cur);
                ans.push_back(an);
                prev = cur;
            }
        }
        return ans;
    }
};