#include <iostream>
#include <chrono>

#define SIZE 2000 
#define PREV_STATE 0
#define NEXT_STATE 1
#define W_POS (i-1)

// Inputs
#define IS_UNDERSCORE         ((tokens[i] & 0x1)         != 0)
#define IS_ALPHABET           ((tokens[i] & 0x2)         != 0) 
#define IS_NUMERAL            ((tokens[i] & 0x4)         != 0)
#define IS_ASTERISK           ((tokens[i] & 0x8)         != 0) 
#define IS_FSLASH             ((tokens[i] & 0x10)        != 0)
#define IS_PLUS               ((tokens[i] & 0x20)        != 0) 
#define IS_HYPHEN             ((tokens[i] & 0x40)        != 0)
#define IS_PERCENT            ((tokens[i] & 0x80)        != 0) 
#define IS_EQUAL              ((tokens[i] & 0x100)       != 0)
#define IS_BAR                ((tokens[i] & 0x200)       != 0) 
#define IS_AMPERSAND          ((tokens[i] & 0x400)       != 0)
#define IS_CARET              ((tokens[i] & 0x800)       != 0) 
#define IS_GT                 ((tokens[i] & 0x1000)      != 0)
#define IS_LT                 ((tokens[i] & 0x8000)      != 0) 
#define IS_PERIOD             ((tokens[i] & 0x20000)     != 0)
#define IS_EXCLAMATION        ((tokens[i] & 0x80000)     != 0) 
#define IS_APOSTROPHE         ((tokens[i] & 0x100000)    != 0)
#define IS_QUOTATION          ((tokens[i] & 0x400000)    != 0) 
#define IS_WHITESPACE         ((tokens[i] & 0x800000)    != 0)
#define IS_COLON              ((tokens[i] & 0x1000000)   != 0) 
#define IS_LPARANTHESIS       ((tokens[i] & 0x2000000)   != 0)
#define IS_RPARANTHESIS       ((tokens[i] & 0x4000000)   != 0) 
#define IS_LBRACE             ((tokens[i] & 0x8000000)   != 0)
#define IS_RBRACE             ((tokens[i] & 0x10000000)  != 0) 
#define IS_LBRACKET           ((tokens[i] & 0x20000000)  != 0)
#define IS_RBRACKET           ((tokens[i] & 0x40000000)  != 0)
#define IS_TILDE              ((tokens[i] & 0x80000000)  != 0) 

/* TOKENS */
#define CHR(CONDITION)        (static_cast<uint64_t>(0x1 & CONDITION))

#define STR(CONDITION)        (static_cast<uint64_t>(0x2 * CONDITION))

#define MUL(CONDITION)        (static_cast<uint64_t>(0x3 * CONDITION))

#define DIV(CONDITION)        (static_cast<uint64_t>(0x4 * CONDITION))

#define PLUS(CONDITION)       (static_cast<uint64_t>(0x5 * CONDITION))

#define MIN(CONDITION)        (static_cast<uint64_t>(0x6 * CONDITION))

#define MOD(CONDITION)        (static_cast<uint64_t>(0x7 * CONDITION))

#define ASSGN(CONDITION)      (static_cast<uint64_t>(0x8 * CONDITION))

#define BOR(CONDITION)        (static_cast<uint64_t>(0x9 * CONDITION))

#define BAND(CONDITION)       (static_cast<uint64_t>(0xA * CONDITION))

#define BXOR(CONDITION)       (static_cast<uint64_t>(0xB * CONDITION))

#define GT(CONDITION)         (static_cast<uint64_t>(0xC * CONDITION))

#define SAR(CONDITION)        (static_cast<uint64_t>(0xD * CONDITION))

#define SHR(CONDITION)        (static_cast<uint64_t>(0xE * CONDITION))

#define LT(CONDITION)         (static_cast<uint64_t>(0xF * CONDITION))

#define SHL(CONDITION)        (static_cast<uint64_t>(0x10 * CONDITION))

#define DOT(CONDITION)        (static_cast<uint64_t>(0x11 * CONDITION))

#define DDOT(CONDITION)       (static_cast<uint64_t>(0x12 * CONDITION))

