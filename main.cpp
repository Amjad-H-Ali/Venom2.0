#include <iostream>
#include <chrono>
#include "Lexer/Lexer.h"




int main() {

   // (1)   Index is the PREV_STATE.   (CONSTANT Index: Permanently 1 -- For Now --)
   // (2)   Index is the NEXT_STATE.   (CONSTANT)
   // (3)   Index is w_token space.    (VARIABLE Index: Changes when current space reaches capacity.)
   // (5)   Index is NUM_BUFFER.       (VARIABLE)
   // (7)   Index is input space.      (VARIABLE)
   // (8)   Index is ALPHANUM_BUFFER   (VARIABLE)
    uint64_t tokens[SIZE] = {0x0}; // 16,000 BYTES : 250/512 CACHE-LINES
    
    lexer(tokens);

    return 0;
 
}




