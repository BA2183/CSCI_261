First, refactor the code to place function prototypes above main().
Then, place the corresponding function definitinos below main().

Build your program.

Run the executable through the debugger.  Perform the following steps.  For each step, add the command that performs that task.

1. Add a breakpoint inside the print_result() function.
b 64

2. Run the program, requesting to add 4 and 5
run 
4
5
a 

3. Print the stack trace
bt

4. Print the current stack frame
frame

5. Print all local variables and arguments within the scope of the current stack frame
info locals
info args 

6. Move up one level in the stack frame
up

7. Print all local variables and arguments within the scope of the current stack frame
info locals
info args 

8. Continue the program, requesting to subtract the values
continue
s

9. Print the stack trace again
bt

10. Step through the program until we have moved out of the two lower stack frames
step 
step 

11. Print the stack trace again
bt 

12. Kill the program
kill 
y 
q