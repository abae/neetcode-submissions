class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> match{
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
        };
        std::vector<char> hist;
        for (char c:s){
            if (c == '{' || c == '(' || c =='['){
                hist.push_back(c);
            }else{
                if (hist.empty()){
                    return false;
                }
                if (match[hist.back()] == c){
                    hist.pop_back();
                }else{
                    return false;
                }
            }
        }
        return hist.empty();
    }
};