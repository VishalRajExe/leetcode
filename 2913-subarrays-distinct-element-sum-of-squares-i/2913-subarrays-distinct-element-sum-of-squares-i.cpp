class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            bool seen[101] = {};
            int d = 0;
            for (int j = i; j < n; ++j) {
                if (!seen[nums[j]]) { seen[nums[j]] = true; ++d; }
                ans += d * d;
            }
        }
        return ans;
    }
};