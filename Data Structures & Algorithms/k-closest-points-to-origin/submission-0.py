import math
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:

        def dist(p1):
            return math.sqrt(p1[0]**2+p1[1]**2)

        maxheap=[]

        for p in points:
            d=dist(p)
            heapq.heappush(maxheap,(d,p))

        ans=[]

        for i in range(k):
            ans.append(heapq.heappop(maxheap)[1])
        return ans
        