class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans=0

        s=set(nums)

        for n in nums:
            streak,cur=0,n

            while cur in s:
                streak += 1
                cur+=1
            ans=max(ans,streak)

        return ans