#p182 = 2^91 * 3^57 - 1

n4 = 45          # 91 / 2 (since its for 4-isogenoes not 2-isogenies)
p4 = 8158*2      # cost of 2 xDBL operations
q4 = 2754+6635   # cost of computation + evaluation of 4-isogenies

n3 = 56
p3 = 15563       # cost of xTPL
q3=7380+8297     # cost of computation + evaluation of 3-isogenies

def strategy(n, p, q):
    S = { 1: [] }
    C = { 1: 0 }
    for i in range(2, n+2):
        b, cost = min(((b, C[i-b] + C[b] + b*p + (i-b)*q) for b in range(1,i)),
                      key=lambda t: t[1])
        S[i] = [b] + S[i-b] + S[b]
        C[i] = cost
    return S[n+1]



def compute_strat(n,p,q):

    S = [None]*(n+2)
    C = [0]*(n+2)

    for i in range(n+2):
        S[i] = []

    S[1] = []
    C[1] = 0

    def argmin(idx): #python confuses me
        # print(C)
        minb = 1
        minval = C[idx-1] + C[1] + p + (idx-1)*q
        for _b in range(idx)[2:]:
            val = C[idx-_b] + C[_b] + _b*p + (idx-_b)*q
            if  val < minval:
                minval = val
                minb = _b
        return minb

    for i in range(n+2)[2:]:
        # print(i)
        b = argmin(i)
        # print(b)
        # print("new size is 1 +", len(S[i-b]), "+", len(S[b]), "=", 1+len(S[i-b])+len(S[b]))
        S[i] = [b] + S[i-b]  + S[b]
        # print (S[i])
        C[i] = C[i-b] + C[b] + b*p + (i-b)*q
        # print(i, C[i])
    # print(len(S[n+1]))
    return S[n+1]


S4 = [48, 28, 16, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 13,
7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 5, 4, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 21, 12, 7, 4, 2, 1, 1, 2, 1,
1, 3, 2, 1, 1, 1, 1, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 9, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1, 2,
1, 1]

# print(len(S4))
S=compute_strat(107,5633,5461)
print(compute_strat(n3,5633,5461))
# print(len(S)==len(S4))