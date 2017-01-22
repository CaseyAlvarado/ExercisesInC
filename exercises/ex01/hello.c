#include <stdio.h>
int main()
{
    int x = 5; 
    // printf("%i", x);
    // printf("Hello world");  

    //when I compile with the -o2 optimization, 
    //it seems to turn on a bunch of other flags
    //that checks for optimization? 

    int y = x + 1;
    printf("%i", y);

    //with the -o2 flag, it seems to be reallocating 
    //information within my computer space? 
    //perhaps its a trade off and memory balance? 
}