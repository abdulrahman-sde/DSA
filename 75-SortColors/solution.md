# Dutch National Flag Algorithm – `sortColors` Explanation

This solution uses the **Dutch National Flag algorithm** to sort an array containing `0`, `1`, and `2` in-place with a single pass and constant space.

---

## Code

```c++
// Dutch National Flag Algorithm Implementation
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = 0;                  // Start boundary (all elements before s are 0s)
        int m = 0;                  // Current index (element under examination)
        int e = nums.size() - 1;    // End boundary (all elements after e are 2s)

        while (m <= e) {
            if (nums[m] == 0) {
                swap(nums[m], nums[s]);
                s++;
                m++; // Safe to move forward (no re-check needed)
            }
            else if (nums[m] == 2) {
                swap(nums[m], nums[e]);
                e--;
                // Don't increment m (must re-check swapped element)
            }
            else { // nums[m] == 1
                m++;
            }
        }
    }
};
```

---

## Pointer Logic

### Pointers
- `s` → **Left boundary** (all elements before `s` are sorted as `0`s).
- `m` → **Current index** (element currently being processed).
- `e` → **Right boundary** (all elements after `e` are sorted as `2`s).

---

## Why Different Increments?

### Case 1: `nums[m] == 0`
```c++
swap(nums[m], nums[s]);
s++;
m++;
```
**Why do we increment both `s` and `m`?**  
- When we find a `0`, we swap it to the front (`s` position).  
- After the swap:
  - The element now at index `s` is **guaranteed to be `0`** because we just placed it there.
  - The element swapped into `m` must be either `1` (middle value) or already processed because:
    - Anything before `m` has already been examined by the loop.
    - We never skip an unchecked element at `m`, so if it wasn’t a `0`, it must be a `1` (strictly speaking, it will always be `1`).
- Therefore, **no need to re-check the new `nums[m]`** — we can safely move both pointers forward.

---

### Case 2: `nums[m] == 2`
```c++
swap(nums[m], nums[e]);
e--;
```
- We **do NOT increment `m`** because:
  - The element swapped from `e` could be `0`, `1`, or `2`.
  - We haven’t processed it yet.
  - Skipping `m` here could leave `0`s or another `2` unprocessed.
- On the next iteration, `nums[m]` is re-evaluated.

---

### Case 3: `nums[m] == 1`
```c++
m++;
```
- `1`s remain in the middle by default, so we just move forward.

---

## Why This Algorithm Works (Invariants)

At every step:
1. All elements before `s` are `0`.
2. All elements between `s` and `m-1` are `1`.
3. All elements after `e` are `2`.
4. The loop continues until all elements are processed (`m > e`).

Thus, the array is sorted in one pass.

---

## Visual Diagram (Pointer Movement)

```
Initial: [2, 0, 2, 1, 1, 0]
Pointers:  s=0, m=0, e=5

Step 1: nums[m]=2 → swap(nums[m], nums[e])
Array:   [0, 0, 2, 1, 1, 2]
Pointers: s=0, m=0, e=4 (m stays)

Step 2: nums[m]=0 → swap(nums[m], nums[s])
Array:   [0, 0, 2, 1, 1, 2]
Pointers: s=1, m=1, e=4

Step 3: nums[m]=0 → swap(nums[m], nums[s])
Array:   [0, 0, 2, 1, 1, 2]
Pointers: s=2, m=2, e=4

Step 4: nums[m]=2 → swap(nums[m], nums[e])
Array:   [0, 0, 1, 1, 2, 2]
Pointers: s=2, m=2, e=3 (m stays)

Step 5: nums[m]=1 → m++
Pointers: s=2, m=3, e=3

Step 6: nums[m]=1 → m++
Pointers: s=2, m=4, e=3 (loop ends)
```

Result: `[0, 0, 1, 1, 2, 2]`

---

## Complexity
- **Time:** O(n) – Each element is processed once.
- **Space:** O(1) – In-place sorting.

---
