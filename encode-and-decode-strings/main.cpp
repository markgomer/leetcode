/* https://neetcode.io/problems/string-encode-and-decode/question */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    encode to length + '#'. Ex.: code = 4#code
    */
    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string& str : strs)
        {
            encoded += to_string(str.length()) + '#' + str;
        }
        return encoded;
    }

    /* 
    s ~= "4#neet4#code5#co#ol"
    */
    vector<string> decode(string s) {
        vector<string> decoded;
        int sIndex = 0;
        while(sIndex < s.length()) // 'til out of bounds
        {
            int sIndex2 = sIndex; // start from the first pointer
            while(s[sIndex2] != '#') // read until the #
            {
                sIndex2++; // we count the number of chars representing the length
            }
            // read the string length. Convert to string
            int length = stoi(s.substr(sIndex, sIndex2 - sIndex));
            sIndex = sIndex2 + 1; // pointer to 1 after #
            // now we put the string on the vector
            decoded.push_back(s.substr(sIndex, length));
            sIndex2 = sIndex + length; // pointer 2 to the next length indicator
            sIndex = sIndex2; // pointer 1 to the next length indicator
        }
        return decoded;
    }
};
