
/*
addr  var  val
0000
0001
0002
....
0F01  a     65 -> 66
0F02  b     66 -> 67 -> 68 -> 78
0F03  si    100
0F04  si..  128 
0F05  ...
0F06  pc    0F01 -> 0F02
0F07  pc..
0F08  pc..
0F09  pc..
0F0A  ppc   0F06
0F0B  ppc..
0F0C  ppc..
0F0D  ppc..
0F0E  arr   10    -> 20   -> 30
0F0F  arr   110   -> 120  -> 130
0F10  arr   1010  -> 1020 -> 1030
0F11  i     0     -> 1
0F12  pp
0F13  xxx   34512 (garbage)
0F14  xxx.. ..... (garbage)
0F15  pv    0F01
0F16  pv..
0F17  pv..
0F18  pv..
....
.... main function
1000  ymd.d
1001  ymd.d
1002  ymd.d
1003  ymd.d
1004  ymd.y
1005  ymd.y
1007  ymd.y
1008  ymd.y
1009  ymd.m
100A  ymd.m
100B  ymd.m
100C  ymd.m
....
2000  1000->d
2001
2002
2003
2004  1000->y
2005
2006
2007
2008  1000->m
FFFF
*/