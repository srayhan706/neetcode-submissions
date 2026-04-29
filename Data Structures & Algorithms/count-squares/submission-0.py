class CountSquares:

    def __init__(self):
        self.arr=[]
        self.ptscnt=defaultdict(int)
        

    def add(self, point: List[int]) -> None:
        self.arr.append(point)
        self.ptscnt[tuple(point)]+=1
        

    def count(self, point: List[int]) -> int:

        res=0
        px,py=point

        for p in self.arr:
            if abs(py-p[1])==abs(px-p[0]) and px!=p[0] and py !=p[1]:
                res+=self.ptscnt[(p[0],py)]*self.ptscnt[(px,p[1])]

        return res
        
