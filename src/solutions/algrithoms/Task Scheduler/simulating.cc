class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26);
        for (const auto& task : tasks) {
            counts[task - 'A']++;
        }
        sort(counts.begin(), counts.end(), [](int x, int y) -> bool {
            return x > y;
        });
        int num = 0;
        for (int i = 0; i < 26; i++) {
            if (counts[i] == counts[0]) {
                num++;
            }
        }
        return max(static_cast<int>(tasks.size()), (n + 1) * (counts[0] - 1) + num);
    }
};