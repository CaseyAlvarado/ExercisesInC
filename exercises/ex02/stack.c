/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];
    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    // printf("array in main is at %p\n", array);
    bar();

    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }

    return 0;
}

//Question: Read stack.c, which should be in this directory. 
//What is it intended to do? 
//What would the output be if the program worked as expected?
//Answer: I thought that this program was meant to story an array in the pointer variable 
//called array. This array was initially created by foo(), modified by bar(), and then 
//printed in the main() function. The output would be 1, 2, 3, 4

//Question: Compile it. Do you get a warning? What does it mean?
//Answer: I get the following warning after compiling: 
// stack.c: In function ‘foo’:
// stack.c:23:5: warning: function returns address of local variable [-Wreturn-local-addr]
//      return array;
//      ^
//I think the line in main(): int *array = foo() was expecting that the array 
//variable would be a pointer to an array that foo() would return. 
//However, foo() did not return an array. Instead it seemed to return an address. 
//Perhaps this is what the astrisk in front of int *foo() did to the output. 

//Question: Run it. What happens? You might get a segmentation fault, 
//or you might get some strange output. Can you explain it? 
//You might find it helpful to draw a stack diagram.
// 0x7ffd17d67090
// 0x7ffd17d67090
// 0
// 1
// 2
// 3
// 4
//I see the address of array in foo() and in bar(), and good thing they are the same. 
//Then I do see the 0,1, 2, 3, 4 that I expected. No segmentation fault. I drew a stack 
//diagram and I found it odd that foo() needed to return an array to store in the array 
//address. However, the foo function declaration says it will return a pointer. 
//Even though it tries to return the modified array. 
//Also is it even necessary to attempt to return the modified array because the 
//pointer will modify it in memory. Isn't that the whole point of pointers (haha)? 

//Question: Comment out the print statements in foo() and bar() and run it again. 
//What happens now?
//Answer: I get the following result 
// 0
// 0
// 547540608
// 32676
// 547628384
//What is this? Perhaps this is pulling other information stored in memory? 