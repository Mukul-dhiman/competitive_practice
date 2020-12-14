
def getUpToN(n):
    return n*(n+1)/2


def getSequenceSum(i,j,k):

    j_i = getUpToN(j) - getUpToN(i-1) 

    j_k = getUpToN(j-1) - getUpToN(k-1)

    return (j_i + j_k)



i = int(input())
j = int(input())
k = int(input())

print(getSequenceSum(i,j,k))