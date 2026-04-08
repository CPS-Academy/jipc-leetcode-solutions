class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n > m)return findMedianSortedArrays(nums2, nums1);

        int total = n + m;
        int left_split = (total + 1)/2;

        int low = 0, high = n;
        double ans = 0.0;
        while(low <= high) {
            int mid1 = low + (high - low)/2;
            int mid2 = left_split - mid1;

            int l1 = mid1 - 1 >= 0 ? nums1[mid1 - 1] : INT_MIN;
            int l2 = mid2 - 1 >= 0 ? nums2[mid2 - 1] : INT_MIN;

            int r1 = mid1 < n ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < m ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1) {
                if(total%2 == 0)ans = (max(l1, l2) + min(r1, r2))/2.0;
                else ans = max(l1, l2);
                break;
            }

            if(l2 > r1)low = mid1 + 1;
            else high = mid1 - 1;
        }

        return ans;
    }
};
