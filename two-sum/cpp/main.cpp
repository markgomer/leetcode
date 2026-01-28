/*
    https://neetcode.io/problems/two-integer-sum/question
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int>
    twoSum(vector<int>& nums, int target)
    {
        vector<int> v;
        int n = nums.size();

        // create the hash map for O(1) lookup
        unordered_map<int,int>seenNumsAndIndex;
        for (int i = 0; i < n; i++)
        {
            int difference = target - nums[i];
            unordered_map<int, int>::iterator iter = seenNumsAndIndex.find(difference);

            // if the iterator didn't reach the end, 
            // we did find the complement on the map! 
            if (iter != seenNumsAndIndex.end())
            {
                // So that's the answer!
                v = { seenNumsAndIndex[difference], i};
                break;
            }
            seenNumsAndIndex.insert({nums[i], i});
        }

        return v;
    }
};

int
main (int argc, char *argv[])
{
    Solution* s = new Solution();

    vector<int> v = {3,4,5,6};
    vector<int> r = s->twoSum(v, 7);
    return 0;
}
