#include <iostream>

using namespace std;

void MergeSort(int* arr, int length) {
    //std::cout << length << std::endl;
    if (length <= 1)
    {
        return;
    }

    
    //Divide the passed array in half
    int firstArrLength = length / 2;
    
    //Check to see if the passed array is odd, 
    // if so give the remainder to the second array
    int secondArrLength = length % 2 == 0 ? length / 2 : (length / 2) + 1;

    int* firstHalfArr = new int[firstArrLength];
    int* secondHalfArr = new int[secondArrLength];
    
    for (int i = 0; i < firstArrLength; i++)
    {
        //std::cout << arr[i] << " " << arr[firstArrLength + i] << std::endl;
        firstHalfArr[i] = arr[i];
        secondHalfArr[i] = arr[firstArrLength + i];
    }
    
    if (length % 2 == 1)
    {
        secondHalfArr[secondArrLength - 1] = arr[length - 1];
    }
    
    MergeSort(firstHalfArr, firstArrLength);
    MergeSort(secondHalfArr, secondArrLength);

    int i = 0;
    int j = 0;
    int k = 0;
    while (i < firstArrLength && j < secondArrLength)
    {
        if (firstHalfArr[i] <= secondHalfArr[j])
        {
            arr[k] = firstHalfArr[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = secondHalfArr[j];
            j++;
            k++;
        }
    }
    while (i < firstArrLength)
    {
        arr[k] = firstHalfArr[i];
        i++;
        k++;
    }
    while (j < secondArrLength)
    {
        arr[k] = secondHalfArr[j];
        j++;
        k++;
    }
    
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }
    

    std::cout << std::endl;

    //delete[] firstHalfArr;
    //delete[] secondHalfArr;
}

void QuickSort(int* arr, int start, int end) {
    
    if (end - start <= 0)
    {
        return;
    }
    std::cout << end - start << std::endl; 
    int temp = arr[start];
    arr[start] = arr[end - 1];
    arr[end - 1] = temp;
    /* Horae's Method
    while (i > j)
    {
        if (arr[i] > arr[end - 1])
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            
            cout << "swapped " << i << "->" << arr[i] << " with " 
                << j << "->" << arr[j] << endl;
           
            
        }

        if (arr[j] < arr[end - 1])
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            
            cout << "swapped " << i << "->" << arr[i] << " with " 
                << j << "->" << arr[j] << endl;
        }
        j--;
        i++;
    }

    temp = arr[end - 1];
    arr[end - 1] = arr[i];
    arr[i] = temp;
    */
    int i = start - 1, j = start;
    while (j < end - 1)
    {
        if (arr[j] < arr[end - 1])
        {
            i++;
           
            /*
            cout << arr[j] << " < " << arr[end - 1] << endl;
            cout << "swapped " << i << "->" << arr[i] << " with " 
                << j << "->" << arr[j] << endl;
            */

            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            
            
        }
        j++;
    }
    
    

    i++;
    temp = arr[end - 1];
    arr[end - 1] = arr[i];
    arr[i] = temp;

    QuickSort(arr, start, i);
    QuickSort(arr, i + 1, end);

   
    for (int n = start; n < end; n++)
    {
        std::cout << arr[n] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int ArrayToSort[]{17, 5, 11, 2, 21, 16, 40, 9, 70, 6, 9};
    //MergeSort(ArrayToSort, 11);
    QuickSort(ArrayToSort, 0, 11);
    return 0;
}