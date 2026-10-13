class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        auto maxit = std::max_element(height.cbegin(), height.cend());
        int peak_i = std::distance(height.cbegin(), maxit);
        for(int i = 0; i < peak_i; ++i){
            if(height[i] < height[i+1]){
                continue;
            }
            int puddleHeight = height[i];
            int puddleSize = 0;
            for(int j = i + 1; j < peak_i + 1; ++j){
                if(height[j] >= puddleHeight){
                    i = j-1;
                    result += puddleSize;
                    break;
                }
                puddleSize += puddleHeight - height[j];
                // cout << i << ":" << j << "\n";
            }
        }
        for(int i = height.size() - 1; i > peak_i; --i){
            if(height[i] < height[i-1]){
                continue;
            }
            int puddleHeight = height[i];
            int puddleSize = 0;
            for(int j = i - 1; j > peak_i - 1; --j){
                if(height[j] >= puddleHeight){
                    i = j+1;
                    result += puddleSize;
                    break;
                }
                puddleSize += puddleHeight - height[j];
                // cout << i << ":" << j << "\n";
            }
        }
        return result;
    }
};
