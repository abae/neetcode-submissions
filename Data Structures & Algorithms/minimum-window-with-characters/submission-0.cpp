class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> target;
        int requirements = 0;
        for(char c:t){
            if (!target.contains(c)){
                ++requirements;
            }
            ++target[c];
        }
        
        string out = "";
        std::unordered_map<char, int> freq;
        std::unordered_set<char> completed_req;
        int left = 0;
        int minLen = s.size() + 1;

        for(int right=0; right<s.size(); ++right){
            ++freq[s[right]];
            if (target[s[right]] > 0 && freq[s[right]] >= target[s[right]] && !completed_req.contains(s[right])){
                completed_req.insert(s[right]);
                --requirements;
            }
            if (requirements <= 0){
                while(freq[s[left]] > target[s[left]]){
                    --freq[s[left]];
                    ++left;
                }
                int stringLen = right - left + 1;
                if (stringLen < minLen){
                    minLen = stringLen;
                    out = s.substr(left, stringLen);
                }
            }
            //cout << requirements << ":" << s.substr(left, right - left + 1) << endl;
        }

        return out;
    }
};