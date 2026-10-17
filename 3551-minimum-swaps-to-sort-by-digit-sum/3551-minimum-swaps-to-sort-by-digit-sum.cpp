#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi2")

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        static uint64_t a[100000];

        for (int i = 0; i < n; i++) {
            uint32_t x = nums[i], s = 0;
            do { s += x % 10; } while (x /= 10);
            a[i] = (uint64_t(s) << 47) | (uint64_t(uint32_t(nums[i])) << 17) | i;
        }

        sort(a, a + n);

        int swaps = 0;
        for (int i = 0; i < n; i++)
            for (int j; (j = a[i] & 0x1FFFF) != i; ++swaps)
                swap(a[i], a[j]);

        return swaps;
    }
};