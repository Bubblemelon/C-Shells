# Problem Statement for ScrambledI.cpp:  

Once upon a day, Mary bought a one-way ticket from somewhere to somewhere with some flight transfers.  

For example: SFO->DFW DFW->JFK JFK->MIA MIA->ORD.  

Obviously, transfer flights at a city twice or more doesn't make any sense. So Mary will not do that.  

Unfortunately, after she received the tickets, she messed up the tickets and she forgot the order of the ticket.  

Help Mary rearrange the tickets to make the tickets in correct order.  

# Input Explained:

```
2  \\ 2 Test Cases
1   \\ Number of Flights
SFO \\ Source and Destination to Sort
DFW
4  \\ Number of Flights
MIA \\ Source and Destination to Sort
ORD
DFW
JFK
SFO
DFW
JFK
MIA  
```

# Output Explained:  


Output is in the following format:  

`Case #x: itinerary`

Where `itinerary`: is a sorted list of flight tickets which represents the actual itinerary.

Each flight segment in the itinerary should be printed as pairs of source-destination airport codes.

```
Case #1: SFO-DFW
Case #2: SFO-DFW DFW-JFK JFK-MIA MIA-ORD

```

**Compile + Run**:

```
g++ ScrambledI.cpp
```

[Go to Question Source](https://code.google.com/codejam/contest/4374486/dashboard#s=p2)  
