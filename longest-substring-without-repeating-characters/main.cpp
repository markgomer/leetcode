/* https://neetcode.io/problems/longest-substring-without-duplicates/question?list=blind75 */

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> substring;
        int left = 0, right = 0, longestLength = 0;
        while(right < s.size()) {
            while(substring.find(s[right]) != substring.end()) { // char is present in the substring?
                substring.erase(s[left]);
                left++;
            } 
            substring.insert(s[right]);
            longestLength = max(longestLength, right - left + 1);
            right++;
        }
        return longestLength;
    }
};

