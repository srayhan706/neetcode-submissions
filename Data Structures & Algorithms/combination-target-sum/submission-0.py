class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        

        res=[]

        def backtrac(idx,arr,tot):
            if tot==target:
                res.append(arr[:])
                return
            if tot>target or len(nums)<=idx:
                return
            
            arr.append(nums[idx])
            backtrac(idx,arr,tot+nums[idx])
            arr.pop()
            backtrac(idx+1,arr,tot)


        

        backtrac(0,[],0)


        return res
        