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
* O(n^2)
* O(2^n)
* O(n!)

Big O is the defention of a set:
`O(g(n)) = {f(n): there exist positive constants c and n0 such that 0 <= f(n) <= cg(n) for all n >= n0 }`

*we say that g(n) is an asymptotic upper bound for f(n).*

Best case scenario analysis: Ω(x)
* Linear search as Ω(1) where as Binary search has Ω(log(n))

Average case analysis (Most accurate, but there is no easy way to find it)