class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        std::unordered_map<char, int> seen;
        for (char c : s){
            seen[c]++;
        }
        for (char c : t){
            seen[c]--;
        }
        return std::all_of(seen.begin(), seen.end(), 
            [](const auto& pair){
                return pair.second == 0;
            });
    }
};