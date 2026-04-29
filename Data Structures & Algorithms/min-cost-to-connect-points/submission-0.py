class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n=len(points)
        adj={i:[] for i in range(n)}

        for i in range(n):
            x1,y1=points[i]

            for j in range(i+1,n):
                x2,y2=points[j]
                d=abs(x2-x1)+abs(y2-y1)
                adj[i].append([d,j])
                adj[j].append([d,i])

        res=0
        vis=set()
        minheap=[[0,0]]

        while len(vis)<n:
            cost,i=heapq.heappop(minheap)
            if i in vis:
                continue
            res+=cost
            vis.add(i)
            for neicost,neighb in adj[i]:
                if neighb not in vis:
                    heapq.heappush(minheap,[neicost,neighb])

        return res
        