// Last updated: 7/24/2025, 11:28:38 AM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int maxCount=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                maxCount++;
                maxi=max(maxi,maxCount);
            }else{
                maxCount=0;
            }
        }
        return maxi;
    }
};