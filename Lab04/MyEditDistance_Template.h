#ifndef _MY_EDIT_DISTANCE_H_
#define _MY_EDIT_DISTANCE_H_

#include <iostream>
#include <string>


/*------------------------------------------------------------------------------
    EditDistance: find the minimum number of edits that converts one string to another
    
        str1: the first input string, has an alphabet of [A, C, G, T]
        str2: the second input string, has an alphabet of [A, C, G, T]
        operations: the list of edit operations as string: 
            [M] for match, [C] for convert, [I] for insert, [D] for delete
        
        returns the number of edit distance
------------------------------------------------------------------------------*/
unsigned int EditDistance
(
    const std::string & str1,
    const std::string & str2
    std::string & operations
)
{
  /*------ CODE BEGINS ------*/


  /*------ CODE ENDS ------*/
}



/*------------------------------------------------------------------------------
    PrintAlgnment: prints the two aligned sequences and the corresponding operations
        in the alignment form to stdout
    
        str1: the first input string, has an alphabet of [A, C, G, T]
        str2: the second input string, has an alphabet of [A, C, G, T]
        operations: the list of edit operations as string: 
            [M] for match, [C] for convert, [I] for insert, [D] for delete

    The alignment output should contain three rows:
        The first row corresponds to the first sequence with gaps
        The second row corresponds to the list of operations
        The third row corresponds to the second sequence with gaps
        A match [M] operation should be represented using '|'
        A convert [C] operation should be represented using '*'
        Insert and delete operations should be represented using ' ' (empty space)

    Example:
        str1: "ACAACC"
        str2: "CAAAAC"
        operations: "DMMMICM"

        output alignment:
        ACAA-CC
         ||| *|
        -CAAAAC
------------------------------------------------------------------------------*/
void PrintAlignment
(
    const std::string & str1,
    const std::string & str2,
    const std::string & operations
)
{

}



#endif
