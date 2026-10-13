class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        std::unordered_map<char, int> seen;
        seen[s[0]] = 0;
        int left = 0;
        int right = 1;
        int maxLen = 1;
        while(right < s.size()){
            //std::cout << left << "," << right << std::endl;
            auto it = seen.find(s[right]);
            //match found
            if(it != seen.end() && left <= it -> second){
                left = it->second + 1;
                seen[s[right]] = right;
                ++right;
            }else{
                //std::cout << s[right] << std::endl;
                seen[s[right]] = right;
                ++right;
                if (right - left > maxLen){
                    maxLen = right - left;
                }
            }
        }
        return maxLen;
    }
};