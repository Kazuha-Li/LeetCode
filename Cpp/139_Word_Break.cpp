/*
https://leetcode.com/problems/word-break/

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.


Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

ref:
https://github.com/grandyang/leetcode/issues/139

*/
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

class Solution {
   public:
    unordered_set<string> dict;
    vector<int> memo;
    bool wordBreak_recursive(string s, vector<string>& wordDict) {
        for (auto w : wordDict) dict.insert(w);
        memo.resize(s.size(), -1);
        return helper(s, wordDict, 0);
    }
    bool helper(string s, vector<string>& wordDict, int start) {
        if (start == s.size()) return true;
        if (memo[start] != -1) {
            cout << "start = " << start << endl;
            return memo[start];
        }
        for (int i = 1; i <= s.size() - start; i++) {
            // cout<<s.substr(start, i)<<endl;
            if (dict.count(s.substr(start, i)) && helper(s, wordDict, start + i)) return memo[start] = 1;
        }
        cout << "start = " << start << ", memo[start] = " << memo[start] << endl;
        return memo[start] = 0;
    }
};
class Solution2 {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            // for(int j = 0; j < i; j++){
            for (int j = i - 1; j >= 0; j--) {
                // because dp.size() = s.size() + 1, so substr(j,i-1) 不用 j+1
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};

class Solution3 {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0) return false;

        unordered_set<string> d(wordDict.begin(), wordDict.end());

        // dp[i] is true only if a valid word or sequence of words ends at i
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                // check only if a valid sequence of words (or a word) ends at j
                if (dp[j]) {
                    const string sub = s.substr(j, i - j);
                    if (d.count(sub)) {
                        // Ending at i is a valid word
                        dp[i] = true;
                        // Others j values might be false
                        // We stop here since there is one valid sequence ending here
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
/*class Solution
{
  public:
     bool wordBreak(string s, vector<string>& wordDict)
     {
         if(wordDict.size() == 0)
         {
             return false;
         }
         
         unordered_set<string> d(wordDict.begin(), wordDict.end());
         vector<bool> dp(s.length()+1 , false);
         dp[0]=true;
         
         for(int i=0;i<=s.length();i++)
         {
             for(int j=0;j<i;j++)
             {
                // check only if a valid sequence of words (or a word) ends at j
                if(dp[j]) 
                {
                    string sub = s.substr(j, i);
                    if(d.count(sub))
                    {
                        // Ending at i is a valid word
                        dp[i]=true;
                       // Others j values might be false
					   // We stop here since there is one valid sequence ending here
                       break; 
                    }
                }
             }
         }
         return dp[s.length()];
     }
};
*/

/*
//memoization
class Solution 
{
    public:
    bool helper(const string& s, int start, const unordered_set<string>& d, vector<int>& memo) 
    {
        if (start == s.size()) 
        {
            return true;
        }
        
        if (memo[start] != -1) return memo[start];
        
        for (int i = start + 1; i <= s.size(); ++i) 
        {
            const string sub = s.substr(start, i - start); 
            if (d.count(sub) == 1) {
                if (helper(s, i, d, memo)) {
                    memo[start] = 1;
                    return true;
                }
            } 
        }
        
        memo[start] = 0;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> d(wordDict.begin(), wordDict.end());
		// Use a vector since we can index from 0 to N. 
		// Possible values in vector are: -1, 0, 1.
        vector<int> memo(s.length(), -1); 
        return helper(s, 0, d, memo);
    }
};
*/
//recursive
/*
class Solution 
{
public:
     bool wordBreak(string s, vector<string>& wordDict)
     {
         int n=s.length();
         if(s.length() == 0)
         {
             return true;
         }
         
         for(auto num: wordDict)
         {
             string sub=s.substr(0,num.length());
             bool result=false;
             if(sub == num)
             {
                 result=wordBreak(s.substr(num.length()),wordDict);
             }
             if(result)
             {
                 return true;
             }
         }
         return false;
     }
};
*/