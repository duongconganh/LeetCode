class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        if n < 2: return 1
        cnt = 0
        g = defaultdict(set)
        for u, v in edges:
            g[u].add(v)
            g[v].add(u)
        
        dq = collections.deque(u for u, vs in g.items() if len(vs) == 1)        
        while dq:
            u = dq.popleft()
            v = next(iter(g[u])) if g[u] else -1
            if v >= 0 : g[v].remove(u)
            if values[u] % k == 0 : cnt += 1
            else: values[v] += values[u]
            if v >= 0 and len(g[v]) == 1 : dq.append(v)

        return cnt