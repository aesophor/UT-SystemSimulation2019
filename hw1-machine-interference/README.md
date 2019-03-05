## Machine Interference
Given N machines, with each machine being able to work
for 5 time units before breaking down and needed to be repaired.

## Terms
* MC (Master Clock)
* CL1 (Next broken time of Machine 1)
* CL2 (Next broken time of Machine 2)
* CL3 (Next broken time of Machine 3)
* CL4 (Next repairment complete time)
* n (Repair queue size)
* R (The status of the repair man)

## Result
```
MC	CL1	CL2	CL3	CL4	n	R
0	1	4	9	-	0	idle
1	-	4	9	6	1	busy
4	-	-	9	6	2	busy
6	16	-	9	11	1	busy
9	16	-	-	11	2	busy
11	16	21	-	16	1	busy
16	-	21	-	16	2	busy
16	-	21	26	21	1	busy
21	-	-	26	21	2	busy
21	31	-	26	26	1	busy
26	31	-	-	26	2	busy
26	31	36	-	31	1	busy
31	-	36	-	31	2	busy
31	-	36	41	36	1	busy
36	-	-	41	36	2	busy
36	46	-	41	41	1	busy
```
