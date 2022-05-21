#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //(val1, index1)
        //(val2, index2)
        //index1 != index2
        unordered_map<int, int>pairs;
        for(int i = 0; i < nums.size(); ++i){
            pairs[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); ++i){
            int rem = target - nums[i];
            if((pairs.find(rem) != pairs.end()) and (pairs[rem]) != i){
                return {i, pairs[rem]};
            }
        }
        return {-1, -1};
    }
     // two sum with a sorted list and the first index is 1 not 0
      vector<int> twoSum2(vector<int>& numbers, int target) {
        //sorted == binary search
        int left = 0, right = numbers.size()-1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left+1, right+1};
            }
            else if(sum > target){
                --right;
            }
            else{
                ++left;
            }
        }
        return {-1, -1};
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size() < 2){
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            //handle duplicates
            if(i > 0 and nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            int x = nums[i];
            
            while(left < right){
                int sum = x + nums[left] + nums[right];
                
                if(sum < 0){
                    left++;
                }
                else if(sum > 0){
                    right--;
                }
                else{
                    ans.push_back(vector<int>{x, nums[left], nums[right]});
                    //handle duplications
                    while(left < right and nums[left] == nums[left + 1]) 
                        left++;
                    while(left < right and nums[right] == nums[right - 1])
                        right--;
                    left++; right--;
                }
            }
        }
        return ans;
    }
     vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        
        vector<int>v(n);//resutl vector
        int k = n-1;//start traversing for the end of v till 0   
        
        while(low <= high){
            if(abs(nums[low]) > abs(nums[high])){
                v[k--]=nums[low] * nums[low];
                low++;
            }else{
                v[k--]=nums[high] * nums[high];
                high--;
            }
        }
        return v; 
    }
    
};
