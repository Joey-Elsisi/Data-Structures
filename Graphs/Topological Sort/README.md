


## Assignment:



It turns out that one of our teaching assistants did not take all of the pre-requisite computer science courses! That TA is all ready to graduate, but it turns that CS 1110 was never taken. The department came down hard, and decided to make that TA take all of the courses over again, to have the proper pre-requisite classes completed for each successive class. But the TA just got a job at Microsoft, and can only take one course a semester while working full time. In what order should the teaching assistant take the list of required courses to properly fulfill the pre-requisites this time around?

Given the following course pre-requisite graph:

![pre-reqs.svg](https://aaronbloomfield.github.io/pdr/labs/lab11/pre-reqs.svg)

There are multiple valid orders that the courses can be taken in; each is a valid topological sorts:

-   cs1110 cs2110 cs2102 cs3330 cs2150 cs4414
-   cs1110 cs2110 cs2102 cs2150 cs3330 cs4414
-   cs1110 cs2102 cs2110 cs3330 cs2150 cs4414
-   cs1110 cs2102 cs2110 cs2150 cs3330 cs4414
-   cs1110 cs2110 cs3330 cs2102 cs2150 cs4414

Any one of these topological sorts is sufficient.

### Example

Given the input file:

```
cs2110 cs2150
cs2102 cs2150
cs1110 cs2110
cs3330 cs4414
cs2150 cs4414
cs2110 cs3330
cs1110 cs2102
0 0
```

A valid topological sort would be

```
cs1110 cs2110 cs2102 cs3330 cs2150 cs4414
```
