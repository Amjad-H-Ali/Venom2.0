#include <iostream>
#include <chrono>

#define SIZE 2000 
#define PREV_STATE 0
#define NEXT_STATE 1
#define IS_UNDERSCORE         ((inputFlags & 0x1)         != 0)
#define IS_ALPHABET           ((inputFlags & 0x2)         != 0) 
#define IS_NUMERAL            ((inputFlags & 0x4)         != 0)
#define IS_ASTERISK           ((inputFlags & 0x8)         != 0) 
#define IS_FSLASH             ((inputFlags & 0x10)        != 0)
#define IS_PLUS               ((inputFlags & 0x20)        != 0) 
#define IS_HYPHEN             ((inputFlags & 0x40)        != 0)
#define IS_PERCENT            ((inputFlags & 0x80)        != 0) 
#define IS_EQUAL              ((inputFlags & 0x100)       != 0)
#define IS_BAR                ((inputFlags & 0x200)       != 0) 
#define IS_AMPERSAND          ((inputFlags & 0x400)       != 0)
#define IS_CARET              ((inputFlags & 0x800)       != 0) 
#define IS_GT                 ((inputFlags & 0x1000)      != 0)
#define IS_LT                 ((inputFlags & 0x8000)      != 0) 
#define IS_PERIOD             ((inputFlags & 0x20000)     != 0)
#define IS_EXCLAMATION        ((inputFlags & 0x80000)     != 0) 
#define IS_APOSTROPHE         ((inputFlags & 0x100000)    != 0)
#define IS_QUOTATION          ((inputFlags & 0x400000)    != 0) 
#define IS_WHITESPACE         ((inputFlags & 0x800000)    != 0)
#define IS_COLON              ((inputFlags & 0x1000000)   != 0) 
#define IS_LPARANTHESIS       ((inputFlags & 0x2000000)   != 0)
#define IS_RPARANTHESIS       ((inputFlags & 0x4000000)   != 0) 
#define IS_LBRACE             ((inputFlags & 0x8000000)   != 0)
#define IS_RBRACE             ((inputFlags & 0x10000000)  != 0) 
#define IS_LBRACKET           ((inputFlags & 0x20000000)  != 0)
#define IS_RBRACKET           ((inputFlags & 0x40000000)  != 0)
#define IS_TILDE              ((inputFlags & 0x80000000)  != 0) 


                                                                                                    
#define IS_TILDE_OR_BRACK_OR_BRACE_OR_PARAN_OR_COLON_OR_WS ((inputFlags & 0xFF800000) != 0)
                      
#define IS_NOT_P23_OR_P22_OR_P21_OR_P20 ((tokens[PREV_STATE] & 0xF00000) == 0 )

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P18_OR_P17_OR_P2_OR_P1_OR_P0 ((tokens[PREV_STATE] & 0xF60007) == 0 )

#define IS_P21_OR_P20 ( (tokens[PREV_STATE] & 0x300000) != 0 )

#define P3ASTERISK_OR_P5PLUS_OR_P6HYPHEN_OR_P8GT_OR_P9BAR_OR_P10AMPERSAND ( ((inputFlags & 0x1668) & tokens[PREV_STATE]) != 0 )

#define GET_PREV_STATE(P) ( (tokens[PREV_STATE] & (0x1 << P)) != 0 ) 

#define SET_NEXT_STATE(N, CONDITION) (tokens[NEXT_STATE] |= (static_cast<uint64_t>(CONDITION) << N) )

#define P18PERIOD_OR_P21APOSTROPHE ((((inputFlags << 1) & 0x240000) & tokens[PREV_STATE]) != 0)

#define P20APOSTROPHE_OR_P22QUOTATION (((inputFlags & 0x500000) & tokens[PREV_STATE]) != 0) 

#define IS_UNDERSCORE_OR_ALPHABET ((inputFlags & 0x3) != 0)

