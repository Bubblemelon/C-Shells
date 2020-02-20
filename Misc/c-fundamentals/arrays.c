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