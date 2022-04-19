First, refactor the code to place function prototypes in a separate header file named calculator_functions.h.
Then, place the corresponding function definitinos in a separate source file named calculator_functions.cpp.
Finally, modify your Makefile to build the calculator_functions.cpp source file.

Build your program.

Run the executable through the debugger.  Perform the following steps.  For each step, add the command that performs that task.

1a. Add a breakpoint inside the print_result() function.
b calculator_functions.cpp:15

1b. What different in how we need to specify the breakpoint compared to L2D?
adding the source file name needed to add breakpoint to

2. Run the program, requesting to add 4 and 5
Run
4
5
a

3a. Print the stack trace
bt

3b. What's different in how the stack trace is formed compared to L2D?
the lowest 3 traces are from calculator_functions.cpp then it return to main.cpp

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