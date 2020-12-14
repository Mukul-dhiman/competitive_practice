def reverseArray(l):
    ln = len(l)
    half = ln/2

    for i in range(half):
        temp = l[i]
        l[i]=l[ln-i-1]
        l[ln-i-1] = temp
    return l



n = int(input())
l=[]
for i in range(n):
    t=int(input())
    l.append(t)

print(l)

reverseArray(l)

print(l)