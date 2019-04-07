/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (29.80%)
 * Total Accepted:    61.7K
 * Total Submissions: 207.2K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array, you need to find one continuous subarray that if you
 * only sort this subarray in ascending order, then the whole array will be
 * sorted in ascending order, too.  
 * 
 * You need to find the shortest such subarray and output its length.
 * 
 * Example 1:
 * 
 * Input: [2, 6, 4, 8, 10, 9, 15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * 
 * Note:
 * 
 * Then length of the input array is in range [1, 10,000].
 * The input array may contain duplicates, so ascending order here means . 
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
  public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> clone(nums);
        sort(nums.begin(), nums.end());
        int unSortStart = nums.size();
        int unSortEnd = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != clone[i])
            {
                unSortStart = min(unSortStart, i);
                unSortEnd = max(unSortEnd, i);
            }
        }

        return unSortEnd - unSortStart < 0 ? 0 : unSortEnd - unSortStart + 1;
    }
};