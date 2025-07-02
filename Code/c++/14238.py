import sys

input = sys.stdin.readline

inputStr = input().strip()
n = len(inputStr)
ca=0
cb=0
cc=0
bb =0 #0, 1
bc=0 #0, 1, 2
for val in inputStr:
    if val == "A":
        ca+=1
        continue
    if val == "B":
        cb+=1
        continue
    cc+=1

dp =[dict() for _ in range(2)]
dp[0] = {(ca,cb,cc,bb,bc):""}

for i in range(n):
    t = i%2
    for tu in dp[t]:
        ca, cb, cc, bb, bc = tu
        string = dp[t][tu]
        nbc = bc-1 if bc >=1 else 0
        if ca >0:
            dp[1-t][(ca-1,cb,cc,0,nbc)]=string+"A"
        if cb >0 and bb ==0:
            dp[1-t][(ca,cb-1,cc,1,nbc)]=string+"B"
        if cc >0 and bc ==0:
            dp[1-t][(ca,cb,cc-1,0,2)]=string+"C"
    dp[t] = dict()

    
if dp[n%2]== dict():
    print(-1)
else:
    print(list(dp[n%2].values())[0])