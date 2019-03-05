## Machine Interference
Given N machines, with each machine being able to work
for 5 time units before breaking down and needed to be repaired.

Repairing a machine takes 5 time units.

## Terms
* MC (Master Clock)
* CL1 (Next broken time of Machine 1)
* CL2 (Next broken time of Machine 2)
* CL3 (Next broken time of Machine 3)
* CL4 (Next repairment complete time)
* n (Repair queue size)
* R (The status of the repair man)

## Result
Initial states: 1, 4, 9
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

Initial states: 2, 3, 8
```
MC	CL1	CL2	CL3	CL4	n	R
0	2	3	8	-	0	idle
2	-	3	8	7	1	busy
3	-	-	8	7	2	busy
7	17	-	8	12	1	busy
8	17	-	-	12	2	busy
12	17	22	-	17	1	busy
17	-	22	-	17	2	busy
17	-	22	27	22	1	busy
22	-	-	27	22	2	busy
22	32	-	27	27	1	busy
27	32	-	-	27	2	busy
27	32	37	-	32	1	busy
32	-	37	-	32	2	busy
32	-	37	42	37	1	busy
37	-	-	42	37	2	busy
37	47	-	42	42	1	busy
```