#define ELLIP(CONDITION)      (static_cast<uint64_t>(0x13 * CONDITION))

#define NOT(CONDITION)        (static_cast<uint64_t>(0x14 * CONDITION))

#define W_CHR(CONDITION)      (static_cast<uint64_t>(0x15 * CONDITION))

#define W_STR(CONDITION)      (static_cast<uint64_t>(0x16 * CONDITION))

#define MULEQ(CONDITION)      (static_cast<uint64_t>(0x17 * CONDITION))

#define EXP(CONDITION)        (static_cast<uint64_t>(0x18 * CONDITION))

#define COLON(CONDITION)      (static_cast<uint64_t>(0x19 * CONDITION))

#define LPARAN(CONDITION)     (static_cast<uint64_t>(0x1A * CONDITION))

#define RPARAN(CONDITION)     (static_cast<uint64_t>(0x1B * CONDITION))

#define LBRACK(CONDITION)     (static_cast<uint64_t>(0x1C * CONDITION))

#define RBRACK(CONDITION)     (static_cast<uint64_t>(0x1D * CONDITION))

#define LBRACE(CONDITION)     (static_cast<uint64_t>(0x1E * CONDITION))

#define RBRACE(CONDITION)     (static_cast<uint64_t>(0x1F * CONDITION))

#define BNOT(CONDITION)       (static_cast<uint64_t>(0x20 * CONDITION))

#define DIVEQ(CONDITION)      (static_cast<uint64_t>(0x21 * CONDITION))

#define PE(CONDITION)         (static_cast<uint64_t>(0x22 * CONDITION))

#define INC(CONDITION)        (static_cast<uint64_t>(0x23 * CONDITION))

#define MINE(CONDITION)       (static_cast<uint64_t>(0x24 * CONDITION))

#define DEC(CONDITION)        (static_cast<uint64_t>(0x25 * CONDITION))

#define MODEQ(CONDITION)      (static_cast<uint64_t>(0x26 * CONDITION))

#define EQ(CONDITION)         (static_cast<uint64_t>(0x27 * CONDITION))

#define FARROW(CONDITION)     (static_cast<uint64_t>(0x28 * CONDITION))

#define BOREQ(CONDITION)      (static_cast<uint64_t>(0x29 * CONDITION))

#define LOR(CONDITION)        (static_cast<uint64_t>(0x2A * CONDITION))

#define BANDEQ(CONDITION)     (static_cast<uint64_t>(0x2B * CONDITION))

#define LAND(CONDITION)       (static_cast<uint64_t>(0x2C * CONDITION))

#define BXOREQ(CONDITION)     (static_cast<uint64_t>(0x2D * CONDITION))

#define GTE(CONDITION)        (static_cast<uint64_t>(0x2E * CONDITION))

#define SAREQ(CONDITION)      (static_cast<uint64_t>(0x2F * CONDITION))

#define SHREQ(CONDITION)      (static_cast<uint64_t>(0x30 * CONDITION))

#define LTE(CONDITION)        (static_cast<uint64_t>(0x31 * CONDITION))

#define SHLEQ(CONDITION)      (static_cast<uint64_t>(0x32 * CONDITION))

#define NOTEQ(CONDITION)      (static_cast<uint64_t>(0x33 * CONDITION))

#define R_CHR(CONDITION)      (static_cast<uint64_t>(0x34 * CONDITION))

#define R_STR(CONDITION)      (static_cast<uint64_t>(0x35 * CONDITION))

#define W_NUM(CONDITION)      (static_cast<uint64_t>(0x36 * CONDITION))

#define W_ALPHANUM(CONDITION) (static_cast<uint64_t>(0x37 * CONDITION))

#define NUM(CONDITION)        (static_cast<uint64_t>(0x38 * CONDITION))

#define R_ALPHANUM(CONDITION) (static_cast<uint64_t>(0x39 * CONDITION))

#define ERROR(CONDITION)      (static_cast<uint64_t>(0x3A * CONDITION))

/* END OF TOKEN DEFINITIONS */

                                                                                                    
#define IS_TILDE_OR_BRACK_OR_BRACE_OR_PARAN_OR_COLON_OR_WS ((tokens[i] & 0xFF800000) != 0)
                      
