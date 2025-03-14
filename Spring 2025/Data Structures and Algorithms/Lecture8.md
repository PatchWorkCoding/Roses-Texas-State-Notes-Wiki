# Sorting

## Simple Sort - All big O(n^2)
### Bubble Sort - (The Worst)

```
for(int i = 0; i < len - 1; i++) {
    if(arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}
```

Best case running time - o(n) <- because the area could already be sorted

average case running time - O(n^2)

Worst Case running time = O(n^2)

### Selection Sort

Find the smallest element and put it where it needs to go

**Pros**:
Only has one swap per cycle

Always o(n^2) time although could be made faster

It has no concept of if the array is already sorted so it will check ever element against every other element

### Insertion Sort
look at slides and put answer here!

**Pros**:
works better for linked list

Best case running time - o(n) <- because the area could already be sorted

average case running time - O(n^2)

Worst Case running time = O(n^2)

In order to get O(n) running time you need to check insertion from right to left

## More Complex Sorts - All Big O(n*log(n))

### Merge Sort
Recursively sort the array by repeatedly breaking it in half and then figuring out how to merge those individual components into a sorted array

Merge Function -

For each element in the combined array-
* have an index i and an index j
* i is one half of the merged array, and j is the other half
* compare the elements at index i and j
* if smaller i than j put i at the kth index of the sorted array, if j is smaller put j their in stead
* increment the i or j by 1 and then increment k by 1
* 20 goto 10

there are ways of merging "in place" but it is a much more complicated algorithm

you should learn "in place" method. They like to ask that on job interviews

Merge is O(nlog(n)) because it needs to perform n merge operations and each merge operation per recursion takes half as long so

**Pros:**
Way faster than the simple sorting algorithms

**Cons:**
* It has larger space complexity than other faster sort algorithms
* Merge sort's best running time is still O(nlog(n)) because it has no concept of whether the the array is already sorted
* Merge Sorts average case is also O(nlog(n)) for the same reason

### Quick Sort
Most of the fastest sorting algorithms are quick sort with extra steps

The algorithm:
* Pre-process the array by putting all the larger elements in one half and the smaller elements in the other half. (this skips the merge function entirely)

* recall recursively to divide and conquer. 

#### Partitioning strategy
**Hoare’s strategy O(n)**
* Choose a pivot at random
* put it at the end of the array
* create two indices i and j. i = 0, j = length - 1
* `while (i > j)`
    * `if (arr[j] <= pivot && arr[i] > pivot)`
        * swap i and j
        * `i++`
    * `j--`
* after i and j cross set swap the pivot with the last element of the array 
* partition of the array by splitting it into two p > i and p < j
* We stop recursive calling when array is only 1 element long. (Notice that if it is only one element long the while loop won't call)

Cons of Hoare's strategy: two many edge cases such as 1 or two element arrays

**Lomuto Strategy O(n)**
* choose a pivot at random
* put it at the end of the array
* create two indices i and j. i = -1, j = 0;
* `while (j < length - 1)`
    * `if (arr[i] < pivot)`
        * `i++`
        * swap the element at i and j if possible (remember i starts at -1)
    * `j++`
* swap `arr[i + 1]` and the pivot which is at the last element of the array 
* split the array at the pivot

#### Choosing the pivot
* Always choose the last element - (worst performance can be O(n^2))
* Choose a random element - (better but not amazing cause you could randomly choose a bad pivot)
* choose the median of 3 random elements - (Best because it decreases the random chance you choose a bad pivot)

#### Big O
average case O(nlog(n))

Worst case O(n^2)

