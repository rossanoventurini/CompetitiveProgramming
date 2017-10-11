<a name="Leaders"></a>
## Leaders in Array

* [Code](/code/Leaders.cpp)

<a name="Number">## Missing Number</a>

* [Code](/code/MissingNumber.cpp)

## Max-Sum Subarray <a name="Kadane"></a>

* [Code](/code/Kadane.cpp)

## Trapping Rain Water <a name="Water"></a>

* [Code](/code/TrappingRainWater.cpp)

## Sliding Window Maximum <a name="Sliding"></a>

* [Description of the solution](/notes/lecture2.pdf)
* [Code](/code/SlidingWindowMaxima.cpp)

## Next Larger Elements <a name="Next"></a>

* [Code](/code/NextLargerElements.cpp)

## Towers <a name="Towers"></a>

* [Codeforces](http://codeforces.com/problemset/problem/37/A?locale=en)
* [Code](/code/Towers.cpp)

Easy: sort and compute the number of distinct lengths.


## Finding Team Member <a name="FindingTeamMember"></a>

* [Codeforces](http://codeforces.com/problemset/problem/37/A?locale=en)
* [Code](/code/FindingTeamMember.cpp)

Create tuple $\langle S_{i,j}, i, j \rangle$, for each pair
$i$ and $j$ where $S_{i,j}$ is the strength of the pair. Sort them by strength
and start selecting the pairs greedly.

## Megacity <a name="Megacity"></a>

* [Codeforces](http://codeforces.com/problemset/problem/37/A?locale=en)
* [Code](/code/Megacity.cpp)

Sort all the locations by their distance with Tomsk and, then, select greedly to sum to at least one million.

## Find Pair <a name="FindPair"></a>

* [CodeForces](http://codeforces.com/problemset/problem/160/C?locale=en)
* [Code](/code/FindPair.cpp)

We can find the $k$-th pair without generating (and sorting) all the pairs. The
idea is to sort the original keys. Then, if all the keys were distinct, the
$k$th pair would be $\langle a_i, a_j \rangle$, where $i=(k-1)/n$ and
$j=(k-1)\%n$. However, the presence of not distinct keys makes it slightly more
difficult. Let $r$ be the number of keys equal to $a_i$ and $l$ be the number
of keys smaller than $a_i$. Then, the pair is $\langle a_i, a_j \rangle$, where
$i=k/n$ and $j=((k-1)-l*n)/r]$.

## Inversion Count <a name="InversionCount"></a>

* [Spoj](http://www.spoj.com/problems/INVCNT/)
* [Code](/code/InversionCount.cpp)

[Possible solutions](http://www.geeksforgeeks.org/counting-inversions/)

## Largest Even Number <a name="LargestEvenNumber"></a>

* [Code](/code/LargestEvenNumber.cpp)

## Firing Employees <a name="FiringEmployees"></a>

* [Code](/code/FiringEmployees.cpp)

## Is BST? <a name="IsBST"></a>

* [Code](/code/IsBST.cpp)

## Preorder Traversal of BST <a name="PreorderTraversal"></a>

* [Code](/code/PreorderTraversal.cpp)

## Two Heaps <a name="TwoHeaps"></a>

* [Codeforces](http://codeforces.com/problemset/problem/353/B?locale=en)
* [Code](/code/TwoHeaps.cpp)

Sort the values and for each value keep at most 2 occurrences. Let $c$ be
the number of the remaining values. The number of possible fourdigit integers is
$k=(c/2)(c-c/2)$. The assignment is done as follows:

* Half of the excluded values are assigned to 1, the other to 2.
* Remaining values are uniformly distributed among 1 or 2 taking care of
assigning values with two occurrences to both sets.


## Maximum Path Sum <a name="MaximumPathSum"></a>

* [Geeks for Geeks](http://practice.geeksforgeeks.org/problems/maximum-path-sum/1)
* [Code](/code/MaximumPathSum.cpp)

## Ilya and Queries <a name="IlyaandQueries"></a>

* [Codeforces](http://codeforces.com/problemset/problem/313/B?locale=en)
* [Code](/code/IlyaQueries.cpp)

Use prefix sums of the array $L[0,n]$ where $L[i] = 1$ iff $s_i = s_{i+1}$.


## Alice, Bob and Chocolate <a name="AliceChocolate"></a>

* [Codeforces](http://codeforces.com/problemset/problem/6/C?locale=en)
* [Code](/code/Chocolate.cpp)


## Number of Ways <a name="NumberWays"></a>

* [Codeforces](http://codeforces.com/problemset/problem/466/C?locale=en)
* [Code](/code/NumberWays.cpp)

Let $S$ be the sum of the values in the array. If $3$ doesn't divide $S$, we
conclude that the number of ways is zero. Otherwise, we compute the number array
$c$ which stores in position $i$ the number suffixes of $a[i\ldots n]$ that sum
to $\frac{S}{3}$. We then compute the sum of the prefixes of $a$.
Every time a prefix $i$ sums to $\frac{S}{3}$, we add $c[i+2]$ to the result.


## Little Girl and Maximum <a name="LittleGirl"></a>

* [Codeforces](http://codeforces.com/problemset/problem/276/C?locale=en)
* [Code](/code/LittleGirl.cpp)

We need to sort the entries of the array by their access frequencies and then
assign the largest values to the most frequently accessed slots. We could use
an array to keep track of the frequencies of the entries. However, let $Q$ be
the sum of the length of queries size, just updating the above array would cost
$\Theta(q+Q)$. Note that $Q$ may be $\Theta(qn)$, which may be even more than
quadratic in $n$.

Thus, we need a cleaver way to compute those frequencies. The idea is to
construct an array $F[1\ldots n]$, initially all the entries are set to $0$. If
we read the query $\langle l_i, r_i \rangle$, we add $1$ to $F[l_i]$ and we
subtract $-1$ to $F[r_i+1]$. The prefix sum of $F$ up to $i$ equals the
frequency of entry $i$. This algorithm costs only $O(q+n)$ time.


## Update the Array <a name="UpdateArray"></a>

* [Spoj](http://www.spoj.com/problems/UPDATEIT/)
* [Code](/code/UpdateArray.cpp)

We use a Fenwick tree F. For the update $l$, $r$, $val$ we add $val$ to $F[l]$
and we substract $val$ to $F[r+1]$. This way, the value at position $i$ is
simply the sum from $F[0]$ to $F[i]$.


## Pashmak and Parmida's problem <a name="PashmakParmida"></a>

* [CodeForces](http://codeforces.com/problemset/problem/459/D?locale=en)
* [Code](/code/PashmakParmida.cpp)


## Nested Segments <a name="NestedSegments"></a>

* [CodeForces](http://codeforces.com/problemset/problem/652/D?locale=en)
* [Code](/code/NestedSegments.cpp)

This problem is a standard two-dimensional problem that can be solved with
one-dimensional data structure. In the same way a lot of other problems can be
solved (for example the problem of finding the maximal weighted chain of points
so that both coordinates of each point are greater than the coordinates of the
predecessing point). Rewrite the problem formally: for each $i$ we should count
the number of indices $j$ so that the following conditions hold: $a_i < a_j$
and $b_j < a_j$. Let's sort all segments by the left ends from right to left
and maintain some data structure (Fenwick tree is the best choice) with the
right ends of the processed segments. To calculate the answer for the current
segment we should simple take the prefix sum for the right end of the current
segment. So the condition $a_i < a_j$ is hold by sorting and iterating over the
segments from the right to the left (the first dimension of the problem). The
condition $b_j < a_j$ is hold by taking the prefix sum in data structure (the
second dimension).
