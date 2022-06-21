#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

 bool isValidParantheses(string s) {
    stack<char> temp;
    map<char, char> m = { {']','['},{')','('},{'}','{'} };
     
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            temp.push(s[i]);
        else if (s[i] == ']' || s[i] == ')' || s[i] == '}')
        {
            if (!temp.empty() and temp.top() == m[s[i]]) temp.pop();
            else return false;
        }
    }
    return temp.empty();
 }
