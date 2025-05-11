class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            std::map<int, int> numsMap;    
    
            for (int i = 0; i < nums.size(); ++i){
                int complement = target - nums[i];
    
                auto item = numsMap.find(complement);
                if (item != numsMap.end()){
                    return {numsMap[complement], i};
                }
                
                numsMap[nums[i]] = i;
            }
    
            return {};
        }
};