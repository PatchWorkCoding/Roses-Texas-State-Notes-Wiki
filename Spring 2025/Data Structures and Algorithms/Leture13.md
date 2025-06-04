# Dynamic Programming 

## Algorithmic paradigms

* **Greedy** build up a solution incrementally, myopically, optimizing some local criterion

* **Divide and Conquer** Break up a problem into sub-problems, solve each subproblem independently and combine solutions to sub problems to form solution to original problem

* **Dynamic Programming** break up a problem into a series of overlapping sub-problems and build up solution to larger and larger sub-problems. ***REMEMBER THIS FOR FINAL EXAM***

An example of a dynamic programming problem is solving efficiently solving a Fibonacci series:
~~~
int FibonacciBuffer[sizeOfDesiredNumber];  
FibonacciBuffer[0] = 0;
FibonacciBuffer[1] = 1;

FindFibonacci(int i) {
    if(FibonacciBuffer[i - 1] doesn't exist) {
        FibonacciBuffer[i - 1] = Fibonacci(i -1);
    }
    else if(FibonacciBuffer[i - 2] doesn't exist) {
        FibonacciBuffer[i - 2] = Fibonacci(i - 2);
    }

    return FibonacciBuffer[i - 1] + FibonacciBuffer[i - 2];
}
~~~