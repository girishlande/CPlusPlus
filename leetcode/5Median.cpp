Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ma;
        size_t i=0;
        size_t j=0;
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i]<nums2[j]) {
                ma.push_back(nums1[i]);
                i++;
            } else {
                ma.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i<nums1.size()) {
                ma.push_back(nums1[i]);
                i++;
        }
        
        while(j<nums2.size()) {
               ma.push_back(nums2[j]);
               j++;
        }

        if (ma.size()%2==0) {
            return double(ma[ma.size()/2] + ma[ma.size()/2-1])/2;
        } 
        return ma[ma.size()/2];
               
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ma;
        size_t i=0;
        size_t j=0;
        size_t med = nums1.size() + nums2.size();
        size_t eSize = 0;
        bool oddFlag = false;
        if (med%2==0) {
            eSize = med / 2 + 1;
            oddFlag = false;
        } else {
            eSize = (med + 1) / 2;
            oddFlag = true;
        }
        
        while(i<nums1.size() && j<nums2.size()) {
            if(nums1[i]<nums2[j]) {
                ma.push_back(nums1[i]);
                i++;
            } else {
                ma.push_back(nums2[j]);
                j++;
            }
            if (ma.size()==eSize)
                break;
        }
        
        while(i<nums1.size() && ma.size() < eSize) {
                ma.push_back(nums1[i]);
                i++;
             if (ma.size()==eSize)
                break;
        }
        
        while(j<nums2.size()&& ma.size() < eSize) {
               ma.push_back(nums2[j]);
               j++;
             if (ma.size()==eSize)
                break;
        }

        
        if (oddFlag==false) {
            return double(ma[ma.size()-1] + ma[ma.size()-2])/2;
        } 
        return ma[ma.size()-1];
               
    }
};