#define IS_NOT_P23_OR_P22_OR_P21_OR_P20 ((tokens[PREV_STATE] & 0xF00000) == 0 )

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P18_OR_P17_OR_P2_OR_P1_OR_P0 ((tokens[PREV_STATE] & 0xF60007) == 0 )

#define IS_P21_OR_P20 ( (tokens[PREV_STATE] & 0x300000) != 0 )

#define P3ASTERISK_OR_P5PLUS_OR_P6HYPHEN_OR_P8GT_OR_P9BAR_OR_P10AMPERSAND ( ((tokens[i] & 0x1668) & tokens[PREV_STATE]) != 0 )

#define GET_PREV_STATE(P) ((tokens[PREV_STATE] & (0x1 << P)) != 0) 

#define GET_NEXT_STATE(N) ((tokens[NEXT_STATE] & (0x1 << N)) != 0)

#define SET_NEXT_STATE(N, CONDITION) (static_cast<uint64_t>(CONDITION) << N) 

#define P18PERIOD_OR_P21APOSTROPHE ((((tokens[i] << 1) & 0x240000) & tokens[PREV_STATE]) != 0)

#define P20APOSTROPHE_OR_P22QUOTATION (((tokens[i] & 0x500000) & tokens[PREV_STATE]) != 0) 

#define IS_UNDERSCORE_OR_ALPHABET ((tokens[i] & 0x3) != 0)

