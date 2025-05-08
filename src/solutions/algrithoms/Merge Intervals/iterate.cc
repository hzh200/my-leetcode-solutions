
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) -> bool {
            if (v1[0] < v2[0]) {
                return 1;
            } else if (v1[0] > v2[0]) {
                return 0;
            }
            return v1[1] > v2[1];
        });
        // cout << intervals[0][0] << endl;
        int index = 1;
        res.push_back(intervals[0]); 
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > res[index - 1][1]) {
                res.push_back(intervals[i]);
                index++;
            } else if (intervals[i][1] > res[index - 1][1]) {
                res[index - 1][1] = intervals[i][1];
            }
        }
        return res;
    }
};