class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> hash;
        for(char c : s1){
            ++hash[c];
        }
        std::unordered_map<char, int> windowHash;
        for(int i = 0; i < s2.size(); ++i){
            ++windowHash[s2[i]];
            if(i >= s1.size()){
                if(--windowHash[s2[i - s1.size()]] == 0){
                    windowHash.erase(s2[i - s1.size()]);
                }
                
            }
            if(hash == windowHash){
                return true;
            }
        }
        return false;
    }
};
