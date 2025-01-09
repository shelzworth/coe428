Sheldon Cerejo
Lab 5 coe 428
March 24th 2024

Req. 1

Works fine as of the submission will validate XML style input examples correctly as shown in the lab manual.

Req. 2

Works fine as of submission, will take in a random series of numbers sort it into a stack and display the heap in XML form.
The popped stack will be the same as the initial entry. to execute the code the user must type in 1.

Question

To implement this into the program, since the initial case requires the '/' to be before the string/word the word will also
need a start tag and in that case the program must determine if the string is the same for both tags. Otherwise if the '/'
is after the string then the tag will be considered a "stand-alone" and be valid by default. We can implement this using a temporary
array and checking if array.length - 2 is '/'.