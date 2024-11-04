'''
Author: 1454164915@qq.com 1454164915@qq.com
Date: 2024-11-04 14:55:07
LastEditors: 1454164915@qq.com 1454164915@qq.com
LastEditTime: 2024-11-04 15:29:10
FilePath: /learn/C++/dijstack/d.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''

# from float import inf
inf = float('inf')


def minTimeTorReach(moveTime): 
    m = len(moveTime)
    n = len(moveTime[0])
    g = [[inf] * m for _ in range(n)]

    for x,y,d in moveTime:
        g[x-1][y-1] = d


    dis = [inf] * n
    ans = dis[k-1]
    done = [False]*n
    while True:
        x = -1
        for i, ok in enumerate(done):
            if not ok and (x <0 or dis[i] < dis[x]):
                x = i
        if x < 0:
            return ans
        if dis[x] == inf:
            return -1
        ans = dis[x]
        done[x] = True
        for y, d in enumerate(g[x]):
            dis[y] = min(dis[y],dis[x] + d)



if __name__ == "__main__":
    a = [[2,1,1],[2,3,1],[3,4,1]]
    b = minTimeTorReach(a)
    print(b)
    print("qqq")
