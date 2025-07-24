// Last updated: 7/24/2025, 11:28:40 AM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalsum=0;
        int elesum=0;
        for(int i=0;i<=nums.size();i++){
            totalsum+=i;
        }
        for(int i=0;i<nums.size();i++){
            elesum+=nums[i];
        }
        return totalsum-elesum;
    }
};