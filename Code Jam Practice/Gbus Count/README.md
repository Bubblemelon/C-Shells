# Problem Statement for GBus.cpp:  

There exists a straight line along which cities are built.

Each city is given a number starting from 1. So if there are 10 cities, city 1 has a number 1, city 2 has a number 2,... city 10 has a number 10.

Different buses (named GBus) operate within different cities, covering all the cities along the way. The cities covered by a GBus are represented as 'first_city_number last_city_number' So, if a GBus covers cities 1 to 10 inclusive, the cities covered by it are represented as '1 10'

We are given the cities covered by all the GBuses. We need to find out how many GBuses go through a particular city.

# Input Explained:  

```
1 // number of test cases (T)
4 // number of GBuses (N)
15 25 30 35 45 50 10 20 //cities covered by Gbuses in the form a_n b_n e.g. Gbus_n covers cities numbered from a_n to b_n
2 // number of outputs (number of GBus counts)
15 // Count #1: Find out how many GBuses goes through City #15
25 // Count #2: Find out how many GBuses goes through City #25
```

# Output Explained:  

```
Case #1: 2 1

2 GBuses go through city 15 (GBus1 [15 25] and GBus4 [10 20])

1 GBus goes through city 25 (GBus1 [15 25])
```

**Compile + Run**:  

`g++ Gbus.cpp`  

`./a < sample.in`  

To have the outputs placed onto a file:  

`./a < sample.in > sample.txt`  

[Go to Question Source](https://code.google.com/codejam/contest/4374486/dashboard)   

**I/O Files:**  

sample.in - The sample input provided on the question page.  
A-small-practice.in - original small input file.   
A-large-practice.in - original large input file.   
[Their respective output files are of the same name but with the ".txt" extension]  

# Outputs Checked:
![https://github.com/Bubblemelon/C-Shells/blob/master/Code%20Jam%20Practice/Gbus%20Count/GBus%20Count%20Submission.png](https://github.com/Bubblemelon/C-Shells/blob/master/Code%20Jam%20Practice/Gbus%20Count/GBus%20Count%20Submission.png=20x20)
