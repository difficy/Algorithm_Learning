//好丑……
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int* p = &nums[0];
        int* q = &nums[n - 1];
        while (p < q) {
            while (p < q) {
                if (*q != val) {
                    break;
                }
                q--;
                n--;
            }

            if (*p == val) {
                n--;
                *p = *q;
                q--;
            }
            p++;
        }
        if (p == q && *p == val) {
            n--;
        }
        return n;
    }
};
