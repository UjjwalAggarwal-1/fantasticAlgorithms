class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        distMap = {}
        for r in roads:
            key = str(r[0])+"_"+str(r[1])
            distMap[key] = r[2]

        adjMap = {}
        for r in roads:
            adjMap[r[0]] = adjMap.get(r[0],[]) + [r[1]]

        shortestDistMap = {}
        for r in roads:
            shortestDistMap[r[0]] = 99999999999
            shortestDistMap[r[1]] = 99999999999
        shortestDistMap[1] = 0

        is_visited = [0]*n

        for node, nextNodes in adjMap.items():
            if is_visited[node-1]:
                continue
            for nextNode in nextNodes:
                key = str(node)+"_"+str(nextNode)
                if not key in distMap:
                    key = str(nextNode)+"_"+str(node)
                shortestDistMap[nextNode] = min(shortestDistMap[nextNode], shortestDistMap[node]+distMap.get(key,9999999999))

            is_visited[node-1] = 1

        print(shortestDistMap)
    
