/* Create unordered_set from the vector;
    Get a number from it, but we will only consider it if it's a start of a sequence.
    The number is a sequence starter if it doesn't have a pre-consecutive.
    If it is a sequence starter, we go find the next ones and counting the length.
    If the length is greater than the one before it, we swap the values.
*/
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // return variable max_length;
        int maxLength = 0;
        // create unordered_set
        unordered_set<int> us(nums.begin(), nums.end()); // O(1)

        for (int num : us) // O(n)
        {
            /*
            if there isn't a consecutive number BEFORE this one, then this number can START a sequence.
            Alternatively, if we hit a number that HAS a pre-consecutive, we SKIP it.
            NOTE: unordered_set's "find" function returns its "end" pointer if can't find the target
            */
            if(us.find(num-1) == us.end())
            {
                int currLength = 1;

                /*
                Here we start the sequence. We iterate by finding the consecutive number of num.
                If we find the consecutive, we increase the length, then find the next one.
                */
                while (us.find(num + currLength) != us.end()) // still O(n) worst case
                {
                    currLength++;
                }
                maxLength = max(maxLength, currLength);
            }
        }
        return maxLength;
    }
};

