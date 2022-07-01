// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i+1; j < nums.size(); j++) {
                for (size_t k = j+1; k < nums.size(); k++) {
                    if ((nums[i] + nums[j] + nums[k]) == 0) {
                        vector<int> v{ nums[i],nums[j],nums[k] };
                        int pp = v[0];
                        int qq = v[1];
                        int rr = v[2];
                        if (pp == 0 && qq == 0 && rr == 0) {
                            // do something
                            int x = 10;
                        }
                        // check if this vector is already present in output
                        bool vector_duplicate = false;
                        for (auto a : output) {
                            // check if all elements are matching
                            list<int> a_copy;
                            for (auto z : a)
                                a_copy.push_back(z);

                            bool all_matching = true;
                            for (auto b : v) {
                                bool found = false;
                                for (auto it = a_copy.begin(); it != a_copy.end(); ++it) {
                                    if (b == *it) {
                                        a_copy.erase(it);
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    all_matching = false;
                                    break;
                                }
                            }
                            if (all_matching) {
                                vector_duplicate = true;
                                break;
                            }
                        }

                        if (!vector_duplicate) {
                            output.push_back(v);
                        }
                    }
                }
            }
        }
        return output;
    }
};

int main()
{
	Solution s1;
	
    vector<int> nums{ -13,10,11,-3,8,11,-4,8,12,-13,5,-6,-4,-2,12,11,7,-7,-3,10,12,13,-3,-2,6,-1,14,7,-13,8,14,-10,-4,10,-6,11,-2,-3,4,-13,0,-14,-3,3,-9,-6,-9,13,-6,3,1,-9,-6,13,-4,-15,-11,-12,7,-9,3,-2,-12,6,-15,-10,2,-2,-6,13,1,9,14,5,-11,-10,14,-5,11,-6,6,-3,-8,-15,-13,-4,7,13,-1,-9,11,-13,-4,-15,9,-4,12,-4,1,-9,-5,9,8,-14,-1,4,14 };
    vector<vector<int>> output = s1.threeSum(nums);
    for (auto a : output) {
        for (auto b : a) {
            std::cout << b << "  ";
        }
        std::cout << "\n";
    }
    return 0;
}

