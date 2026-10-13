#include <algorithm>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> taskCount;
        int maxFreq = 0;
        int countMax = 0;
        for(char c : tasks){
            ++taskCount[c];
            if(taskCount[c] > maxFreq){
                countMax = 1;
                maxFreq = taskCount[c];
            }else if(taskCount[c] == maxFreq){
                ++countMax;
            }
        }
        return std::max((int)tasks.size(), (maxFreq - 1) * (n + 1) + countMax);
    }
};