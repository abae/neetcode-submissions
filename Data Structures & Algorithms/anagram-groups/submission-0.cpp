class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> out;
        std::unordered_map<std::string, vector<string>> outMap;
        for (const auto& str : strs){
            std::map<char, int> hash;
            for (const char c : str){
                hash[c]++;
            }
            std::string hashstr;
            for (const auto& pair : hash){
                hashstr += pair.first + std::to_string(pair.second);
            }
            outMap[hashstr].push_back(str);
        }
        for (const auto& pair : outMap){
            out.push_back(pair.second);
        }
        return out;
    }
};