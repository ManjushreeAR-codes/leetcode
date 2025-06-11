class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        unsigned int n = nums1.size(), m = nums2.size();

        if (n == 0 && m == 0)
            return double(0);

        if (n == 0) {
            if (m % 2 == 0) {
                return (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
            } else {
                return nums2[m / 2];
            }
        }

        if (m == 0) {
            if (n % 2 == 0) {
                return (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
            } else {
                return nums1[n / 2];
            }
        }

        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0, high = n;

        while (low <= high) {
            int partN1 = (low + high) / 2;
            int partN2 = (n + m + 1) / 2 - partN1;

            int mxLN1 = (partN1 == 0) ? INT_MIN : nums1[partN1 - 1];
            int minRN1 = (partN1 == n) ? INT_MAX : nums1[partN1];

            int mxLN2 = (partN2 == 0) ? INT_MIN : nums2[partN2 - 1];
            int minRN2 = (partN2 == m) ? INT_MAX : nums2[partN2];

            if (mxLN1 <= minRN2 && mxLN2 <= minRN1) {
                if ((n + m) % 2 == 0) {
                    return (max(mxLN1, mxLN2) + min(minRN1, minRN2)) / 2.0;
                } else {
                    return max(mxLN1, mxLN2);
                }
            } else if (mxLN1 > minRN2) {
                high = partN1 - 1;
            } else {
                low = partN1 + 1;
            }
        }

        return 0.0;
    }
};