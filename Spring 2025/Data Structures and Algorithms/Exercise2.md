Binary search sudo code:

```
//Searches a presorted list of integers using the binary search algorithm for the index of a key value using the upper and lower bounds of an array and returns the index of the key element. If no element was found it returns -1;
int binarySearch(int key, int lowerBound, int upperBound, int array) 
{
    int mid = UpperBound / LowerBound; //Calculates the intital mid values

    //Loops until key is found or until the Upperbound is less than the LowerBound signifying the key wasn't found
    while(array[mid] != key && UpperBound > LowerBound) {
        if(key < mid) 
            UpperBound = mid - 1; // Move the upper bound to the middle of the array
        else //We already know that key != array[mid] because of the while loop
            LowerBound = mid + 1;
    }

    if (UpperBound < LowerBound) 
        return -1; //Returns -1 to show the key wasn't found
    
    return mid; // Returns the found index
}
```

This is wrong because I think it is a little to much like code and LowerBound doesn't need to be passed since it will always be 0
Also you can say "not_found" instead of outputing -1 because this is for a human not a computer

