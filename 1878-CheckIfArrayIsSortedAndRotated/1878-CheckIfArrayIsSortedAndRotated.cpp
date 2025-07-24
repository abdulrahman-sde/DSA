// Last updated: 7/24/2025, 11:28:36 AM
// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int n = nums.size();

//         if (nums[0] >= nums[n - 1] ) {
//             // Find max index
//             auto maxIt = max_element(nums.begin(), nums.end());
//             int max_index = distance(nums.begin(), maxIt);

//             // Check ascending from start to max_index
//             for (int i = 0; i < max_index; i++) {
//                 if (nums[i] > nums[i + 1]) {
//                     return false;
//                 }
//             }

//             // Check ascending from max_index+1 to end
//             for (int i = max_index + 1; i < n - 1; i++) {
//                 if (nums[i] > nums[i + 1] && nums[i] != nums[max_index]) {
//                     return false;
//                 }
//             }

//             // Check circular link: last to first
//             if (nums[n - 1] > nums[0]) {
//                 return false;
//             }
//         }
//         else {
//             // Array is already sorted in ascending order
//             for (int i = 1; i < n; i++) {
//                 if (nums[i] < nums[i - 1]) {
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool check(vector<int>& nums) {
        int dip_count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                dip_count++;
            }
        }
        if(nums[nums.size()-1]>nums[0]){
            dip_count++;
        }

        return dip_count<=1;
    }
    };
