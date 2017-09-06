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


## Two Heaps <a name="TwoHeaps"></a>

* [Codeforces](http://codeforces.com/problemset/problem/353/B}?locale=en)
* [Code](/code/TwoHeaps.cpp)

Sort the values and for each value keep at most 2 occurrences. Let $c$ be
the number of the remaining values. The number of possible fourdigit integers is
$k=(c/2)*(c-c/2)$. The assignment is done as follows:

* Half of the excluded values are assigned to 1, the other to 2.
* Remaining values are uniformly distributed among 1 or 2 taking care of
assigning values with two occurrences to both sets.
