class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> hist;
        for (const std::string& s:tokens){
            if (s == "+"){
                int v2 = hist.top();
                hist.pop();
                int v1 = hist.top();
                hist.pop();
                hist.push(v1 + v2);
            }else if (s == "-"){
                int v2 = hist.top();
                hist.pop();
                int v1 = hist.top();
                hist.pop();
                hist.push(v1 - v2);
            }else if (s == "*"){
                int v2 = hist.top();
                hist.pop();
                int v1 = hist.top();
                hist.pop();
                hist.push(v1 * v2);
            }else if (s == "/"){
                int v2 = hist.top();
                hist.pop();
                int v1 = hist.top();
                hist.pop();
                hist.push(v1 / v2);
            }else{
                hist.push(std::stoi(s));
            }
        }
        return hist.top();
    }
};