/* https://neetcode.io/problems/three-integer-sum/history?submissionIndex=4 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for(int i = 0; i < nums.size(); i++) {
            if(sorted[i] > 0) break; // every number is positive. No solution
            if(i > 0 && sorted[i] == sorted[i-1]) continue; // skip duplicates
            int left = i + 1;
            int right = sorted.size() - 1;

            while(left < right) {
                int threeSum = sorted[i] + sorted[left] + sorted[right];
                if(threeSum > 0) right--;
                else if(threeSum < 0) left++;
                else if(threeSum == 0) {
                    vector<int> zeroSum = {sorted[i], sorted[left], sorted[right]};
                    result.push_back(zeroSum);
                    right--;
                    left++;
                    // skip duplicates again
                    while(left < right && sorted[left] == sorted[left-1]) left++;
                }
            }
        }
        return result;
    }
};
