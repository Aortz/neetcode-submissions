class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int left = 0;
        int maxFreq = 0;   // Most frequent character count in current window
        int best = 0;
        
        for (int right = 0; right < (int)s.size(); ++right) {
            // 1. Expand: Add s[right] to window
            count[s[right]]++;
            
            // 2. Update maxFreq: Check if current char is new most frequent
            maxFreq = max(maxFreq, count[s[right]]);
            
            // 3. Shrink while invalid: 
            // If (window size - most frequent char) > k, we need more than k replacements
            while ((right - left + 1) - maxFreq > k) {
                count[s[left]]--;
                left++;
                // Note: We don't strictly need to recalculate maxFreq here.
                // Keeping maxFreq as the "historical high" for this window size
                // is sufficient for this algorithm to work correctly.
            }
            
            // 4. Record best
            best = max(best, right - left + 1);
        }

        return best;
    }
};
