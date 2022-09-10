#include "stdio.h"
#include "utils/data_structure.hpp"

#define METHOD 0

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

class Solution {
public:
#if METHOD == 0
    /* 98.59, 26.54 */
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int ans = nums[0];
        int max = nums[0];
        int min = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmp_max = MAX(MAX(max * nums[i], min * nums[i]), nums[i]);
            min = MIN(MIN(max * nums[i], min * nums[i]), nums[i]);
            max = tmp_max;
            ans = MAX(ans, max);
        }
        return ans;
    }

#elif METHOD == 1
    /* 65.55, 72.12 */
    int maxProduct(vector<int>& nums, int front, int rear) {
        if (front >= rear) return nums[front];
        int total_prod = 1.;
        int neg_prod_0 = 1.;
        int neg_prod_1 = 1.;
        int tmp = 1.;
        for (int i = front; i <= rear; i++) {
            total_prod *= nums[i];
            if (nums[i] > 0) {
                tmp *= nums[i];
                continue;
            }
            if (neg_prod_0 == 1.) {
                neg_prod_0 = tmp * nums[i];
            } else {
                neg_prod_1 = tmp;
            }
            tmp = nums[i];
        }
        if (total_prod > 0) return total_prod;       
        if (neg_prod_0 != 1.) {
            neg_prod_1 = tmp;
        }
        return MAX(total_prod / neg_prod_0, total_prod / neg_prod_1);
    }

    int maxProduct(vector<int>& nums) {
        int ans = 0;
        int front = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ans = MAX(ans, maxProduct(nums, front, i - 1));
                front = i + 1;
            }
        }
        if (front <= nums.size() - 1) {
            ans = MAX(ans, maxProduct(nums, front, nums.size() - 1));
        }
        return ans;
    }
#else
#endif
};