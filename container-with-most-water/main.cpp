/* https://neetcode.io/problems/max-water-container/question?list=blind75 */

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;
        while(left < right) {
            int area = (right - left) * min(heights[left], heights[right]);
            maxArea = max(area, maxArea);

            if(heights[left] <= heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

