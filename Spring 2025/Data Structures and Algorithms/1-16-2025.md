*And so it begins again*

# Lecture 2: Abstract Data types

You should try and solve the problem in your brain first and then go to typing. Get a good hold of your problem before you start working.

We keep running into concept at our time in college. Conceptualize then execute, not just for programming but for any sufficiently large problem

Solution design - Conceptual problem solving:
* Specification: what is the problem
    * get specific, what does the program actually need to do, what are its end conditions, what are its rules and exceptions, etc
* Design: how to solve the problem
    * What are you going to do solve the problem? How are you going to organize the data, process that data, etc? how will it actually work in the code
    * *a common exam question will be: here is a problem what is the best data structure to solve it*
* Analysis: is it the best possibly solution, what are the trade off that you had to commit to
* Implementation and Testing

Software System Life Cycle
* Requirements
    * Specification of input and output
    * Specification of functions
    * Error handling
* Analysis
    * Break-down the problem in manageable pieces
    * Strategies:
        * bottom up:
            * making small / specific functions first
            * connect those functions to build a large system
        * Top down <- Typical problem solving philosophy
            * High-level plan first, subsequently refine for low-level
            * Preferred for complex system
* Design
    * When we get to this step we are starting thinking about how to actually start writing the program, but we don't code it yet!
    * Dta Objects and operations:
        * Define abstract data types
        * Specify algorithms 
* Refinement and Coding
    * Choose representation and write algorithms
    * use programming paradigms
        * Structured
        * modular
        * Objected-oriented <- the majority of all paradigms
    * Deferring implementation makes system modification easier. *Basically all the problems will have been caught like way earlier and you will have an innate understanding of how it works*
* Verification
    * Correctness proofs: Mathematically prove the program will always work *Almost impossible to do*
    * Testing: break that motherfuckers knee's in a trial by fire
        * Most testing is unit testing where you make automated tests to only verify one class or one unit
        * There is no shame in having like 25% of your code is devoted to testing code
    * Error Removal: kill all those bugs

## What is an ADT (Abstract data type)

A specification of a set of *data* and a *minimal set of operations* that can be performed on the data

*Independent* of concrete implementation

Uses defined *interfaces*

*Hides details* from the user

*Not the same* as data structures
* A data structure is a way of storing and organizing data
* An ADT is a an abstract model of a certain class of data structure that have similar behavior

A class is like an Abstract data type because they are both  bundles of methods and data. *The only difference I think is that ADT breaks inheritance*

ADT is the what where the Data structure is the how

## Preconditions vs Postconditions
Preconditions are statements that indicates must be true before the function is called

postconditions are statements that indicate what will be true when the function finishes its work

Example: sqrt(x);
* preconditions is that X must be >= 0 or else it would be imaginary and cause to crashes
* postcondition: the square root of x has been written to the standard output

It is important to comment down your pre and post conditions because those facts are both easily forgotten and extraordinary important. The function is kind of derived completely from its pre and post conditions

Example: bool is_vowel(char letter);
* precondition letter is character in the alphabet
* postcondition: the value returned by the function is true if letter is a vowel and false otherwise
* What are the following values returned;
    * is_vowel('A'); True
    * is_vowel('Z'); False
    * is_Vowel('?'); Throws an error because it violates the preconditions

you can also write it as Precondition -> Postcondition

your function should have code inside it to handle precondition violation

## Assert C++
Library #include "<"cassert">"

instead of using an if statement you can use assert(precondtions) { /* some code */ };

It is used when you can't use throw exception, and it will crash the whole god damn

Assert can be super inefficient mainly when you are doing error checking hundreds of thousands of times on data that might never need it.

One best practice is to use assert and then fully test your program then remove it when you are ready to push to prod

You should use Assert more often in your code

## OOP
**Object**: An entity that performs *computations* and has a *local state*. It is Data + Procedural elements

**Object Oriented Programming**: Programming where Objects are  the fundamental building blocks. Each object is an instance of a type (class) and Classes are related to each other by inheritance

**Dynamic Dispatch**: Function changes based on which function is called on it

**Polymorphism**: It is possible for one object to be used in many different ways

Remember the implementation of .h and .cpp files

**Generic typings:**
* Typedef int value_type;
* using value_type = int;


## Algorithm
Definition: A  finite set of instructions that accomplish a particular task.

Algorithms are normally defined as a function or procedure

**Function**: Always Returns Something and has an end state
**Procedure**: Might not return something nor an end state

Algorithms need input and output

How to write sudo code for certain algorithms

When writing the sudo code of an algorithm it should be written more like a program where each step is explained plainly

Coding style Guides at Texas State:
* http://cs.txstate.edu/~lk04/3358/StyleGuide.html
    * credit: Lee-Song Koh
* http://cs.txstate.edu/~v_m137/cs3358_fall2015/codin
gstyle.html
    * credit: Vangelis Metsis, Roger Priebe, J. Slomka