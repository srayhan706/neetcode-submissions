class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        intervals.sort()

        res=[]
        res.append(intervals[0])
        e=intervals[0][1]

        for i in range(1,len(intervals)):
            if e>=intervals[i][0]:
                res[-1][1]=max(e,intervals[i][1])
                e=res[-1][1]
            else:
                res.append(intervals[i])
                e=res[-1][1]

        return res

            
            
        