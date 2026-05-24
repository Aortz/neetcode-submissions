class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;  // can't fit
        
        unordered_map<char, int> need;
        for (char c : s1) need[c]++;
        int needDistinct = need.size();
        int matched = 0;

        // Step 1: build initial window of size s1.size()
        unordered_map<char, int> window;
        int left = 0;

        // Step 3: slide window across rest of s2
        for (int right = 0; right < (int)s2.size(); ++right) {
            //  - enter s2[right]
            char in = s2[right];
            if (need.count(in)) {
                window[in]++;
                if (window[in] == need[in]) matched++;
            }

            // Shrink window if size exceeds s1
            if (right - left + 1 > (int)s1.size()) {
                //  - leave s2[left]
                char out = s2[left];
                if (need.count(out)) {
                    if (window[out] == need[out]) matched--;
                    window[out]--;
                }
                left++;
            }
            
            //  - check matched == needDistinct
            if (matched == needDistinct) return true;
        }

        return false;
    }
};
