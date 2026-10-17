class Solution {
public:
    int minSwaps(vector<int>& nums) {
        constexpr int INDEX_BITS = 17; // 2^17 > 100000
        constexpr uint64_t INDEX_MASK = (1ULL << INDEX_BITS) - 1;
        constexpr uint64_t VISITED = 1ULL << 63;

        int n = nums.size();
        vector<uint64_t> order;
        order.reserve(n);

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            int sum = 0;

            while (x) {
                sum += x % 10;
                x /= 10;
            }

            uint64_t sortKey =
                (static_cast<uint64_t>(sum) << 30) | nums[i];

            order.push_back((sortKey << INDEX_BITS) | i);
        }

        sort(order.begin(), order.end());

        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (order[i] & VISITED)
                continue;

            int current = i;
            int cycleLength = 0;

            while (!(order[current] & VISITED)) {
                int next = order[current] & INDEX_MASK;
                order[current] |= VISITED;
                current = next;
                ++cycleLength;
            }

            swaps += cycleLength - 1;
        }

        return swaps;
    }
};