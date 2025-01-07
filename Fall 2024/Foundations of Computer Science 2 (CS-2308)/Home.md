## Index
* [8-27-24](8-27-24.md)

Recursion parts: Base condition, The function calls itself, Recursive condition always moves toward the base condition

Remember how to implement Binary Search, Selection Sort, and Bubble sort

Big O notation is always Base 2

(N-1) + (N-2) + (n-3)...+3 + 2 + 1 = (n^2 - N) / 2

Big O only considers the largest factor, so in the example above (N^2) / 2 - (N / 2) the big O of is O(N^2) because dividing by 2 doesn't mater and adding N doesn't matter if when N is a really large number

linear search is O(N)

Binary search is O(Log^2(N))

Bubble Sort is O(N^2)

Selection Sort is O(N^2)

All Space Complexity for these algorithms is (1)

Time complexity is how much time it takes

Space complexity how much memory the algorithm takes

The space complexity is calculated by the number variables needed to execute the algorithm and doesn't include the input

If space complexity only uses one set of variables it is constant

ClassName& operator=(const ClassName& inVal); <- copy constructor

ClassName newObj(&oldObj); <- wrong way to call!!

Not including a library is on the table as far as non 
