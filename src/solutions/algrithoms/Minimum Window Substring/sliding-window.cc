class Solution {
    unordered_map<char, int> cover;
    unordered_map<char, int> full;
public:
    bool check(string& t) {
        for (auto iter = cover.begin(); iter != cover.end(); iter++) {
            if (cover[iter->first] < full[iter->first]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int left = 0, right = 0, n = s.size();
        for (auto c : t) {
            cover[c] = 0;
            if (full.find(c) == full.end()) {
                full[c] = 1;
            } else {
                full[c]++;
            }
        }
        while (right < n) {
            cover[s[right]]++;
            if (check(t)) {
                break;
            }
            right++;
        }
        if (right == n) {
            return "";
        }
        int res = right - left + 1;
        int resRight = right;
        int resLeft = left;
        while (right < n) {
            while (check(t) && left <= right) {
                if (right - left < res) {
                    res = right - left;
                    resLeft = left;
                    resRight = right;
                }
                cover[s[left]]--;
                left++;
            }
            right++;
            if (right == n) {
                break;
            }
            cover[s[right]]++;
            if (check(t)) {
                if (right - left < res) {
                    res = right - left;
                    resLeft = left;
                    resRight = right;
                }
            }
        }
        return s.substr(resLeft, resRight - resLeft + 1);
    }
};