class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
       
        if (sum < 1 || 1LL * sum > 9LL * num) {
            return "";
        }

        string answer;
        answer.reserve(num);

       
        for (int i = 0; i < num; ++i) {
            int digit = min(9, sum);
            answer.push_back(char('0' + digit));
            sum -= digit;
        }

        return answer;
    }
};