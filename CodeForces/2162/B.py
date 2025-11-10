t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    L, R = [], []
    i, j = 0, n - 1
    while i < j:
        if s[i] == s[j]:
            i += 1
            j -= 1
        elif s[i] == '0' and s[j] == '1':
            R.append(j + 1)
            j -= 1
        else:
            L.append(i + 1)
            i += 1
    R.reverse()
    res = []
    p = q = 0
    while p < len(L) and q < len(R):
        if L[p] < R[q]:
            res.append(L[p]); p += 1
        else:
            res.append(R[q]); q += 1
    if p < len(L): res.extend(L[p:])
    if q < len(R): res.extend(R[q:])
    if not res:
        print(0)
        print()
    else:
        print(len(res))
        print(' '.join(map(str, res)))
