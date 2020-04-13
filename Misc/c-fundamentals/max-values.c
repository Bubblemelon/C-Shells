#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=vs-2019
#include <limits.h>

 // long long >= long >= int >= short >= char
int main(){

    /* Lower & Upper Bound for unsigned int:
     *
     * 0 to 4,294,967,295 -- identifier %u
     * 0 to UINT_MAX
     */
    const unsigned int PASS_UNSIGNED_INT = 0;

    /* Lower & Upper Bound for short int:
     *
     * -32,768 to 32,767 -- identifier %hd
     * SHRT_MIN to SHRT_MAX
     */
    const short int PASS_SHORT_INT = 0;

    /* Lower & Upper Bound for unsigned long:
     *
     * 0 to 4,294,967,295 -- identifier %lu
     * 0 to ULONG_MAX
     */
    const unsigned long PASS_UNSIGNED_LONG = 0;

    clock_t start, end;
    float seconds;

    // Another way to find the max value of a data type:
    //
    // printf("UINT_MAX = %u", UINT_MAX);
    // printf("Unsigned int max = %u", ( pow(2, ((sizeof(PASS_UNSIGNED_INT) * 8) / 2) - 1 )));

    start = clock();
    for(unsigned int i = 0; i < UINT_MAX; i++){
        if(i == PASS_UNSIGNED_INT) {
            break;
        }
    }
    end = clock();

    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nPassword guess for 'unsigned int' of %u took %fs.\n", PASS_UNSIGNED_INT, seconds);



    start = clock();
    for(short int i = SHRT_MIN; i < SHRT_MAX; i++){
        if(i == PASS_SHORT_INT) {
            break;
        }
    }
    end = clock();

    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("\nPassword guess for 'short int' of %hd took %fs.\n", PASS_SHORT_INT, seconds);



    start = clock();
    for(unsigned long i = 0; i < ULONG_MAX; i++){
        if(i == PASS_UNSIGNED_LONG) {
            break;
        }
    }
    end = clock();

    seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("\nPassword guess for 'unsigned long' of %lu took %fs.\n\n", PASS_UNSIGNED_LONG, seconds);


    printf("-1 in unsigned int is: %u\n", -1); // 4294967295
    printf("-100 in unsigned long is: %lu\n", -1); // 4294967295

    /* Signed-to-unsigned conversion is modulo UINT_MAX + 1.
       -1 will be converted to UINT_MAX i.e.
       0xffffffff or 4294967295 if 'unsigned int' is 32 bits.
       https://stackoverflow.com/a/7152835/7072506 */

    return 0;

    /* NOTES

    The time it takes to guess PASS_* depends on the where the value is between the data type's lower and upper bounds. E.g. if PASS_*'s is numeric value '0', then 'unsigned long' and 'unsigned int' will be faster than 'short int'. This is because the range for 'short int' extents to negative values. Hence, to guess PASS_* in 'short int' would need to go through all negative values before getting to '0'.

    'unsigned' data types cannot handle negative values, so if PASS_* were
    in fact a negative value. `unsigned int` and `unsigned long` will take the
    longest to run since the inaccurate conversion of a negative value approaches their type's maximum/upper bound.
    */
}