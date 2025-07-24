// Last updated: 7/24/2025, 11:56:49 AM
class Solution {
    // Brute will be checking count of each element using two for loops if its 1 return element;
    // Better will be using hashmap
    // Bit manipulation will be optimal 
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int,int> freq;
        for(auto num:nums){
            freq[num]++;
        }
        for(auto it:freq){
            if(it.second==1){
                return it.first;
            }

        }
        return -1;
    }
};