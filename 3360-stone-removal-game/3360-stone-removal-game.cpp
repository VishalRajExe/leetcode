class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = false;
        for (int x = 10; x > 0 && n >= x; --x) {
            n -= x;
            alice = !alice;
        }
        return alice;
    }
};