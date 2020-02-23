#include <stdio.h>
#include <stdbool.h>

/* Takes an int array and returns the sum of the 1st and 3rd element. */
int sumIndex0and2(int array[]);

/* Returns the sum of all elements
in the subarray starting with index start until index end */
int sumOfSubarray(int array[], int start, int end);

/* Returns the largest subarray sum of elements */
int largestSubarraySum(int array[], int array_size);

/* Returns the largest sum from the elements in an array */
int largestSum(int array[], int array_size);


/////////////////////////////////////////////////////////////

int sumIndex0and2( int array[]){
    return array[0] + array[2];
}

int sumOfSubarray(int array[], int start, int end){
    int total = 0;

    for(int i = start; i <= end; i++){
        total += array[i];
    }
    return total;
}

int largestSubarraySum(int array[], int array_size){

    int temp, result = 0;

    for(int i = 0; i < array_size; i++){
        for(int j = i + 1; j < array_size; j++){

            temp = sumOfSubarray(array, i, j);

            // update result with any larger subarray sum
            if(result < temp){
                result = temp;
            }
        }
    }

    return result;
}



int largestSubarraySum(int array[], int array_size){

    int temp, result = 0;

    for(int i = 0; i < array_size; i++){
        for(int j = i + 1; j < array_size; j++){

            temp = sumOfSubarray(array, i, j);

            // update result with any larger subarray sum
            if(result < temp){
                result = temp;
            }
        }
    }

    return result;
}

// find the size of a referenced array is inaccurate
// int array[] === int *array
int largestSum(int array[], int array_size){

    int result = 0;

    for(int i = 0; i < array_size; i++){

        if(result < (result + array[i])){
            result += array[i];
        }
    }

    return result;
}

int main()
{
    int a[6] =  {1 , -3 , 2 , 9 , -2 , 10};

    int array_size = sizeof(a)/sizeof(a[0]);

    printf("*** Array Manipulation ***");

    /* Checks to see if there are at least 3 elements in the array. */
    if( array_size < 3 ){
        printf("Size of array needs to have at least 3 elements.");
        return 0;
    }

    // a[0] = 1
    // a[2] = 2
    printf("The sum of the 1st and 3rd elements: %d\n", sumIndex0and2(a));

    // Outputs 8 ( -3 + 2 + 9 = 8)
    printf("Sum of indexes from 1 to 3: %d\n" , sumOfSubarray ( a, 1 , 3));

    // Outputs -2 (1 + ( -3) = -2)
    printf("Sum of indexes from 0 to 1: %d\n" , sumOfSubarray ( a, 0 , 1));

    // Outputs 1 + 2 + 9 + 10 = 22
    printf("The largest sum of elements in the array: %d\n", largestSum(a, array_size));

    // Outputs [2, 9, -2, 10] = 19
    printf("The subarray sum of elements from the array: %d\n", largestSubarraySum(a, array_size));

    return 0;
}