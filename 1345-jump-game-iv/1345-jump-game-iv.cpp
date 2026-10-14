class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) {
            return 0;
        }

        unordered_map<int, vector<int>> positions;
        positions.reserve(n * 2);

        for (int i = 0; i < n; ++i) {
            positions[arr[i]].push_back(i);
        }

        vector<int> distance(n, -1);
        queue<int> q;

        q.push(0);
        distance[0] = 0;

        while (!q.empty()) {
            int index = q.front();
            q.pop();

            if (index == n - 1) {
                return distance[index];
            }

            int nextDistance = distance[index] + 1;

            if (index > 0 && distance[index - 1] == -1) {
                distance[index - 1] = nextDistance;
                q.push(index - 1);
            }

            if (index + 1 < n && distance[index + 1] == -1) {
                distance[index + 1] = nextDistance;
                q.push(index + 1);
            }

            auto it = positions.find(arr[index]);

            if (it != positions.end()) {
                for (int next : it->second) {
                    if (distance[next] == -1) {
                        distance[next] = nextDistance;
                        q.push(next);
                    }
                }

                positions.erase(it);
            }
        }

        return -1;
    }
};