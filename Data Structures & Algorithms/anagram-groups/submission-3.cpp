class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            int freq[26] = {0};
            for (char c : word) {
                freq[c - 'a']++;
            }

            // encode freq array as a string key e.g. "1#0#0#1#..."
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& [key, words] : groups) {
            result.push_back(words);
        }

        return result;
    }
};
