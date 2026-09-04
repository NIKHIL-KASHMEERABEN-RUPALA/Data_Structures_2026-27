#include <vector>
#include <algorithm>

class Solution {
public:
    int firstStableIndex(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // suffix_min[i] stores the minimum value in nums[i..n-1]
        std::vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = std::min(nums[i], suffix_min[i + 1]);
        }

        // Maintain prefix maximum on the fly and check the condition
        int prefix_max = nums[0];
        for (int i = 0; i < n; ++i) {
            prefix_max = std::max(prefix_max, nums[i]);
            // Instability score is prefix_max - suffix_min[i]
            // Using long long prevents potential overflow if k or values exceed INT_MAX
            if (static_cast<long long>(prefix_max) - suffix_min[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};