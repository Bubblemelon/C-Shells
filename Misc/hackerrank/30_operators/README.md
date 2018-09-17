# Problem Statement for op.cpp:  

There are 3 lines of numeric input:  

The first line has a double, `mealCost` (the cost of the meal before tax and tip).   
The second line has an integer, `tipPercent` (the percentage of  being added as tip.   
The third line has an integer, `taxPercent` (the percentage of  being added as tax).  
The returned output is the `totalCost`, a rounded integer. 

# Expected behaviour for the sample and case files:

```
//sample

12.00
20
8

// returns

15

// totalCost = 12 + 2.4 + 0.96 = 15.36
```

```
//case 1

15.50
15
10

//returns 

19 

// totalCost = 15.5 + 2.325 + 1.55 = 19.375
```

```
//case 2

19.80
20
30

//returns 

30

// totalCost = 19.80 + 3.90 + 5.85 = 29.55
```

```
//case 3

10.25
17
5

//returns 

13

// totalCost = 10.25 + 1.7425 + 0.5125 = 12.505
```


**Compile + Run**:  

`gcc -lstdc++ op.cpp -o op` or `g++ op.cpp -o op`  

`./op < case1.txt`

To have the outputs placed onto a file:  

`./op < case1.txt > op-output.txt`

[Go to Question Source](https://www.hackerrank.com/challenges/30-operators/problem
)  
