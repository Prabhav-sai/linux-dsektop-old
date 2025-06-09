t = int(input())
for i in range(t):
    n,m,s,x = input().split()
    n = int(n)
    m = int(m)
    s = int(s)
    x = int(x)
    a = [0]*(n+1)
    for j in range(m):
        a1,a2 = input().split()
        a1 = int(a1)
        a2 = int(a2)
        a[a1]=a2
    b = [0]*(n+1)
    freq = [0]*(n+1)
    check = s
    y=1
    while(b[check]==0)and y<x+1:
        b[check]=y
        freq[check]=1
        y+=1
        check=a[check]
    r = y - b[check]
    p=(x-y+1)%(r)
    q = int((x-y+1)/r)
    for j in range(1,r+1):
        if j<p+1:
            freq[check]+= q +1
        else:
            freq[check]+=q
        check=a[check]
    # print(y)
    # print(b)
    # print(freq[1:n+1])
    # print("")
    for x in freq[1:n+1]:
        print(x,end=" ")
    print("")