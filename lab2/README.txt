Sheldon Cerejo 
Lab 2 coe 428
January 23rd 2024

This lab worked perfectly, the problem dealt with is the Towers of Hanoi problem. This was solved using a recursive algorithm that was created in the 
“towers.c” it operates by having a towers recursive function which takes in parameters(arguments). Where the first argument is the number of disks to 
be moved(n), the second argument is the tower to be moved from(from) and the last one the tower to be moved(dest). The goal of this lab was to make 
another c file, towersMain that would take in the user defined arguments and use the entered information to either solve the towers or produce an error.



I tried my best to make the program error proof by having multiple if/else statements and a case of nested if statements and a double 
nested if statement. This would take care of any inputs the algorithm can’t deal with. This included when the fromID destID are the same,
 when either is above 3 (there are only 3 towers) or lower than 1 (there is no tower 0) or when there’s more than 3 arguments. 
There was also another error message posted for when there was a fromID but no destID. All errors have their own unique error messages 
for their respective error types.



The program can do 1 of 3 things:

 - Solve the problem normally in 7 steps (towers)

 - Solve the problem for a chosen number of disks defaulting from tower 1 to 2 (towers n)

 -  Solve the problem for a chosen number of disks and from a chosen tower to a chosen tower (towers n fromID destID)



Questions
Question 1's Output1 and Question 2's Output2

1.1.) - Towers (5, 2, 3) will have an initial recursive call of 
towers (4, 2, 1) this is indicated by the two dots.

1.2.) - There will have 5 recursive calls before arriving at the initial invocation.

1.3.) - "Move #1: From Tower 2 to Tower 3” is the first printed statement.

1.4.) - The second recursive call invoked will be towers(0, 3, 2)


2.) - The program output is 255 lines. As show in the file Output2 