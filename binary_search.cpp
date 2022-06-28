#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int binary_search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right){
            int midpoint = left+(right-left)/2;
            if(nums[midpoint] == target) return midpoint;
            else if(nums[midpoint] < target) left = midpoint + 1;
            else right = midpoint - 1;
        }
        return -1;
    }
};
