## Network Token-based Access Scheme

1. A network node can send its packet out if and only if it holds the token
2. The network token times out per 15 seconds
3. If the token times out, but the active network node is still sending packets, wait until it is finished

## Result
MC	Arr1	Dep1	Size1	Arr2	Dep2	Size2	Arr3	Dep3	Size3	Node no	Timeout	Next pass
0	2	-1	0	4	-1	0	6	-1	0	1	-1	1
1	2	-1	0	4	-1	0	6	-1	0	2	-1	2
2	12	-1	1	4	-1	0	6	-1	0	3	-1	3
3	12	9	1	4	-1	0	6	-1	0	1	18	-1
4	12	9	1	19	-1	1	6	-1	0	1	18	-1
6	12	9	1	19	-1	1	26	-1	1	1	18	-1
9	12	-1	0	19	-1	1	26	-1	1	1	-1	10
10	12	-1	0	19	16	1	26	-1	1	2	25	-1
12	22	-1	1	19	16	1	26	-1	1	2	25	-1
16	22	-1	1	19	-1	0	26	-1	1	2	-1	17
17	22	-1	1	19	-1	0	26	23	1	3	32	-1
19	22	-1	1	34	-1	1	26	23	1	3	32	-1
22	32	-1	2	34	-1	1	26	23	1	3	32	-1
23	32	-1	2	34	-1	1	26	-1	0	3	-1	24
24	32	30	2	34	-1	1	26	-1	0	1	39	-1
26	32	30	2	34	-1	1	46	-1	1	1	39	-1
30	32	36	1	34	-1	1	46	-1	1	1	39	-1
32	42	36	2	34	-1	1	46	-1	1	1	39	-1
34	42	36	2	49	-1	2	46	-1	1	1	39	-1
36	42	42	1	49	-1	2	46	-1	1	1	39	-1
39	42	42	1	49	-1	2	46	-1	1	1	-2	-1
42	52	42	2	49	-1	2	46	-1	1	1	-2	-1
42	52	-1	1	49	-1	2	46	-1	1	1	-1	43
43	52	-1	1	49	49	2	46	-1	1	2	58	-1
46	52	-1	1	49	49	2	66	-1	2	2	58	-1
49	52	-1	1	64	49	3	66	-1	2	2	58	-1
49	52	-1	1	64	55	2	66	-1	2	2	58	-1
52	62	-1	2	64	55	2	66	-1	2	2	58	-1
55	62	-1	2	64	61	1	66	-1	2	2	58	-1
58	62	-1	2	64	61	1	66	-1	2	2	-2	-1
61	62	-1	2	64	-1	0	66	-1	2	2	-1	62
62	72	-1	3	64	-1	0	66	68	2	3	77	-1
64	72	-1	3	79	-1	1	66	68	2	3	77	-1
66	72	-1	3	79	-1	1	86	68	3	3	77	-1
68	72	-1	3	79	-1	1	86	74	2	3	77	-1
72	82	-1	4	79	-1	1	86	74	2	3	77	-1