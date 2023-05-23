// Data Structures Spring 2023
// CS 2413
// Aditya Narasimhan

#include <iostream>
#include <time.h> // for experiments

using namespace std;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Linear Search used on array A
int linearSearch(int array[], int n, int arraySize) {
    int idxLocation = -1;
    
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == n) {
            idxLocation = i;
        }
    }
    return idxLocation;
}


// Binary Search used on array B
int binarySearch(int array[], int n, int low, int high) {
    int idxLocation = -1;
    int mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (n == array[mid]) {
            idxLocation = mid;
            break;
        }
        else if (n > array[mid]) {
            low = mid + 1;
            
        }
        else {
            high = mid - 1;
        }
    }
    
    return idxLocation;
}


// Selection Sort
int * selectionSort(int array[], int arraySize) {
    int temp;
    
    int *B = new int[arraySize];
    
    for (int i = 0; i < arraySize; i++) {
        B[i] = array[i];
    }
    
    for (int i = 0; i < arraySize; i++) {
        for (int j = i+1; j < arraySize; j++) {
            if (B[j] < B[i]) {
                temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
    }
    return B;
}


// Display array
void display(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
}


// Find for Sorted Array
void findInB(int maxSize, int numFinds, int array[], int arraySize, int inputArray[], int inputArraySize) {
    // Find element and print location
    int location;
    
    for (int i = 0; i < inputArraySize; i++) {
        location = binarySearch(array, inputArray[i], 0, arraySize);
        cout << "Element " << inputArray[i];
        
        if (location > -1) {
            cout << "  found at " << location << " in B" << endl;
        }
        else {
            cout << "  not found in B" << endl;
        }
    }
    cout << endl;
}


// Find in unsorted array
void findInA(int maxSize, int numFinds, int array[], int arraySize, int inputArray[], int inputArraySize) {
    // Find element and print location
    int location;
    
    for (int i = 0; i < inputArraySize; i++) {
        location = linearSearch(array, inputArray[i], arraySize);
        cout << "Element " << inputArray[i];

        if (location > -1) {
            cout << "  found at " << location << " in A" << endl;
        }
        else {
            cout << "  not found in A" << endl;
        }
    }
    cout << endl;
}


// Input into array
int * inputArray(int maxSize, int numFinds) {
    int *F = new int[maxSize];
    int fCurSize = 0;
    
    // Read the numbers that need to be found into an array
    for (int i = 0; i < numFinds; i++) {
        cin >> F[i];
        fCurSize++;
    }
    return F;
}


// SumPair finder
void sumPair(int array[], int arraySize, int newArray[], int newArraySize) {
    bool found = false;
    
    for (int i = 0; i < newArraySize; i++) {
        cout << newArray[i] << endl;
        for (int j = 0; j < arraySize; j++) {
            for (int k = 0; k < arraySize; k++) {
                if (array[j] + array[k] == newArray[i] && !found) {
                    cout << " = " << array[j] << " + " << array[k] << endl;
                    found = true;
                }
            }
        }
        found = false;
    }
}


// Remove a given element from array B
int removeB(int array[], int currVal, int newArray[], int newArraySize) {
    int location;
    
    for (int i = 0; i < newArraySize; i++) {
        // Find the location of the element that needs to be removed
        location = binarySearch(array, newArray[i], 0, currVal);
        
        if (location > -1) {
            for (int j = location; j < currVal; j++) {
                array[j] = array[j+1];
            }
            --currVal;
            cout << "Removing " << newArray[i] << " at " << location << " in B" << endl;
        }
        else {
            cout << "Element " << newArray[i] << "  not found in B" << endl;
        }
    }
    return currVal;
}


// Removes a given element from array A
int removeA(int array[], int currVal, int newArray[], int newArraySize) {
    int location;
    
    for (int i = 0; i < newArraySize; i++) {
        // Find the location of the element that needs to be removed
        location = linearSearch(array, newArray[i], currVal);
        
        if (location > -1) {
            for (int j = location; j < currVal; j++) {
                array[j] = array[j+1];
            }
            --currVal;
            cout << "Removing " << newArray[i] << " at " << location << " in A" << endl;
        }
        else {
            cout << "Element " << newArray[i] << "  not found in A" << endl;
        }
    }
    return currVal;
}


// Adds an element to A
void addA(int array[], int currVal, int inputArray[], int inputArraySize) {
    int tempCurrA = currVal;
        for (int i = 0; i < inputArraySize; i++) {
            array[tempCurrA] = inputArray[i];
            tempCurrA++;
            cout << "Inserting " << inputArray[i] << " in A" << endl;
        }
}


//Adds an element to B
void addB(int array[], int currVal, int inputArray[], int inputArraySize) {
    int tempCurrA = currVal;
        for (int i = 0; i < inputArraySize; i++) {
            array[tempCurrA] = inputArray[i];
            tempCurrA++;
            cout << "Inserting " << inputArray[i] << " in B" << endl;
        }
}


int main()
{
    int maxValues; // max number of values to store / length of the arrays
    int currentValues = 0; // as we add, the number of values in the arrays
    int tempVal; // variable used to read the number
    
    cin >> maxValues; // read the maximum number of values from the redirected input file
    
    cout << "Length of the array: " << maxValues << endl;
    
    // TODO create a dynamic array A of size maxValues
    int *A = new int[maxValues];
    
    
    // TODO read in the number from the redirected input
    for (int i = 0; i < maxValues; i++)
    {
        cin >> tempVal;
        A[i] = tempVal;
        ++currentValues;
    }
    
    
    // TODO display the values in array A
    cout << "Array A: ";
    display(A, currentValues);
    cout << endl;
    
    
    // TODO sort the array A and store it in B - any sorting algorithm can be used
    int * B = selectionSort(A, currentValues);
    
    
    // Display the contents of array B
    cout << "Array B: ";
    display(B, currentValues);
    cout << endl;
    cout << endl;
    
    
    // TODO read the commands/options till the end of the file
    char command;
    int numTimes;
    
    while (cin) {
        cin >> command;
        cin >> numTimes;
        
        if (command == 'F') {
            // Find a given number in both array A and B
            cout << "Find:" << endl;
            int * F = inputArray(maxValues, numTimes);
            
            findInB(maxValues, numTimes, B, currentValues, F, numTimes);
            findInA(maxValues, numTimes, A, currentValues, F, numTimes);
            break;
        }
        else if (command == 'A') {
            // Find the SumPairs of a given number of for arrays A and B
            cout << "SumPairs:" << endl;
            int copyCuurentValues = currentValues;
            
            // Creates an array that holds the sums that need to be found
            int * S = inputArray(maxValues, numTimes);
            
            // B
            cout << "B:" << endl;
            sumPair(B, copyCuurentValues, S, numTimes);
            cout << endl;
            cout << endl;
            
            // A
            cout << "A:" << endl;
            sumPair(A, copyCuurentValues, S, numTimes);
            cout << endl;
            break;
        }
        else if (command == 'R') {
            cout << "Remove:" << endl;
            
            // Read the numbers that need to be found into an array
            int * R = inputArray(maxValues, numTimes);
            
            // Find and remove
            
            // B
            int num;
            int copyCurrentValues = currentValues;
            num = removeB(B, copyCurrentValues, R, numTimes);
            cout << endl;
            
            // A
            num = removeA(A, copyCurrentValues, R, numTimes);
            cout << endl;
            
            // Display updated contents of array A and B
            currentValues = num;
            
            //A
            cout << "After removal Array A: ";
            display(A, currentValues);
            cout << endl;
            
            // B
            cout << "After removal Array B: ";
            display(B, currentValues);
            cout << endl;
            cout << endl;
            break;
        }
        else if (command == 'I') {
            // Insert the given numbers into both array A and B
            cout << "Insert:" << endl;
            
            int * I = inputArray(numTimes, numTimes);
            
            maxValues += numTimes;
            
            // Insert
            
            // B
            int copyCurrVal = currentValues;
            
            addB(B, copyCurrVal, I, numTimes);
            int copyVal = copyCurrVal + numTimes;
            B = selectionSort(B, copyVal);
            
            cout << endl;
            
            // A
            addA(A, copyCurrVal, I, numTimes);
            cout << endl;
            currentValues += numTimes;
            
            // Display updated contents of array A and B
            
            //A
            cout << "After insertions Array A: ";
            display(A, currentValues);
            cout << endl;
            
            // B
            cout << "After insertions Array B: ";
            display(B, currentValues);
            cout << endl;
            cout << endl;
            break;
        }
    }
    
    // TODO delete all the dynamically created arrays
    delete[] A;
    delete[] B;
}
