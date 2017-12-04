def binomialCoef(n, k):
	res = 1
	if(k > n- k):
		k = n - k

	for i in xrange(0,k):
		res *= (n - i)
		res //= (i + 1)

	return res

def catalan(n):
	c = binomialCoef(2*n, n)

	return c/(n+1)

def findWays(n):
	if(n & 1):
		return 0

	return catalan(n)

print findWays(10**4) % 10**3