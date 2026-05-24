class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int left = 0;
        int maxFreq = 0;
        int best = 0;

        for(int right = 0; right < static_cast<int>(s.size()); ++right){
            count[s[right]]++;
            maxFreq = max(maxFreq, count[s[right]]);
            while((right -left + 1) - maxFreq > k){
                count[s[left]]--;
                left++;
            }
            // 4. Record best
            best = max(best, right - left + 1);
        }

        return best;
    }
};
