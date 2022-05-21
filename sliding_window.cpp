#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

class Solution {
public:
     int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.size() < k) return s.size();
        unordered_map<char, int>seen;
        int maxLen = k;
        for(int left = 0, right = 0; right < s.size(); ++right){
            seen[s[right]]++;
            while(seen.size() > k){
                if(!--seen[s[left]]){
                    seen.erase(s[left]);
                }
                ++left;
            }
            maxLen = max(maxLen, (right-left+1));
        }
        return maxLen;
    }
  
     int fruitIntoBasket(vector<int>& fruit) {
        if(fruit.size() < 2) return fruit.size();
        unordered_map<int, int>frumap;
        
        int maxFru = INT_MIN;
        for(int left = 0, right = 0; right < fruit.size(); )
        {
            frumap[fruit[right++]]++;
            if(frumap.size() > 2){
                frumap[fruit[left]]--;
                if(frumap[fruit[left]] == 0){
                    frumap.erase(fruit[left]);
                }
                ++left;
            }
            maxFru = max(maxFru, (right-left));
        }
        return maxFru;
    }
  
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        unordered_set<char>seen;
        int mx = INT_MIN;
        for(int left = 0, right = 0; right < s.size(); ){
            if(seen.find(s[right]) == seen.end()){
                seen.insert(s[right]);
                mx = max(mx, (right-left+1));
                ++right;
            }else{
                seen.erase(s[left++]);
            }
        }
        return mx;
    }
  
    int maxSubArray(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        int mx = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            int sum = 0;
            for(int j = i; j < nums.size(); ++j){
                sum += nums[j];
                mx = max(mx, sum);
            }
        }
        return mx;
    }
};
