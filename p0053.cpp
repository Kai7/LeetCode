#include "utils/data_structure.hpp"

#define MAX(a,b) (((a)>(b))?(a):(b))

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum += nums[i];
            sum = MAX(sum, nums[i]);
            ans = MAX(ans, sum);
        }
        return ans;
    }

#if 0
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int tmp = (nums[0] > 0) ? nums[0] : 0;
        for (int i = 1; i < nums.size(); ++i) {
            tmp += nums[i];
            if (tmp < 0) {
                if (ans < 0) {
                    ans = MAX(ans, nums[i]);
                }
                tmp = 0;
                continue;
            } 
            ans = MAX(tmp, ans);
        }
        return ans;
    }
#endif
};