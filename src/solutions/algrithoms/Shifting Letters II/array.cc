class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diffs(s.size() + 1);
        for (auto shift : shifts) {
            if (shift[2] == 1) {
                diffs[shift[0]] += 1;
                diffs[shift[1] + 1] -= 1;
            } else {
                diffs[shift[0]] -= 1;
                diffs[shift[1] + 1] += 1;
            }
        }
        int change = 0;
        stringstream ss("");
        for (int i = 0; i < s.size(); i++) {
            change += diffs[i];
            if (change < 0) {
                change = change + (-change / 26 + 1) * 26;
            }
            char c = 'a' + (s[i] - 'a' + change) % 26;
            ss << c;
        }
        return ss.str();
    }
};