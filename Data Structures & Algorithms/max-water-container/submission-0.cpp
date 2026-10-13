class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxOut = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right){
            int contHeight = std::min(height[left], height[right]); 
            int contWidth = right - left;
            if(contWidth * contHeight > maxOut){
                maxOut = contWidth * contHeight;
            }
            if (height[left] < height[right]){
                ++left;
            }else{
                --right;
            }
        }
        return maxOut;
    }
};