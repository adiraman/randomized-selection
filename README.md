# Randomized Selection

Input :- An array A[n] and a number i belonging to the set {1,2,3,4,...,n}.

Output :- ith order statistic, i.e. the ith smallest element of A.

Algorithm :- Rselect(A, n, i)

1.  if n = 1, return A
2.  Choose pivot P from A uniformly at random.
3.  Partition A around P
4.  Let j = new index of P (i.e. the jth order stat of A)
5.  if i = j, return P
6.  if j > i, return Rselect(1st Part of A, j - 1, i)
7.  if j < i, return Rselect(2nd Part of A, n - j, i - j)