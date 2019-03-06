## Network Token-based Access Scheme

1. A network node can send its packet out if and only if it holds the token
2. The network token times out per 15 seconds
3. If the token times out, but the active network node is still sending packets, wait until it is finished

## C++ Event-Driven Programming
* Conforms to Google C++ style guide except for indentation (I use 4 spaces instead of 2)
* Four network events which are specific to this simulation are defined in `network_events.h`
* All event handlers are lambdas, see `Network::Network()`
* When an event is fired, all handlers of that event type will be invoked

## Run
Requires g++ with C++11 support
```
$ make 
$ make run
```

## Result
```
MC	Arr1	Dep1	Size1	Arr2	Dep2	Size2	Arr3	Dep3	Size3	Node no	Timeout	Next pass
0	2	 	0	4	 	0	6	 	0	1	 	1
1	2	 	0	4	 	0	6	 	0	2	 	2
2	12	 	1	4	 	0	6	 	0	3	 	3
3	12	9	1	4	 	0	6	 	0	1	18	 
4	12	9	1	19	 	1	6	 	0	1	18	 
6	12	9	1	19	 	1	26	 	1	1	18	 
9	12	 	0	19	 	1	26	 	1	1	 	10
10	12	 	0	19	16	1	26	 	1	2	25	 
12	22	 	1	19	16	1	26	 	1	2	25	 
16	22	 	1	19	 	0	26	 	1	2	 	17
17	22	 	1	19	 	0	26	23	1	3	32	 
19	22	 	1	34	 	1	26	23	1	3	32	 
22	32	 	2	34	 	1	26	23	1	3	32	 
23	32	 	2	34	 	1	26	 	0	3	 	24
24	32	30	2	34	 	1	26	 	0	1	39	 
26	32	30	2	34	 	1	46	 	1	1	39	 
30	32	36	1	34	 	1	46	 	1	1	39	 
32	42	36	2	34	 	1	46	 	1	1	39	 
34	42	36	2	49	 	2	46	 	1	1	39	 
36	42	42	1	49	 	2	46	 	1	1	39	 
39	42	42	1	49	 	2	46	 	1	1	*	 
42	52	42	2	49	 	2	46	 	1	1	*	 
42	52	 	1	49	 	2	46	 	1	1	 	43
43	52	 	1	49	49	2	46	 	1	2	58	 
46	52	 	1	49	49	2	66	 	2	2	58	 
49	52	 	1	64	49	3	66	 	2	2	58	 
49	52	 	1	64	55	2	66	 	2	2	58	 
52	62	 	2	64	55	2	66	 	2	2	58	 
55	62	 	2	64	61	1	66	 	2	2	58	 
58	62	 	2	64	61	1	66	 	2	2	*	 
61	62	 	2	64	 	0	66	 	2	2	 	62
62	72	 	3	64	 	0	66	68	2	3	77	 
64	72	 	3	79	 	1	66	68	2	3	77	 
66	72	 	3	79	 	1	86	68	3	3	77	 
68	72	 	3	79	 	1	86	74	2	3	77	 
```
