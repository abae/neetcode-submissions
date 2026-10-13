class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto num:nums){
            hash.insert(num);
        }
        int maxChain = 0;
        while(!hash.empty()){
            int chain = 1;
            int start = *hash.begin();
            int i = start;
            hash.erase(start);
            while(hash.find(--i) != hash.end()){
                ++chain;
                hash.erase(i);
            }
            i = start;
            while(hash.find(++i) != hash.end()){
                ++chain;
                hash.erase(i);
            }
            if (chain > maxChain){
                maxChain = chain;
            }
        }
        return maxChain;
    }
};