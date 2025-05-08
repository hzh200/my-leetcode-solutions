class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> v1, vector<int> v2) -> bool {
            return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
        });
        int n = people.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (res.size() <= people[i][1]) {
                res.push_back(people[i]);
            } else {
                res.insert(res.begin() + people[i][1], people[i]);
            }
        }
        return res;
    }
};