class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(auto& str : strs){
            result += std::to_string(str.size()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        bool numInput = true;
        string substr = "";
        string length_str = "";
        int length = 0;
        for(char c : s){
            if(numInput){
                if(c != '#'){
                    length_str += c;
                }else{
                    numInput = false;
                    length = std::stoi(length_str);
                    if(length == 0){
                        result.push_back("");
                        numInput = true;
                    }
                    length_str = "";
                }
            }else{
                if(length > 1){
                    substr += c;
                }else{
                    substr += c;
                    numInput = true;
                    result.push_back(substr);
                    substr = "";
                }
                --length;
            }
        }

        return result;
    }
};
