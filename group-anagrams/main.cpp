/* https://neetcode.io/problems/anagram-groups/question */

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /* anagrams can be grouped by their char count.
         * i.e. 'cat' and 'act' has 1 a, 1 c and 1 t.
         * so they may be represented by a vector of 26 positions, each
         * representing a character. 
         * i.e. cat would be "1,0,1,....,1,0,0,0,0,0,0", which is the same as
         * act.
         * This string can be a key to a hashmap, in which we would have an
         * array of the strings that are grouped as the value of each key in the
         * hashmap.
        */
        unordered_map<string, vector<string>> res;

        // transform the string in the 26 array
        for(string s : strs)
        {
            vector<int> countChar(26, 0);
            for(char c : s)
            {
                countChar[c - 'a']++;
            }
            // but now we have to convert the vector<int> to a string!
            string key = "";
            for(int count : countChar)
            {
                key += "," + to_string(count);
            }
            res[key].push_back(s);
        }
        // now we need to make the vector of strings 
        vector<vector<string>> answer;
        for(auto& array : res)
        {
            answer.push_back(array.second);
        }
        return answer;
    }
};

