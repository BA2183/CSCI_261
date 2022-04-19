For this lab, your tasks are as follows.  Provide the answers after each number.  Show your work for each step.

1a. Convert the decimal number 1,904,803,840 to 32-bit two's complement binary representation.
1,904,803,840/2 r:0
952,401,920/2 r:0
476,200,960/2 r:0
281,100,480/2 r:0
119,050,240/2 r:0
59,525,120/2 r:0
29,762,560/2 r:0
14,881,280/2 r:0
7,440,640/2 r:0
3,730,320/2 r:0
1,860,260/2 r:0
930,080/2 r:0
465,040/2 r:0
232,520/2 r:0
116,260/2 r:0
58,130/2 r:0
29,065/2 r:1
14,532/2 r:0
7,266/2 r:0
3,633/2 r:1
1,816/2 r:0
908/2 r:0
454/2 r:0
227/2 r:1
113/2 r:1
56/2 r:0
28/2 r:0
14/2 r:0
7/2 r:1
3/2 r:1
1/2 r:1

[0111 0001 1000 1001 0000 0000 0000 0000]

1b. Represent the value in hexadecimal. 
0111 0001 1000 1001 0000 0000 0000 0000
 07   01   08   09   00   00   00   00
[71890000]

2a. Convert the decimal number -1,047,986,176 to 32-bit two's complement binary representation.
1,047,986,176/2 r:0
523,993,088/2 r:0
261,996,544/2 r:0
130,998,272/2 r:0
65,499,136/2 r:0
32,749,568/2 r:0
16,374,784/2 r:0 
8,187,392/2 r:0
4,093,696/2 r:0
2,046,848/2 r:0
1,023,424/2 r:0
511,712/2 r:0
255,856/2 r:0
127,928/2 r:0
63,964/2 r:0
31,982/2 r:0
15,991/2 r:1
7,995/2 r:1
3,997/2 r:1
1,998/2 r:0
999/2 r:1
499/2 r:1
249/2 r:1
124/2 r:0
62/2 r:0
31/2 r:1
15/2 r:1
7/2 r:1
3/2 r:1
1/2 r:1

0011 1110 0111 0111 0000 0000 0000 0000
               flip bits
1100 0001 1000 1000 1111 1111 1111 1111
                                     +1
[1100 0001 1000 1001 0000 0000 0000 0000]

2b. Represent the value in hexadecimal.
1100 0001 1000 1001 0000 0000 0000 0000
12=C  01   08   09   00   00   00   00
[C1890000]
3a. Convert the decimal number 17.125 to 32-bit floating point precsision.
17/2 r:1
8/2 r:0
4/2 r:0
2/2 r:0
1/2 r:1
17 --> 10001

2^-1 = 0.5 X
2^-2 = 0.25 X
2^-3 = 0.125
=> .001
0.125 = .001 
17.125 = 10001.001 --> 1.0001001 x 2^4
bias = 2^(8-1) - 1 = 127
bias + e = 127 + 4 = 131
131 -->  1000 0011

[17.125 --> 0 1000 0011 1000 1001 0000 0000 0000 000]

3b. Represent the value in hexadecimal.
0100 0001 1100 0100 1000 0000 0000 0000
 04   01  12=C  04   08   00   00   00
41C48000
4a. Convert the decimal number -17.125 to 32-bit floating point precision.
17/2 r:1
8/2 r:0
4/2 r:0
2/2 r:0
1/2 r:1
17 --> 10001

2^-1 = 0.5 X
2^-2 = 0.25 X
2^-3 = 0.125
=> .001
0.125 = .001 

17.125 = 10001.001 --> 1.0001001 x 2^4
bias = 2^(8-1) - 1 = 127
bias + e = 127 + 4 = 131
131 -->  1000 0011

NEGATIVE --> first bit = 1

[-17.125 --> 1 1000 0011 1000 1001 0000 0000 0000 000]

4b. Represent the value in hexadecimal.
1100 0001 1100 0100 1000 0000 0000 0000
12=C  01  12=C  04   08   00   00   00
[C1C48000]
5a. Convert the hexadecimal value 0xC3890000 to binary.
 C=12  03   08   09   00   00   00   00
[1100 0011 1000 1001 0000 0000 0000 0000]
5b. Convert the binary to a signed decimal integer value using two's complement.
0x2^01=0 +
0x2^02=0 +
0x2^03=0 +
0x2^04=0 +
0x2^05=0 +
0x2^06=0 +
0x2^07=0 +
0x2^08=0 +
0x2^09=0 +
0x2^10=0 +
0x2^11=0 +
0x2^12=0 +
0x2^13=0 +
0x2^14=0 +
0x2^15=0 +
0x2^16=0 +
1x2^17=131,072 +
0x2^18=0 +
0x2^19=0 +
1x2^20=1,038,576 +
0x2^21=0 +
0x2^22=0 +
0x2^23=0 +
1x2^24=16,777,216 +
1x2^25=33,554,432 +
1x2^26=67,108,864 +
0x2^27=0 +
0x2^28=0 +
0x2^29=0 +
0x2^30=0 +
1x2^31=2,147,483,648 +
(-1)1x2^32=-4,294,967,296
1100 0011 1000 1001 0000 0000 0000 0000 = 131,072 + 1,038,576 + 16,777,216 + 33,554,432 + 67,108,864 + 2,147,483,648 - 4,294,967,296
                                        = [-2,028,873,488]
5c. Convert the binary to a floating point decimal value.
2,028,873,488 --> 111 1000 1110 1110 0010 0111 0001 0000 --> 1.11 1000 1110 1110 0010 0111 0001 0000 x 2^28

bias = 2^(10-1)-1 = 511
bias + e = 511 + 28 = 539
529 --> 10 0001 1011

NEGATIVE --> first bit = 1

[-2,028,873,488 --> 1 10 0001 1011 111 1000 1110 1110 0010 0111 0001 0000]

6.  Using a terminal, perform the following steps.  List the commands used to perform the tasks:

- print the current directory you are in when the terminal opens
pwd

- move into the lab1b_folder directory
cd lab1b_folder

- list the contents of the directory
ls

- move into the data directory
cd lab1b_folder/data

- rename the misspelled file fil2.txt to be file2.txt
mv fil2.txt file2.txt

- copy file1.txt to be file3.txt
cp file1.txt file3.txt

- make a new file named file4.txt
ni file4.txt

- move to the parent directory
cd ..

- make a directory named bin
mkdir bin

- compile main.cpp into an executable
g++ main.cpp

- move the generated executable into the bin folder and rename it to be lab1b
mv a.exe bin
cd bin
mv a.exe lab1b


- print the current directory you are currently in
cd

- run the new executable from your current directory
start a.exe
.\a.exe

What to submit?
Submit this README.txt with the completed responses.
