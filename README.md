# Revisit Computation Analysis

This repository is related to the paper **Revisiting the Computation Analysis against Internal Encodings in White-Box Implementations** published by Yufeng Tang, Zheng Gong, Bin Li, and Liangju Zhao in TCHES Volume 2023, Issue 4.

This repository contains the source code for the computation analysis on different internal encodings.

The attack results are recorded in "xxx_distinguisher.txt".

## Notes
- ADCA is a higher-degree computation analysis. The attack degree of ADCA can be modified by the param 'attack_degree' of the ADCA funcion.
- ADCA also supports to sum the results of different attack degrees for maximizing the probability of the correct key guess.

## Build

```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Run

```
$ ./ENCA
```
