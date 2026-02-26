class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int n1 = nums1.length, n2 = nums2.length;

        // Always binary search on the smaller array for efficiency
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;

        // 'left' = number of elements in the left half of merged array
        int left = (n + 1) >> 1; // equivalent to (n+1)/2

        int low = 0, high = n1; // Binary search bounds on nums1

        while (low <= high) {

            // mid1 = number of elements taken from nums1 for left half
            int mid1 = low + (high - low) / 2;

            // mid2 = remaining elements needed from nums2 for left half
            int mid2 = left - mid1;

            // l1, l2 = largest elements on left side of partition in nums1, nums2
            // r1, r2 = smallest elements on right side of partition in nums1, nums2
            int l1 = Integer.MIN_VALUE, l2 = Integer.MIN_VALUE;
            int r1 = Integer.MAX_VALUE, r2 = Integer.MAX_VALUE;

            // Set values only if partition index is within bounds
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            // Valid partition found:
            // Left side of both partitions ≤ Right side of opposite partitions
            if (l1 <= r2 && l2 <= r1) {
                // Odd total length → median is max of left elements
                if ((n & 1) == 1) return Math.max(l1, l2);
                // Even total length → median is average of middle two elements
                return ((double)(Math.max(l1, l2) + Math.min(r1, r2))) / 2.0;
            }

            // l1 too large → move partition left in nums1
            if (l1 > r2)
                high = mid1 - 1;
            else
                // l2 too large → move partition right in nums1
                low = mid1 + 1;
        }

        return 0;
    }
}
// ```

// ### Dry Run Example
// ```
// nums1 = [1, 3]
// nums2 = [2]

// n1=2, n2=1 → swap → nums1=[1,3], nums2=[2] (n1 <= n2 ✅)
// n=3, left=2, low=0, high=2

// Iteration 1:
//   mid1 = 1, mid2 = 1
//   l1 = nums1[0] = 1
//   r1 = nums1[1] = 3
//   l2 = nums2[0] = 2
//   r2 = INT_MAX (mid2=1 == n2=1, out of bounds)

//   l1(1) <= r2(MAX) ✅  and  l2(2) <= r1(3) ✅ → Valid partition!
//   n is odd → return max(l1, l2) = max(1, 2) = 2.0 ✅
// ```
// ```
// nums1 = [1, 2]
// nums2 = [3, 4]

// n=4, left=2, low=0, high=2

// Iteration 1:
//   mid1=1, mid2=1
//   l1=1, r1=2, l2=3, r2=4
//   l1(1) <= r2(4) ✅  but  l2(3) <= r1(2) ❌
//   → low = mid1+1 = 2

// Iteration 2:
//   mid1=2, mid2=0
//   l1=2, r1=INT_MAX, l2=INT_MIN, r2=3
//   l1(2) <= r2(3) ✅  and  l2(MIN) <= r1(MAX) ✅ → Valid partition!
//   n is even → (max(2, MIN) + min(MAX, 3)) / 2
//             = (2 + 3) / 2 = 2.5 ✅
