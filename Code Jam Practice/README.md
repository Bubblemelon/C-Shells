### Content:
- [InOut.cpp]()  

**Kickstart Qs:**  
- [GBus.cpp]()  

**Google Code Jam Qs:**  
- []()

**Notes + References:**


-----
# Getting Started Tutorial:

## [InOut.cpp]()  

# Kickstart Questions:

## [GBus Count]()
## [Googol String]()

# Google Code Jam Questions:

# References:  

-----
## Links:  

- [`int main(int argc, char const *argv[])` Explained](https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean)
- [Difference between `cin.getline` vs `getline]()` ](https://stackoverflow.com/questions/4872361/why-are-there-two-different-getline-functions-if-indeed-there-are)    
- [Difference between `cin` vs `cin.get()`](https://stackoverflow.com/questions/29630513/difference-between-cin-and-cin-get-for-char-array)  
-----

Suppose you have a `file.txt` with the following content:  
```
1
```  
Your `main.cpp` file is of the following:

```
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
  std::ifstream input_file( argv[0] );

  while( !input_file.eof() )
  {
    int num;

    //storing value
    std::cin >> num;

    // printing value
    std::cout << num;

  }
}
```

After compilation, loops happen when:

(1) `./a.out < file.txt`
(2) `./a.out file.txt`

Reasons:


(1) End of File is never reached. `cin` keeps storing the content from the file, and `cout` keeps printing onto the terminal. Due to the `< file.txt` portion, a file is never fed into the program. The reason for this is:  

> `./a.out < file.txt` is considered as only `1` argument i.e. `./a.out`; Fixing `argv[0]` to `argv[3]` does not work because doing `< file.txt` is being utilised by `cin`.  

(2) End of File is never reached. Although `2` arguments are fed into the program, i.e. `./a.out` and `file.txt`, file `file.txt` was never opened:  

> Nothing happens when the program runs, since there was no file opened. Adding a boolean check like with `input_file.is_open()` could be useful to see if the file was successfully opened.  
>
> First, `std::ifstream input_file( argv[0] );` should be corrected to `std::ifstream input_file( argv[1] );`. `argv[0]` is actually refering to `./a.out` so having `argv[1]` refers to `file.txt`.
>
> Note: having `argv[1]` unchanged, will show that the file is opened when using `input_file.is_open()` because `a.out` itself is a file.
>  
> Second, regardless of whether the above fix was made, the program now waits for a _user's input_ from `cin`. This loops forever, and will proceed to ask for a user's input forever (only if an int/number was given). If an anything other than a number was given, an infinite/forever loop of zeros will show.
>
> The infinite loop happens, because this program never reaches the end of files `argv[1]` or `argv[0]`.


-----
ifstream:  
<br/>
Use the constructor and let its destuctor to the work of opening and closing the file
[source](https://stackoverflow.com/questions/13035674/how-to-read-line-by-line-or-a-whole-text-file-at-once)

```
// if this is done:    
std::ifstream input_file( argv[0] );  

// Then the following is unnecessary:  
//
// close the file when parsing is done  
std::ifstream input_file;  

input_file.Open(argv[0]);  

input_file.close();  
```
