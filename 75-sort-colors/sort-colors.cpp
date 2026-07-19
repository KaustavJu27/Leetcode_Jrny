class Solution {
public:
    void sortColors(vector<int>& nums) {

        // by using 2 pointer approach :

        int n = nums.size();

        int low = 0, mid = 0, high = (n - 1);

        // traverse the array and swap it with corresponding value :
        // so here if nums[mid]==0 then swap(nums[mid++],nums[low++]);
        // so here if nums[mid]==1 then mid++;
        // so here if nums[mid]==2 then swap(nums[mid++],nums[high--]);

        while (mid <= high) {

            if (nums[mid] == 0) {
                swap(nums[mid++], nums[low++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
    }
};