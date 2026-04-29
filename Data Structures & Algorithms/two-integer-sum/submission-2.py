class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        rem_map={}

        for i in range(len(nums)):
            comp=target-nums[i]

            if comp in rem_map:
                return [rem_map[comp],i]
            rem_map[nums[i]]=i
        return []