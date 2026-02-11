// https://neetcode.io/problems/top-k-elements-in-list/question?list=neetcode150

#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;

        for (int numsIDX = 0; numsIDX < nums.size(); numsIDX++)
        {
            um[nums[numsIDX]]++;
        }

        vector<pair<int,int>> v;
        for(auto& p : um)
        {
            v.push_back({p.second, p.first});
        }
        sort(v.rbegin(), v.rend());

        vector<int> result;
        for(int i = 0; i < k; i++)
        {
            result.push_back(v[i].second);
        }

        return result;
    }
};
