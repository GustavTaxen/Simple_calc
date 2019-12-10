# Simple_calc
A small simple calculator by Fadi.

Syntax:
		<register> <operation> <value>
		print <register>
		quit

-----------------------------------

Using MinGW to build and compile:
    g++ main.cpp
    
Running:
    a.exe

Running with file as input:
    a.exe test.txt

ELSE using Visual studio:
  > Build the solution and let it compile
  > Go to <project-name>/Debug and the exe file should be there.


-----------------------------------

Assumption 1: Not allowed to write closed loops.
Do NOT write values that depends on each other and creates a closed loop. Asssuming that it didn't have to be handled. 
For example: 
      result add revenue
      cee add result
      revenue add cee 
      cee add 5
      revenue add 200
      print result
      QUIT


Assumption 2: Not allowed to write values that are empty.
