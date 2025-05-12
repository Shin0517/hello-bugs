class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) {
                return "";
            } 
            
            sort(strs.begin(), strs.end());
            auto first = strs.front();
            auto last = strs.back();
    
            int i = 0;
            while (i < first.length() && i < last.length() && first[i] == last[i]){
                i++;
            }
            
            return first.substr(0, i);
        }
};