class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            string sortedKey = word;
            // Sort the string to create a unique identifier for its anagram group
            sort(sortedKey.begin(), sortedKey.end());

            groups[sortedKey].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& [key, words] : groups) {
            result.push_back(words);
        }

        return result;
    }
};
