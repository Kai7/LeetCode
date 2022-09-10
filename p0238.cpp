#include "utils/data_structure.hpp"

class Solution {
public:
    /* 49.25, 57.48 */
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }

#if 0
    /* 17.95, 15.33 */
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> fwd(nums.size(), 1);
        vector<int> bwd(nums.size(), 1);
        vector<int> result(nums.size());
        for (int i = 1; i < nums.size(); ++i) {
            fwd[i] = fwd[i - 1] * nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            bwd[i] = bwd[i + 1] * nums[i];
        }
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = fwd[i] * bwd[i];
        }
        return result;
    }
#endif
};