.ORIG x3000 ;the address in memory where the program will be loaded 
LEA R0, HELLO_STR
into R0
PUTs
;console 
HALT
HELLO_STR .STRINGZ "hello world"
.END
