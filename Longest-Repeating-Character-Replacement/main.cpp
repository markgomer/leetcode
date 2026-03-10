/* https://neetcode.io/problems/longest-repeating-substring-with-replacement/question */

#include <string>
#include <unordered_map>

using namespace std;

int characterReplacement(string s, int k) {
    unordered_map<char, int> count;
    int longestSubstringSize = 0;

    int left = 0, right = 0, maxFreq = 0;
    while (right < s.size()) {
        count[s[right]]++;
        maxFreq = max(maxFreq, count[s[right]]);

        /*  right - left + 1 - maxFreq is the window length minus the maxfreq,
            which is the lesser number of characters we need to replace in
            order to make everyone equal. If this number is greater than k,
            this substring is not relevant, so we slide the window right.
        */
        while (right - left + 1 - maxFreq > k) {
            count[s[left]]--;
            left++;
        }
        longestSubstringSize = max(longestSubstringSize, right - left + 1);
        right++;
    }
    return longestSubstringSize;
}