#define IS_P1NUMERAL (((tokens[i] & 0x4) & (tokens[PREV_STATE] << 1)) != 0) 

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P1 ((tokens[PREV_STATE] & 0xF00002) == 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P3 ((tokens[PREV_STATE] & 0xF00008) == 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P5 ((tokens[PREV_STATE] & 0xF00020) == 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P6 ((tokens[PREV_STATE] & 0xF00040) == 0)

#define IS_P0_OR_P1_OR_P2_OR_P17_OR_P18 ((tokens[PREV_STATE] & 0x60003) != 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P9 ((tokens[PREV_STATE] & 0xF00200) == 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P10 ((tokens[PREV_STATE] & 0xF00400) == 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P13_OR_P12_OR_P8 ((tokens[PREV_STATE] & 0xF03100) == 0)

#define IS_P12GT (((tokens[i] & 0x1000) & tokens[PREV_STATE]) != 0)

#define IS_P13GT ((((tokens[i] & 0x1000) << 1) & tokens[PREV_STATE]) != 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P15 ((tokens[PREV_STATE] & 0xF08000) == 0)

#define IS_P15LT (((tokens[i] & 0x8000) & tokens[PREV_STATE]) != 0)

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P18_OR_P17 ((tokens[PREV_STATE] & 0xF60000) == 0)

#define IS_P17PERIOD (((tokens[i] & 0x20000) & tokens[PREV_STATE]) != 0)

#define IS_P20NOTAPOSTROPHE ((((tokens[i] & 0x100000) == 0) & ((tokens[PREV_STATE] & 0x100000) != 0) ) !=0)

#define IS_P22NOTQUOTATION ((((tokens[i] & 0x400000) == 0) & ((tokens[PREV_STATE] & 0x400000) != 0) ) != 0) 

#define IS_P21NOTAPOSTROPHE ((((tokens[i] & 0x100000) == 0) & ((tokens[PREV_STATE] & 0x200000) != 0)) != 0)

#define IS_P23 ((tokens[PREV_STATE] & 0x800000) != 0)

#define IS_P3 ((tokens[PREV_STATE] & 0x8) != 0)

#define IS_P4 ((tokens[PREV_STATE] & 0x10) != 0)

#define IS_NOT_ASTERISK_OR_EQUAL ((tokens[PREV_STATE] & 0x108) == 0) 

#define IS_NOT_EQUAL ((tokens[i] & 0x100) == 0)

#define IS_P5 ((tokens[PREV_STATE] & 0x20) != 0)

#define IS_NOT_PLUS_OR_EQUAL ((tokens[i] & 0x120) == 0)

#define IS_P6 ((tokens[PREV_STATE] & 0x40) != 0)

#define IS_NOT_MIN_OR_EQUAL ((tokens[i] & 0x140) == 0)

#define IS_P7 ((tokens[PREV_STATE] & 0x80) != 0)

#define IS_P8 ((tokens[PREV_STATE] & 0x100) != 0)

#define IS_NOT_GT_OR_EQUAL ((tokens[i] & 0x1100) == 0)

#define IS_P9 ((tokens[PREV_STATE] & 0x200) != 0)

#define IS_NOT_BAR_OR_EQUAL ((tokens[i] & 0x300) == 0)

#define IS_P10 ((tokens[PREV_STATE] & 0x400) != 0)

#define IS_NOT_AMPERSAND_OR_EQUAL ((tokens[i] & 0x500) == 0)

#define IS_P11 ((tokens[PREV_STATE] & 0x800) != 0)

#define IS_P12 ((tokens[PREV_STATE] & 0x1000) != 0)

#define IS_P13 ((tokens[PREV_STATE] & 0x2000) != 0)

#define IS_P14 ((tokens[PREV_STATE] & 0x4000) != 0)

#define IS_P15 ((tokens[PREV_STATE] & 0x8000) != 0)

#define IS_NOT_LT_OR_EQUAL (tokens[i] & 0x8100)

#define IS_P16 ((tokens[PREV_STATE] & 0x10000) != 0)

#define IS_P17 ((tokens[PREV_STATE] & 0x20000) != 0)

#define IS_P18 ((tokens[PREV_STATE] & 0x40000) != 0)

#define IS_P19 ((tokens[PREV_STATE] & 0x80000) != 0)

#define IS_NOT_PERIOD ((tokens[i] & 0x20000) == 0)

#define IS_P18PERIOD ((((tokens[i] & 0x20000) << 1) & tokens[PREV_STATE]) != 0)

int main() {
   
    
    
    uint64_t tokens[SIZE] = {0x0}; // 16,000 BYTES : 250/512 CACHE-LINES
    tokens[PREV_STATE] = 0x100;
    uint32_t i = 3;
    uint8_t w_shft_factor = 0;
    while(tokens[i] += getchar()) {
        
        // Set the corresponding bit of current input to 1.
        tokens[i] = 
            
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
                                                        
 
        
             
        
    tokens[NEXT_STATE] |= 
              
            SET_NEXT_STATE(0, 

                (IS_TILDE_OR_BRACK_OR_BRACE_OR_PARAN_OR_COLON_OR_WS & IS_NOT_P23_OR_P22_OR_P21_OR_P20) |
                (IS_EQUAL & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P18_OR_P17_OR_P2_OR_P1_OR_P0)           |
                 P3ASTERISK_OR_P5PLUS_OR_P6HYPHEN_OR_P8GT_OR_P9BAR_OR_P10AMPERSAND                     |
                 P18PERIOD_OR_P21APOSTROPHE                                                            |
                 P20APOSTROPHE_OR_P22QUOTATION       
            )  
                                                                                                                        |
            SET_NEXT_STATE(1,                 
                (IS_UNDERSCORE_OR_ALPHABET & IS_NOT_P23_OR_P22_OR_P21_OR_P20)|
                 IS_P1NUMERAL   

            )                                                                                                    
                                                                                                                        |
            SET_NEXT_STATE(2,
                IS_NUMERAL & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P1
            )
                                                                                                                        |
            SET_NEXT_STATE(3,

                IS_ASTERISK & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P3
            )
                                                                                                                        |
            SET_NEXT_STATE(4,

                IS_FSLASH & IS_NOT_P23_OR_P22_OR_P21_OR_P20            
            )
                                                                                                                        |
            SET_NEXT_STATE(5,
                IS_PLUS & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P5          
            )
                                                                                                                        |
            SET_NEXT_STATE(6,
                IS_HYPHEN & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P6
            )
                                                                                                                        |
            SET_NEXT_STATE(7,
                IS_PERCENT & IS_NOT_P23_OR_P22_OR_P21_OR_P20
            )
                                                                                                                        |
            SET_NEXT_STATE(8,
                IS_EQUAL & IS_P0_OR_P1_OR_P2_OR_P17_OR_P18                      
            )
                                                                                                                        |
            SET_NEXT_STATE(9,
                IS_BAR & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P9
            )
                                                                                                                        |
            SET_NEXT_STATE(10,
                IS_AMPERSAND & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P10
            )
                                                                                                                        |
            SET_NEXT_STATE(11,
                IS_CARET & IS_NOT_P23_OR_P22_OR_P21_OR_P20                     
            )
                                                                                                                        |
            SET_NEXT_STATE(12,
                IS_GT & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P13_OR_P12_OR_P8                  
            )
                                                                                                                        |
            SET_NEXT_STATE(13,
                IS_P12GT                  
            )
                                                                                                                        |
            SET_NEXT_STATE(14,
                 IS_P13GT                           
            )
                                                                                                                        |
            SET_NEXT_STATE(15,
                IS_LT & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P15            
            )
                                                                                                                        |
            SET_NEXT_STATE(16,

                IS_P15LT

            )
                                                                                                                        |
            SET_NEXT_STATE(17,

                IS_PERIOD & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P18_OR_P17                           

            )    
                                                                                                                        |
            SET_NEXT_STATE(18,

                 IS_P17PERIOD                                       

            ) 
                                                                                                                        |
            SET_NEXT_STATE(19,
                IS_EXCLAMATION & IS_NOT_P23_OR_P22_OR_P21_OR_P20

            )
                                                                                                                        |
            SET_NEXT_STATE(20,
                IS_APOSTROPHE & IS_NOT_P23_OR_P22_OR_P21_OR_P20
            )
                                                                                                                        |
            SET_NEXT_STATE(21,

                IS_P20NOTAPOSTROPHE                   
            )   
                                                                                                                        |
            SET_NEXT_STATE(22,
                (IS_QUOTATION & IS_NOT_P23_OR_P22_OR_P21_OR_P20) |
                 IS_P22NOTQUOTATION             
            )
                                                                                                                        |
            SET_NEXT_STATE(23,
                IS_P21NOTAPOSTROPHE |
                IS_P23
            )
                                                                                                                        ;

                
            tokens[W_POS] |=
                
                (
                
                    CHR(GET_NEXT_STATE(20))                                   
                                                                               |
                    STR(IS_QUOTATION & IS_NOT_P23_OR_P22_OR_P21_OR_P20)        
                                                                               |
                    MUL(IS_P3 & IS_NOT_ASTERISK_OR_EQUAL)                      
                                                                               |
                    DIV(IS_P4 & IS_NOT_EQUAL) 
                                                                               |
                    PLUS(IS_P5 & IS_NOT_PLUS_OR_EQUAL)
                                                                               |
                    MIN(IS_P6 & IS_NOT_MIN_OR_EQUAL)
                                                                               |
                    MOD(IS_P7 & IS_NOT_EQUAL)
                                                                               |
                    ASSGN(IS_P8 & IS_NOT_GT_OR_EQUAL)
                                                                               |
                    BOR(IS_P9 & IS_NOT_BAR_OR_EQUAL)
                                                                               |
                    BAND(IS_P10 & IS_NOT_AMPERSAND_OR_EQUAL)
                                                                               |
                    BXOR(IS_P11 & IS_NOT_EQUAL)
                                                                               |
                    GT(IS_P12 & IS_NOT_GT_OR_EQUAL)
                                                                               |
                    SAR(IS_P13 & IS_NOT_GT_OR_EQUAL)
                                                                               |
                    SHR(IS_P14 & IS_NOT_EQUAL)
                                                                               |
                    LT(IS_P15 & IS_NOT_LT_OR_EQUAL)
                                                                               |
                    SHL(IS_P16 & IS_NOT_EQUAL)
                                                                               |
                    DOT(IS_P17 & IS_NOT_PERIOD)
                                                                               |
                    DDOT(IS_P18 & IS_NOT_PERIOD)
                                                                               |
                    ELLIP(IS_P18PERIOD)
                                                                               |
                    NOT(IS_P19 & IS_NOT_EQUAL)
                    

                ) << w_shft_factor;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
 
        
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
