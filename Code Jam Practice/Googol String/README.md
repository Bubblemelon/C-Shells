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

``g++ Googol.cpp`   

``

To have the outputs placed onto a file:  

``

[Go to Question Source](https://code.google.com/codejam/contest/4374486/dashboard#s=p1)  
