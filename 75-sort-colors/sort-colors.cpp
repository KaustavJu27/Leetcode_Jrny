class Solution {
public:
    void sortColors(vector<int>& nums) {

        int zero = 0, one = 0, two = 0;

        // Count frequency
        for (int x : nums) {
            if (x == 0)
                zero++;
            else if (x == 1)
                one++;
            else
                two++;
        }

        // Fill 0s
        int i = 0;
        while (zero--) {
            nums[i] = 0;
            i++;
        }

        // Fill 1s
        while (one--) {
            nums[i] = 1;
            i++;
        }

        // Fill 2s
        while (two--) {
            nums[i] = 2;
            i++;
        }
    }
};