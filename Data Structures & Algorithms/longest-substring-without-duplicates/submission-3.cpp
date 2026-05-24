class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0;
        int best = 0;

        for(int right = 0; right < static_cast<int>(s.size()); ++right){
            while(window.count(s[right])){
                window.erase(s[left]);
                ++left;
            }
            window.insert(s[right]);
            best = max(best, right - left + 1);

        }

        return best;
    }
};
