class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> hash;
        for(char c : s1){
            ++hash[c];
        }
        std::unordered_map<char, int> resetHash = hash;
        for(int i = 0; i < s2.size() - s1.size() + 1; ++i){
            hash = resetHash;
            for(int j = i; j < i + s1.size(); ++j){
                if(hash.contains(s2[j])){
                    if(--hash[s2[j]] == 0){
                        hash.erase(s2[j]);
                    }
                }
            }
            if(hash.empty()){
                return true;
            }
        }
        return false;
    }
};