#define IS_P1NUMERAL (((inputFlags & 0x4) & (tokens[PREV_STATE] << 1)) != 0) 

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P1 ((tokens[PREV_STATE] & 0xF00002) == 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P3 ((tokens[PREV_STATE] & 0xF00008) == 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P5 ((tokens[PREV_STATE] & 0xF00020) == 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P6 ((tokens[PREV_STATE] & 0xF00040) == 0)

#define IS_P0_OR_P1_OR_P2_OR_P17_OR_P18 ((tokens[PREV_STATE] & 0x60003) != 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P9 ((tokens[PREV_STATE] & 0xF00200) == 0)

int main() {
    
    
    uint64_t tokens[SIZE] = {0x0}; // 16,000 BYTES : 250/512 CACHE-LINES
    tokens[PREV_STATE] = 0x100;
    uint64_t inputFlags = 0x0;  
    uint32_t i = 2;
    while(tokens[i] += getchar()) {
        
        // Set the corresponding bit of current input to 1.
        inputFlags = 
            
            (tokens[i] == '_') << 0                                                                       |
            (((tokens[i] >= 'a') & (tokens[i] <= 'z')) | ((tokens[i] >= 'A') & (tokens[i] <= 'Z'))) << 1  |
            ((tokens[i] >= '0')  & (tokens[i] <= '9')) << 2                                               |
            (tokens[i] == '*') << 3                                                                       | 
            (tokens[i] == '/') << 4                                                                       | 
            (tokens[i] == '+') << 5                                                                       | 
            (tokens[i] == '-') << 6                                                                       | 
            (tokens[i] == '%') << 7                                                                       |
            (tokens[i] == '=') << 8                                                                       | 
            (tokens[i] == '|') << 9                                                                       | 
            (tokens[i] == '&') << 10                                                                      | 
            (tokens[i] == '^') << 11                                                                      | 
            (tokens[i] == '>') << 12                                                                      |
            (tokens[i] == '<') << 15                                                                      | 
            (tokens[i] == '.') << 17                                                                      | 
            (tokens[i] == '!') << 19                                                                      | 
            (tokens[i] == '\'') << 20                                                                     | 
            (tokens[i] == '"') << 22                                                                      |
            ((tokens[i] == 0x9) | (tokens[i] == 0xA) | (tokens[i] == 0x20)) << 23                         | 
            (tokens[i] == ':') << 24                                                                      | 
            (tokens[i] == '(') << 25                                                                      |
            (tokens[i] == ')') << 26                                                                      | 
            (tokens[i] == '{') << 27                                                                      | 
            (tokens[i] == '}') << 28                                                                      | 
            (tokens[i] == '[') << 29                                                                      | 
            (tokens[i] == ']') << 30                                                                      |
            (tokens[i] == '~') << 31                                                                      ; 
                                                        
 
        
             
        
       
        SET_NEXT_STATE(0, 
       
            (IS_TILDE_OR_BRACK_OR_BRACE_OR_PARAN_OR_COLON_OR_WS & IS_NOT_P23_OR_P22_OR_P21_OR_P20)               |
            (IS_EQUAL & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P18_OR_P17_OR_P2_OR_P1_OR_P0)                         |
             P3ASTERISK_OR_P5PLUS_OR_P6HYPHEN_OR_P8GT_OR_P9BAR_OR_P10AMPERSAND                                   |
             P18PERIOD_OR_P21APOSTROPHE                                                                          |
             P20APOSTROPHE_OR_P22QUOTATION       
           /*            
                                                                                                   |
            (GET_PREV_STATE(18) & IS_PERIOD)  | (IS_APOSTROPHE & IS_P21_OR_P20 )                   |
            (GET_PREV_STATE(22) & IS_QUOTATION)
           */
        );
        

        
        SET_NEXT_STATE(1,                 
            (IS_UNDERSCORE_OR_ALPHABET & IS_NOT_P23_OR_P22_OR_P21_OR_P20)                                        |
             IS_P1NUMERAL   

        );
        
        
        SET_NEXT_STATE(2,
            IS_NUMERAL & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P1
        );
        
        
            
        SET_NEXT_STATE(3,
        
            IS_ASTERISK & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P3
        );
        
            
        SET_NEXT_STATE(4,
                       
            IS_FSLASH & IS_NOT_P23_OR_P22_OR_P21_OR_P20            
        );
        

        
        SET_NEXT_STATE(5,
            IS_PLUS & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P5          
        );
        
        
            
        SET_NEXT_STATE(6,
            IS_HYPHEN & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P6
        );
        
   
            
        SET_NEXT_STATE(7,
            IS_PERCENT & IS_NOT_P23_OR_P22_OR_P21_OR_P20
        );
        
            
        SET_NEXT_STATE(8,
             IS_EQUAL & IS_P0_OR_P1_OR_P2_OR_P17_OR_P18                      
        );
        
        
            
        SET_NEXT_STATE(9,
            IS_BAR & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P9
        );
        
        
        std::cout << tokens[NEXT_STATE] <<std::endl;
        
        tokens[NEXT_STATE] = 0x0;
        tokens[i] = 0;
        
        
            
        
    }
}


//     const uint32_t SIZE = 21;
//     uint32_t i = 0;
//     uint32_t j = 0;
//     const char stream[SIZE]= 
//         {
//             'f', 'o', 'o', 0x20, 'i', 's', 0x20, 'i', 
//             's', 0x20, 'l', ')', '=', '>', '{', 0x20, '}', 'i', 's', 0x20, '\n'
//         };

//     uint64_t tokens[SIZE] = {0};

    
//     std::chrono::time_point<std::chrono::system_clock> start2, end2;

//     start2 = std::chrono::system_clock::now();
    
//     /*
//      * 
//      *  IS: 1  
//      * 
//      */
//     uint64_t flags = 0x0000000000000000;
//    // Read stream from stdin into tokens[]
//    // Tokenize chars inplace
//     while(tokens[offset_w] += getchar()) { 
        
//         flags = 
  
//             (tokens[offset_r] == 0x00000000006973)*0000000100000000 // IS flag
                
//             (tokens[offset_r] == 0x00000000000028)*0000000000000001 // LPARAN flag
            
//             (tokens[offset_r] == 0x00000000000029)*0000000000000002 // RPARAN flag
            
//             (tokens[offset_r] == 0x0000000000007B)*0000000000000004 // LBRACE flag
            
//             (tokens[offset_r] == 0x0000000000007D)*0000000000000008 // RBRACE flag
            
//             (tokens[offset_r] == 0x00000000000020)*0000000000000010 // SPACE flag
            
            
            
            
//         /*
//          * 
//          * IS Token     : 1
//          * 
//          * LPARAN Token : 2
//          * 
//          * RPARAN Token : 3
//          * 
//          * LBRACE Token : 4
//          * 
//          * RBRACE Token : 5
//          * 
//          */    
//         //
//         tokens[offset_r] = 
            
//             // A Single Token (ie. curly brace, paranthesis, space,  etc.) ends.
//             // Check which flag is on and write corresponding Token to tokens[]. 
//             // If no flag is on (only SINGLE_TOKS flag is on), then write 
//             // corresponding single char Token to tokens[]
//             SINGLE_TOKS*
//             (
//                 IS_FLG*1 + NOT_VAR_STR_KEYWORD*
            
//                 (LPARAN_FLG*2 + RPARAN_FLG*3 + LBRACE_FLG*4 + RBRACE_FLG*5)
            
//              ) + !SINGLE_TOKS*tokens[offset_r];
            
            
         
            
       
    
//         offset_w += (tokens[offset_w] > 0x00FFFFFFFFFFFFFF);

//         tokens[offset_w] <<= 8;

//         std::cout << std::hex << tokens[j] << std::endl;

        
//         std::cout << std::hex << j << std::endl;
//         std::cout << std::hex << stream[i] << std::endl;
        
        
//         ++i;
//     }
//     std::cout << "I: " <<i << std::endl;
//     tokens[j] <<= ((9-((i+1)%9))*7);

//     uint64_t flags = 0;
//     // Possibly combine the two. Only need 4 bits for each.
//     uint8_t SHFT = 0; // Offset for reading TOKEN
//     uint8_t SHFT_W = 0; // Offset for writing TOKEN
//     // Possibly combine the two
//     i = 0; // For Reading TOKEN
//     j = 0; // For Writing TOKEN
//     while(i < (SIZE/9) ) {

//         // Don't Set any Flag if VAR or STR is on.
//         flags |= 
//             (   
//                 !VAR_B &  // To avoid reading part of a VAR as a Keyword 
//                 (
//                     (tokens[i] & (0xFFFFF80000000000 >> (SHFT+1) )) == (0x69E6800000000000 >> SHFT )
//                 ) &

//                 (
//                     ( (tokens[i+1] & ( 0xFFFC000000000000 << (56-SHFT)) ) << 1 ) == (0xE680000000000000 << (56-SHFT))
//                 )
//             ) & 0x0000000000000001;

//         // If above did not set any of the Keyword Flags, and current char is an Alphabet, then Set VAR_B to on.
//         flags |= 
//             (
//                 ((flags & 0xFFFFFFFFFFFFFFFF) == 0) &
                
//                 (
//                     (
//                         (((tokens[i] & (0xFE00000000000000 >> (SHFT+1) )) >> (56-SHFT)) >= 'A') & 

//                         (((tokens[i] & (0xFE00000000000000 >> (SHFT+1) )) >> (56-SHFT)) <= 'Z')

//                     ) |
//                     (
//                         (((tokens[i] & (0xFE00000000000000 >> (SHFT+1) )) >> (56-SHFT)) >= 'a') & 

//                         (((tokens[i] & (0xFE00000000000000 >> (SHFT+1) )) >> (56-SHFT)) <= 'z')

//                     )

//                 )
//             )*0x0000000100000000;

//         std::cout << "--------------------" << std::endl;
//         std::cout << "--------------------" << std::endl;
//         std::cout << "LETTER: " << (char) ((tokens[i] & (0xFE00000000000000 >> (SHFT+1) )) >> (56-SHFT))<< std::endl;

//         std::cout << "BOOL: " << ( (tokens[i+1] << (57-SHFT)) & ( 0xFFFC000000000000 << (56-SHFT)) )<< std::endl;
        

//         std::cout << "IS: " <<  IS_B << std::endl;
//         std::cout << "i: " <<  i << std::endl;
//         std::cout << "SHFT: " <<  (int)SHFT << std::endl;
        
        

//         tokens[j] = 
//             (   
//                  IS_B * ((tokens[j] & ~(0xFF00000000000000 >> SHFT_W)) | (0x0100000000000000 >> SHFT_W)) +

//                 !IS_B * tokens[j]
//             );


//         SHFT += 
//             7*!IS_B + 21*IS_B;

//         if(21*IS_B) std::cout << "INCREMENTED BY 21" << std::endl;

//         i += (SHFT >= 63);

//         // When part of a TOKEN takes up more than one space in the array of Longs, 
//         // SHFT should  be set to the end of that TOKEN.
//         SHFT = (SHFT >= 63)*(SHFT - 63) + (SHFT < 63)*SHFT;

//         // Increment by 1 Byte after a Write occured since each TOKEN is one Byte.
//         // Don't forget that it should not WRite over a string.
//         SHFT_W += 8;
//         j += (SHFT_W >= 64); // Increment j if current array space is full w/ TOKENS
//         SHFT_W = (SHFT_W % 64);  // Reset to 0 if SHFT_W is at end

//         flags &= 0xFFFFFFFF00000000;    

//     }

//     for(uint32_t k = 0; k < (SIZE/9); ++k) {
//         std::cout << std::hex << tokens[k] << std::endl;

//         for(uint32_t x = 0; x < 9; ++x) {

//             std::cout << (tokens[k] & (0xFE00000000000000 >> ((x*7)+1) )) << std::endl;
//         }
//     }    

//     std::cout << (tokens[0] &(0xFF00000000000000 >> 28) ) << std::endl;

//     std::cout << (0x69E6800000000000 >> 28) << std::endl;
    

    
    

//     end2 = std::chrono::system_clock::now();
//     std::chrono::duration<double> elapsed_seconds2 = end2 - start2; 
//     std::time_t end_time2 = std::chrono::system_clock::to_time_t(end2);

//     std::cout << "finished computation at " << std::ctime(&end_time2) 
//                << "elapsed time: " << elapsed_seconds2.count() << "s\n"; 
// }
