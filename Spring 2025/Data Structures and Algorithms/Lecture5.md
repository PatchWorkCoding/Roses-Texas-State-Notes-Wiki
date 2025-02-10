# chapter 5: Templates

## Templates: 

**Generic Programming** creating programs that are agnostic to data types.

We want to do this because it would be nice to do functions like comparisons to many many different data types without having to write them all out be hand

We do this through the generic data type `T` :
```
template <typename T>
T maximum(T a, T b) {
    if (a > b)
        return a;
    else
        return b;
}
```
*Alternatively you can use `class` instead of `typename`*

To call this function:
```
double v = maximum<double>(2.3, 3.1);
```

you can have multiple different generic data types like:
```
template<typename A, typename B>
void someFunction(A a, B b) {
    /* Code*/
}
```

To call: 
```
someFunction<int, double>(2, 4.5);
```

You can also call a template function with type inference
```
maximum(2.4f, 2.6f);
```
However this can lead to type miss-matches that have a bunch of arbitrary rules they used to figure it out

***

## Typedef and Using

`typedef` is the older version of `using` and is a hold over from c++

Typedef and Using are known as *type aliases* and can't be changed onces they have been hard coded. This is because you might have datatypes with really long names that you don't want to write over and over again:

How to use `Typedef`or `Using`
```
class stack
{
    public:
        using name_of_datatype_alias = int;
        static const int CAPACITY = 20;
        void push(name_of_datatype_alias item);
        name_of_datatype_alias pop();
    private:
        name_of_datatype_alias data[CAPACITY];
        int count;
};

```

***
## Auto
`auto` is like `var` in c# where you just have generic data type.

## Template Class:
Isn't a class until you define it

