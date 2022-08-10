#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        // unordered_map<char, int>seen;
        int seen[26] = {0};
        for(int i = 0; i < s.size(); ++i){
            seen[s[i] - 'a']++;
            seen[t[i] - 'a']--;
        }
        // if empty == return true
        for(int i = 0; i < 26; ++i){
            if(seen[i] != 0) return false;
        }
        return true;
    }
  
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(!strs.size()) return {};
        
        vector<vector<string>>res;
        unordered_map<string, vector<string>>matchs;
        
        for(string &s : strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            matchs[sorted].push_back(s);
        }
        
        for(auto &m : matchs){
            res.push_back(m.second);
        }
        return res;
    }
  
    int minAbsDiff1(vector<int>vals){
       int diff = INT_MAX;
       for(int i = 0; i < vals.size()-1; ++i){
         for(int j = i+1; j < vals.size(); j++){
           if(abs(vals[i] - vals[j] ) < diff)
              diff = abs(vals[i] - vals[j]);
        }
      }
       return diff;
    }
  
    int minAbsDiff2(vector<int>vals){
       sort(vals.begin(), vals.end());
       int diff = vals[1] - vals[0];
       for(int i = 2; i != vals.size(); ++i){
           diff = min(diff, abs(vals[i] - vals[i-1]));
       }
       return diff;
    }
  
      vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>seen;
        for(int i : nums){
            seen[i]++;
        }
        vector<int>res;
        priority_queue<pair<int, int>>freqs;
        for(auto item : seen){
            freqs.push({item.second, item.first});
        }
        while(k--){
            res.push_back(freqs.top().second);
            freqs.pop();
        }
        return res;
    }
  
};
