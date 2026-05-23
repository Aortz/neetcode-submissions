class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> freq_map;
        for (char c : s) {
            freq_map[c]++;
        }
        for (char c : t) {
            if (--freq_map[c] < 0) return false;
        }
        return true;
        }
};
