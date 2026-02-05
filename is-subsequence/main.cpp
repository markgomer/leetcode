/* https://neetcode.io/problems/is-subsequence/question?list=allNC */

#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0; 
        while (i < s.length()) {
            char sc = s[i];

            bool found = false;
            while (j < t.length()) {
                char tc = t[j++];
                if(sc != tc) {
                    continue;
                }
                else {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
            i++;
        }
        return true;
    }

    // --- RECURSIVE SOLUTION ---
    bool isSubsequencyRec(string s, string t, int sptr, int tptr)
    {
        if (sptr >= s.length()) return true;
        if (tptr >= t.length()) return false;
        if (s[sptr] == t[tptr]) return isSubsequencyRec(s, t, ++sptr, ++tptr);
        else return isSubsequencyRec(s, t, sptr, ++tptr);
    }
    bool isSubsequence2(string s, string t) {
        return isSubsequencyRec(s, t, 0, 0);
    }
};


