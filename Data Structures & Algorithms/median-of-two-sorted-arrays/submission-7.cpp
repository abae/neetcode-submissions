class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> searchArray;
        vector<int> auxArray;
        if(nums2.size() < nums1.size()){
            searchArray = nums2;
            auxArray = nums1;
        }else{
            searchArray = nums1;
            auxArray = nums2;
        }
        int left = -1;
        int right = searchArray.size();
        int totSize = searchArray.size() + auxArray.size();
        while(true){
            int mid = left + ((right - left) / 2);
            int searchLeft = mid >= 0 ? searchArray[mid] : INT_MIN;
            int searchRight = mid + 1 < searchArray.size() ? searchArray[mid + 1] : INT_MAX;
            int half = (totSize + 1) / 2;
            int aux_i = half - 2 - mid;
            int auxLeft = aux_i >=0 ? auxArray[aux_i] : INT_MIN;
            int auxRight = aux_i + 1 < auxArray.size() ? auxArray[aux_i + 1] : INT_MAX;
            if(std::max(searchLeft, auxLeft) <= std::min(searchRight, auxRight)){
                if(totSize % 2 == 0){
                    return (double)(std::max(searchLeft, auxLeft) + std::min(searchRight, auxRight)) / 2.f;
                }else{
                    return (double)(std::max(searchLeft, auxLeft));
                }
            }else if(searchLeft > auxRight){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
    }
};
