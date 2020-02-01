# C-Shells

My exploration with C and C++.

![C++ GIF](https://media.giphy.com/media/7TcdDvbmG7qmqxTIYU/giphy.gif)

<p style="color:rgb(255, 99, 71, 0.5);"><i>C shells by the sea shore, buffer overflow by adding more?</i></p>

## Notes + References

Table of Contents:

| Sections          | Description         |
| ----------------- | ------------------- |
| [Links](#links) | External references |
| [Better Usage](#better-usage) |  Usage mistakes explained and corrected |
| [Tools](#tools) | A list of compilation and debugging tools |
| [Notes](#notes) | A list of notes I've made on C and C++ programming |

-----

#### [Links](#links):

- [`int main(int argc, char const *argv[])`
  Explained](https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean)
> Refer to the [main-args]() folder to test out this explanation.

- [What is a Segmentation
  Fault?](https://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault?rq=1)

- [Difference between `cin.getline` vs `getline]()`
  ](https://stackoverflow.com/questions/4872361/why-are-there-two-different-getline-functions-if-indeed-there-are)
> Global `getline()` works with C++ `std::string` objects
>
> `std::cin.getline()` from `<istream>` works with classic C strings i.e.
> pointers to char.

- [Difference between `cin` vs
  `cin.get()`](https://stackoverflow.com/questions/29630513/difference-between-cin-and-cin-get-for-char-array)
> `cin` reads a word e.g. digits/chars separated by whitespace.
>
> `std::getline(std::cin, char a);` gets the whole line from user and stores in
> `a`.
>
> `cin.get(char a, streamsize n);cin.get();` gets the whole line (stores in
> `a`), then takes in end-of-line character. Repeat this to get a the next line.
>
> `cin.get(char a, streamsize n)` gets the whole line (stores in `a`), but
> repeating this line gives no more input.

- [`>>` Operator skips
  whitespace](https://stackoverflow.com/questions/30005015/whats-the-difference-between-getline-and-stdistreamoperator)
> the `>>` operator of `std::istream` reads space separated strings

- [Convert a String to a `Char[]`
  Array](https://www.geeksforgeeks.org/convert-string-char-array-cpp/)

- [Convert a `Char[]` Array to a
  String](https://stackoverflow.com/questions/8960087/how-to-convert-a-char-array-to-a-string)

- [Convert a `string` to an
  `int`](https://www.geeksforgeeks.org/converting-strings-numbers-cc/)
> `stringstream()`: converts strings of digits into ints, floats or doubles.
> `atoi()`: Only works on C-style strings (character array and string literals).
> `stoi()`: C++ 11 only compatible and works for both C++ strings and C style
> strings.

- [Getting the Size of an
  Array](https://stackoverflow.com/questions/4108313/how-do-i-find-the-length-of-an-array)
> One of the shortcuts listed in the above link: `sizeof( myArray )` is total
> number of bytes allocated for that array. `sizeof( myArray[0] )` is the number
> of bytes for one element.
>
> `sizeof( myArray ) / sizeof( myArray[0] )` is the number of elements in the
> array.

- [Undeclared Identifier
  Error](https://stackoverflow.com/questions/22197030/what-is-an-undeclared-identifier-error-and-how-do-i-fix-it)
> e.g. when using a function above/before where it was defined in the script.

- [Type Casting in C vs in
  C++](https://stackoverflow.com/questions/103512/why-use-static-castintx-instead-of-intx)
> e.g. C++ `static_cast<int>(x)` vs C `(int)x`

- [How to do Rounding in
  C++](https://www.programiz.com/cpp-programming/library-function/cmath/round
  )
> e.g. `round(0.5)` becomes `1`


-----
#### [Better Usage](#better-usage):

Mistakes on Usage Explained and Resolved.

##### When using: `#include <fstream>`

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

(1) `./a.out < file.txt` (2) `./a.out file.txt`

Reasons:


(1) End of File is never reached. `cin` keeps storing the content from the file,
and `cout` keeps printing onto the terminal. Due to the `< file.txt` portion, a
file is never fed into the program. The reason for this is:

> `./a.out < file.txt` is considered as only `1` argument i.e. `./a.out`; Fixing
> `argv[0]` to `argv[3]` does not work because doing `< file.txt` is being
> utilised by `cin`.

(2) End of File is never reached. Although `2` arguments are fed into the
program, i.e. `./a.out` and `file.txt`, file `file.txt` was never opened:

> Nothing happens when the program runs, since there was no file opened. Adding
> a boolean check like with `input_file.is_open()` could be useful to see if the
> file was successfully opened.
>
> First, `std::ifstream input_file( argv[0] );` should be corrected to
> `std::ifstream input_file( argv[1] );`. `argv[0]` is actually refering to
> `./a.out` so having `argv[1]` refers to `file.txt`.
>
> Note: having `argv[1]` unchanged, will show that the file is opened when using
> `input_file.is_open()` because `a.out` itself is a file.
>
> Second, regardless of whether the above fix was made, the program now waits
> for a _user's input_ from `cin`. This loops forever, and will proceed to ask
> for a user's input forever (only if an int/number was given). If an anything
> other than a number was given, an infinite/forever loop of zeros will show.
>
> The infinite loop happens, because this program never reaches the end of files
> `argv[1]` or `argv[0]`.


##### The ifstream Object

Use the constructor and let its destuctor do the work of opening and closing the
file.
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

-----

#### [Tools](#tools):

Compiler versions:

`gcc (GCC) 10.2.1 20200723 (Red Hat 10.2.1-1)`

`gcc (Ubuntu 5.5.0-12ubuntu1) 5.5.0 20171010`

Debugging tools:

`GNU gdb (GDB) Fedora 9.1-6.fc32`

`GNU gdb (GDB) 8.1`
> Error encountered during usage on Mac OSX:
>
> `Unable to find Mach task port for process-id 7234: (os/kern) failure (0x5).
 (please check gdb is codesigned - see taskgated(8))`
>
> **To resolve issue above**:
>
>
> [Link to the related Github Issue](https://github.com/cs01/gdbgui/issues/55)
> - This more reader friendly, as in not txt file print but the content
>   mentioned in the above link was copied from
>   [this](https://gcc.gnu.org/onlinedocs/gnat_ugn/Codesigning-the-Debugger.html).
>
> [Similar but for
> lldb](https://opensource.apple.com/source/lldb/lldb-69/docs/code-signing.txt)
> - The work around "the bug" that this link is referring to can be found
>   [here](https://apple.stackexchange.com/questions/309017/unknown-error-2-147-414-007-on-creating-certificate-with-certificate-assist
>   ).
>
>
> **How I resolved this:**:
>
> Before creating the certificate, check the version of gdb by doing `gdb
> --version`.
> - if it is not version 8.0.1, then do the following:
>   1. Run `brew uninstall gdb`, if that doesn't work then do, `brew uninstall
>      --force gdb`. Doing `brew unlink gdb` may work instead, look at this
>      [discussion](https://stackoverflow.com/questions/49001329/gdb-doesnt-work-on-macos-high-sierra-10-13-3).
>   3. Now do `brew install
>      https://raw.githubusercontent.com/Homebrew/homebrew-core/c3128a5c335bd2fa75ffba9d721e9910134e4644/Formula/gdb.rb`.
>
> For more information on the above, refer to this on
> [StackOverFlow](https://stackoverflow.com/questions/49001329/gdb-doesnt-work-on-macos-high-sierra-10-13-3).
>
> The following are steps to codesign gdb:
>
> 1. In Keychain Access (toolbar i.e. where system time is displayed), go to
>    Certificate Assistant and Create a Certificate.
> 2. Enter a relatable name for this Certificate e.g. "gdb_cert".
> 3. Fill in the following and then click create:
>   - Identity Type: Self Signed Root
>   - Certificate Type: Code Signing
> 4. Double click on the Certificate which can be found in "Login" category.
> 5. In the popup window, click on the "Trust" arrow and select "Always Trust"
>    when using this Certificate.
> 6. Drag this Certificate from the Login category to "System".
> 7. Run `killall taskgated`:
>   - if `No matching processes belonging to you were found` then do `ps aux |
>     grep taskgated`
> 8. Finally run `codesign -fs nameofcertificate /usr/local/bin/gdb`:
>   - To find path location of gdb run `which gdb`
>   - This command does not need to be in the same directory of the Certificate
> 9. Restart machine.
> - Additional sources:
>   - [Apple Stack
>     Exchange](https://apple.stackexchange.com/questions/309017/unknown-error-2-147-414-007-on-creating-certificate-with-certificate-assist
>     )
>   - [Github Gist
>     Discussion](https://gist.github.com/gravitylow/fb595186ce6068537a6e9da6d8b5b96d)
>
> **This may happen:**
>
> `(gdb) file a.out` `\"a.out\": not in executable format: File format not
> recognized`
>
> Do `g++ -m32 filename.cpp -g -Wall` to resolve, as noted
> [here](https://stackoverflow.com/questions/47639685/gdb-error-not-in-executable-format-file-format-not-recognized),
> existing GDB installed may be the x86_32 version.
>


`valgrind-3.13.0`

-----

#### [Notes](#notes):

These are links to a separate README.md.

- [Functions](/Misc/Notes/README.md#functions)

- [Header Files](/Misc/Notes/README.md#header-files)

- [Interface](/Misc/Notes/README.md#interface)

- [Parameters](/Misc/Notes/README.md#parameters)

- [Pointers](/Misc/Notes/README.md#pointers)

- [Preprocessor](/Misc/Notes/README.md#preprocessor)

- [Scope of Identifiers](/Misc/Notes/README.md#scope-of-identifiers)

- [Variables](/Notes/README.md#variables)
