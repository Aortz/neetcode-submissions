class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen; //values = 1
        for (int i = 0; i < nums.size(); ++i){
            if (seen[nums[i]]){
                return true;
            }
            seen[nums[i]] = 1;
        }

        return false;
    }
};