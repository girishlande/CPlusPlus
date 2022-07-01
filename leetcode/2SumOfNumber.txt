// return the index of 2 numbers whose sum is equal to target.
// Logic is sort the vector and then iterate from front and rear side. 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        vector<int> numscopy = nums;
        sort(nums.begin(), nums.end());
        
        for (size_t i=0, j = nums.size()-1;i<j;) {
            
            if(nums[i]+nums[j]==target) {
                for (size_t k = 0; k<nums.size();k++) {
                    if (numscopy[k]==nums[i] || numscopy[k]==nums[j]) {
                        output.push_back(k);
                    }
                    if (output.size()==2) {
                        sort(output.begin(),output.end());
                        return output;
                    }
                }
            } else if (nums[i]+nums[j]<target) {
                i++;
            } else {
                j--;
            }
            
        }
        return output;
    }
};