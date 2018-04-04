# Problem Statement for Googol.cpp:  


A "0/1 string" is a string in which every character is either 0 or 1. There are two operations that can be performed on a 0/1 string:  

<br/>

switch: Every 0 becomes 1 and every 1 becomes 0. For example, "100" becomes "011".
reverse: The string is reversed. For example, "100" becomes "001".  
Consider this infinite sequence of 0/1 strings:  

```
S0 = ""  

S1 = "0"  

S2 = "001"  

S3 = "0010011"  

S4 = "001001100011011"  
```
...

`SN = SN-1 + "0" + switch(reverse(SN-1)).`

You need to figure out the `Kth` character of S_googol, where googol = 10^100.  

# Input Explained:  

```
4 \\ 4 Test Cases  
1 \\ What is the digit at the 1st position of S_googol?  
2 \\ What is the digit at the 2nd position of S_googol?  
3 \\ What is the digit at the 3rd position of S_googol?  
10 \\ What is the digit at the 10th position of S_googol?  
```

# Output Explained:  

```
Case #1: 0  
Case #2: 0  
Case #3: 1  
Case #4: 0

Using S4 as an example: "[0] [0] [1] 001100 [0] 11011"  
The digits in [] correspond to the output above.  

Note: the 1st position starts at 1 not Zero.  
```

**Compile + Run**:  

```
g++ Googol.cpp   

```

To have the outputs placed onto a file:  

```
g++ Googol.cpp sample.in > output.txt
```

To debug:

```
g++ Googol.cpp -g -Wall
```

[Go to Question Source](https://code.google.com/codejam/contest/4374486/dashboard#s=p1)

-----
**Googol Project File Status**:

Segmentation Fault + Memory Leaks - `gdb` Output:

```
(gdb) file a.out
Reading symbols from a.out...done.
(gdb) run B-small-practice.i
Starting program: /home/catbug/Desktop/C-Shells/Code Jam Practice/Googol String/a.out B-small-practice.i
[Inferior 1 (process 6995) exited normally]
(gdb) run B-small-practice.in
Starting program: /home/catbug/Desktop/C-Shells/Code Jam Practice/Googol String/a.out B-small-practice.in
Case #1: 0

Program received signal SIGSEGV, Segmentation fault.
0x0000555555555784 in reverseNSwitch (
    sn_1="11011001110010011101100011001001110110011100100011011000110010011101100111001001110110001100100011011001110010001101100011001001110110011100100111011000110010011101100111001000110110001100100011011001"...) at Googol.cpp:35
warning: Source file is more recent than executable.
35	    std::strcpy( char_array, sn_1.c_str() );
(gdb) quit

```

`a.out` Program works when kth is less than 100.   

**Plan of Action**:

Debug using Valgrind.
[Tips on Usage](https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks)  

```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -v --log-file=valgrind-out.txt ./a.out B-small-practice.in

```
Refer to valgrind-out.txt.
