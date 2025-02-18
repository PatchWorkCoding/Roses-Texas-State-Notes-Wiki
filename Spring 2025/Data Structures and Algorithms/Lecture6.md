# Big O Notation:
The most important performance metric of a program is its running time.

There are two ways to compare two different algorithms:
* Experimentally: Implement the whole program and then stress test it against a bunch of different types of tests and data sets.
    * This can be made complicated by you will get different performance results from language to language and compiler to compiler.
    * Another limitations is that you can only test a limited amount of data sets and so projects will always have a little bit of imprecision.
    * Experienced programs will know the ins and outs of a language enough to write algorithms in the most efficient ways possible
* Mathematically: This one is more accurate cause it compares things in the abstract and can be proven for all cases

## Asymptotic Analysis  

Big O describes algorithms in the abstract by eliminating the insignificant variables and only looking at the "shape" of the function by plotting on the graph as (x, O(x)).

Big O Notation is always looking at the worst case.

Time Complexity measures the running time of the algorithm

Space Complexity measure the amount of memory used by the algorithm

Most common shapes:
* O(1) - Constant time
* O(log(n)) - logarithmic Time
* O(n) - Linear time
* O(nlogn)
* O(n^2)
* O(2^n)
* O(n!)

Big O is of a set of function defined by:
`O(g(n)) = {f(n): there exist positive constants c and n0 such that 0 <= f(n) <= cg(n), for all n >= n0 }`

*we say that g(n) is an asymptotic upper bound for f(n). Asymptotic in this case meaning f(n) will approach g(n) but never get there.*

in order to find c and n0 then all you need to do is set all factors to the most significant term and add all the terms together

Best case scenario analysis: Ω(x)
* Linear search as Ω(1) where as Binary search has Ω(log(n))

Like Big O Ω() is defined as: `Ω(g(n)) = {f(n): there exist positive constants c and n0 such that 0 <= cg(n) <= f(n), for all n >= n0 }`

*g(n) in this case is the asymptotic lower bound of f(n).*

in order to find c and n0 for Ω(x) you can just drop all but the most significant term

Average case analysis (Most accurate, but there is no easy way to find it)

Tight bound Θ(x): `Θg(n)) = {f(n): there exist positive constants c1 c2 and n0 such that 0 <= c1g(n) <= f(n) <=  c2g(n), for all n >= n0 }`

*note that in order to find Θ(g(n)) O(g(n)) and Ω(g(n)) need to have the same g(n).*

theorem: T(n) = O(n^2) && T(n) = Ω(n^2) ↔ Θ(n^2)

n0 = max (n0-1, n0-2)


small o notation: `o(g(n)) = {f(n): for any positive constant c > 0, there exists a constant n0 > 0 such a that 0 <= f(n) < cg(n), for all n >= n0 }`

*we say g(n) is an upper bound for f(n) that is not asymptotically tight.*

f(n) = o(n) and f(n) = O(n) and f(n) != Θ(n)

ω(n): `o(g(n)) = {f(n): for any positive constant c > 0, there exists a constant n0 > 0 such a that 0 <= cg(n) < f(n), for all n >= n0 }`

*we say g(n) is an lower bound for f(n) that is not asymptotically tight.*

`=` should be written as `∈ `

