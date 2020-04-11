#include <iostream>
#include <chrono>

#define SIZE 2000 
#define PREV_STATE 0
#define NEXT_STATE 1



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
#define SET_CHR(CONDITION)        (0x1 & CONDITION)

#define SET_STR(CONDITION)        (0x2 * CONDITION)

#define SET_MUL(CONDITION)        (0x3 * CONDITION)

#define SET_DIV(CONDITION)        (0x4 * CONDITION)

#define SET_PLUS(CONDITION)       (0x5 * CONDITION)

#define SET_MIN(CONDITION)        (0x6 * CONDITION)

#define SET_MOD(CONDITION)        (0x7 * CONDITION)

#define SET_ASSGN(CONDITION)      (0x8 * CONDITION)

#define SET_BOR(CONDITION)        (0x9 * CONDITION)

#define SET_BAND(CONDITION)       (0xA * CONDITION)

#define SET_BXOR(CONDITION)       (0xB * CONDITION)

#define SET_GT(CONDITION)         (0xC * CONDITION)

#define SET_SAR(CONDITION)        (0xD * CONDITION)

#define SET_SHR(CONDITION)        (0xE * CONDITION)

#define SET_LT(CONDITION)         (0xF * CONDITION)

#define SET_SHL(CONDITION)        (0x10 * CONDITION)

#define SET_DOT(CONDITION)        (0x11 * CONDITION)

#define SET_DDOT(CONDITION)       (0x12 * CONDITION)

#define SET_ELLIP(CONDITION)      (0x13 * CONDITION)

#define SET_NOT(CONDITION)        (0x14 * CONDITION)

#define SET_W_CHR(CONDITION)      (0x15 * CONDITION)

#define SET_W_STR(CONDITION)      (0x16 * CONDITION)

#define SET_MULEQ(CONDITION)      (0x17 * CONDITION)

#define SET_EXP(CONDITION)        (0x18 * CONDITION)

#define SET_COLON(CONDITION)      (0x19 * CONDITION)

#define SET_LPARAN(CONDITION)     (0x1A * CONDITION)

#define SET_RPARAN(CONDITION)     (0x1B * CONDITION)

#define SET_LBRACK(CONDITION)     (0x1C * CONDITION)

#define SET_RBRACK(CONDITION)     (0x1D * CONDITION)

#define SET_LBRACE(CONDITION)     (0x1E * CONDITION)

#define SET_RBRACE(CONDITION)     (0x1F * CONDITION)

#define SET_BNOT(CONDITION)       (0x20 * CONDITION)

#define SET_DIVEQ(CONDITION)      (0x21 * CONDITION)

#define SET_PE(CONDITION)         (0x22 * CONDITION)

#define SET_INC(CONDITION)        (0x23 * CONDITION)

#define SET_MINE(CONDITION)       (0x24 * CONDITION)

#define SET_DEC(CONDITION)        (0x25 * CONDITION)

#define SET_MODEQ(CONDITION)      (0x26 * CONDITION)

#define SET_EQ(CONDITION)         (0x27 * CONDITION)

#define SET_FARROW(CONDITION)     (0x28 * CONDITION)

#define SET_BOREQ(CONDITION)      (0x29 * CONDITION)

#define SET_LOR(CONDITION)        (0x2A * CONDITION)

#define SET_BANDEQ(CONDITION)     (0x2B * CONDITION)

#define SET_LAND(CONDITION)       (0x2C * CONDITION)

#define SET_BXOREQ(CONDITION)     (0x2D * CONDITION)

#define SET_GTE(CONDITION)        (0x2E * CONDITION)

#define SET_SAREQ(CONDITION)      (0x2F * CONDITION)

#define SET_SHREQ(CONDITION)      (0x30 * CONDITION)

#define SET_LTE(CONDITION)        (0x31 * CONDITION)

#define SET_SHLEQ(CONDITION)      (0x32 * CONDITION)

#define SET_NOTEQ(CONDITION)      (0x33 * CONDITION)

#define SET_R_CHR(CONDITION)      (0x34 * CONDITION)

#define SET_R_STR(CONDITION)      (0x35 * CONDITION)

#define SET_W_NUM(CONDITION)      (0x36 * CONDITION)

#define SET_W_ALPHANUM(CONDITION) (tokens[i+1] * CONDITION)

#define SET_NUM(CONDITION)        (0x38 * CONDITION)

#define SET_R_ALPHANUM(CONDITION) (0x39 * CONDITION)

#define SET_ERROR(CONDITION)      (0x3A * CONDITION)

/* END OF TOKEN DEFINITIONS */

                                                                                                    
#define IS_TILDE_OR_BRACK_OR_BRACE_OR_PARAN_OR_COLON_OR_WS ((tokens[i] & 0xFF800000) != 0)
                      
#define IS_NOT_P23_OR_P22_OR_P21_OR_P20 ((tokens[PREV_STATE] & 0xF00000) == 0 )

#define IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P18_OR_P17_OR_P2_OR_P1_OR_P0 ((tokens[PREV_STATE] & 0xF60007) == 0 )

#define IS_P21_OR_P20 ( (tokens[PREV_STATE] & 0x300000) != 0 )

#define P3ASTERISK_OR_P5PLUS_OR_P6HYPHEN_OR_P9BAR_OR_P10AMPERSAND ( ((tokens[i] & 0x668) & tokens[PREV_STATE]) != 0 )

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

#define IS_NOT_ASTERISK_OR_EQUAL ((tokens[i] & 0x108) == 0) 

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

#define IS_P22 ((tokens[PREV_STATE] & 0x400000) != 0)

#define IS_NOT_PERIOD ((tokens[i] & 0x20000) == 0)

#define IS_P18PERIOD ((((tokens[i] & 0x20000) << 1) & tokens[PREV_STATE]) != 0)

#define IS_NOT_QUOTATION ((tokens[i] & 0x400000) == 0)

#define N20 ((tokens[NEXT_STATE] & 0x100000) != 0)

#define N21 ((tokens[NEXT_STATE] & 0x200000) != 0)

#define IS_P3EQUAL (((tokens[i] & 0x100) & (tokens[PREV_STATE] << 5)) != 0)

#define IS_P3ASTERISK (((tokens[i] & 0x8) & tokens[PREV_STATE]) != 0)

#define IS_P4EQUAL (((tokens[i] & 0x100) & (tokens[PREV_STATE] << 4)) != 0)

#define IS_P5EQUAL (((tokens[i] & 0x100) & (tokens[PREV_STATE] << 3)) != 0)

#define IS_P5PLUS (((tokens[i] & 0x20) & tokens[PREV_STATE]) != 0)

#define IS_P6EQUAL (((tokens[i] & 0x100) & (tokens[PREV_STATE] << 2)) != 0)

#define IS_P6HYPHEN (((tokens[i] & 0x40) & tokens[PREV_STATE]) != 0)

#define IS_P7EQUAL (((tokens[i] & 0x100) & (tokens[PREV_STATE] << 1)) != 0)

#define IS_P8EQUAL (((tokens[i] & 0x100) & tokens[PREV_STATE]) != 0)

#define IS_P8GT (((tokens[i] & 0x1000) & tokens[PREV_STATE] << 4)  != 0)

#define IS_P9EQUAL ((((tokens[i] & 0x100) << 1) & tokens[PREV_STATE]) != 0)

#define IS_P9BAR (((tokens[i] & 0x200) & tokens[PREV_STATE]) != 0)

#define IS_P10EQUAL ((((tokens[i] & 0x100) << 2) & tokens[PREV_STATE]) != 0) 

#define IS_P10AMPERSAND (((tokens[i] & 0x400) & tokens[PREV_STATE]) != 0)

#define IS_P11EQUAL ((((tokens[i] & 0x100) << 3) & tokens[PREV_STATE]) != 0)

#define IS_P12EQUAL ((((tokens[i] & 0x100) << 4) & tokens[PREV_STATE]) != 0)

#define IS_P13EQUAL ((((tokens[i] & 0x100) << 5) & tokens[PREV_STATE]) != 0)

#define IS_P14EQUAL ((((tokens[i] & 0x100) << 6) & tokens[PREV_STATE]) != 0)

#define IS_P15EQUAL ((((tokens[i] & 0x100) << 7) & tokens[PREV_STATE]) != 0)

#define IS_P16EQUAL ((((tokens[i] & 0x100) << 8) & tokens[PREV_STATE]) != 0)

#define IS_P19EQUAL ((((tokens[i] & 0x100) << 11) & tokens[PREV_STATE]) != 0)

#define IS_P20APOSTROPHE_OR_P21APOSTROPHE ((((tokens[i] & 0x100000) != 0) & ((tokens[PREV_STATE] & 0x300000) != 0)) != 0)

#define IS_P22QUOTATION (((tokens[i] & 0x400000) & tokens[PREV_STATE]) != 0)

#define IS_P2NOTNUMERAL ((((tokens[i] & 0x4) == 0) & ((tokens[PREV_STATE] & 0x4) != 0)) != 0)

#define IS_P1NOT_ALPHABET_OR_UNDERSCORE ((((tokens[i] & 0x3) == 0) & ((tokens[PREV_STATE] & 0x2) != 0)) != 0)

#define IS_N23 ((tokens[NEXT_STATE] & 0x800000) != 0)

// #define IS_W_ALPHANUM ((tokens[w_token/8] & 0xFF) == 0x37)

// #define IS_R_ALPHANUM ((tokens[w_token/8] & 0xFF) == 0x39)

int main() {
    
    /*
     *  For Next time, write ALPHANUM_BUFFER into Tokens Buffer when Token is a R_ALPHANUM and clear the buffer.
     *  Then, do the NUMERAL_BUFFER and Operator Stack. 
     */
   
    
    
    uint64_t tokens[SIZE] = {0x0}; // 16,000 BYTES : 250/512 CACHE-LINES
    tokens[PREV_STATE] = 0x1;
    uint32_t i = 3;
    uint32_t w_token = 16;
//     uint32_t start_to_buffer = 0;
    
    while((tokens[i] = getchar())) {
        
        std::cout << "PREV_STATE: " << (tokens[PREV_STATE]&0xFFFFFFFF) << std::endl;
        
        // Regardless if TOKEN is W_ALPHANUM, write the getchar() value in ALPHANUM_BUFFER in case it is.
        // Later on, value will be overwritten if it wasn't, or it will be shifted to the left if it was.
        
//         tokens[ALPHANUM_BUFFER + (buffer_num/64)]   = ((tokens[ALPHANUM_BUFFER + (buffer_num/64)] & 0xFFFFFFFFFFFFFF00) | tokens[i]);
            

        tokens[i+1] = tokens[i]; 
        
        
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
                                                        
 
    // Store the new Previous State  but do not change Previous State now
    // since it is needed to calculate Next State. Think of this as a 
    // temporary variable.
//     tokens[NEXT_STATE] <<= 32;         

    tokens[NEXT_STATE] = 
              
            SET_NEXT_STATE(0, 

                (IS_TILDE_OR_BRACK_OR_BRACE_OR_PARAN_OR_COLON_OR_WS & IS_NOT_P23_OR_P22_OR_P21_OR_P20) |
                (IS_EQUAL & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P18_OR_P17_OR_P2_OR_P1_OR_P0)           |
                 P3ASTERISK_OR_P5PLUS_OR_P6HYPHEN_OR_P9BAR_OR_P10AMPERSAND                             |
                 P18PERIOD_OR_P21APOSTROPHE                                                            |
                 P20APOSTROPHE_OR_P22QUOTATION                                                         |
                 IS_P8GT
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

                
            tokens[w_token/8] |=
                
                (              
                    SET_CHR((N20))                                   
                                                                                                       |
                    SET_STR((IS_QUOTATION & IS_NOT_P23_OR_P22_OR_P21_OR_P20))        
                                                                                                       |
                    SET_MUL((IS_P3 & IS_NOT_ASTERISK_OR_EQUAL))                      
                                                                                                       |
                    SET_DIV((IS_P4 & IS_NOT_EQUAL)) 
                                                                                                       |
                    SET_PLUS((IS_P5 & IS_NOT_PLUS_OR_EQUAL))
                                                                                                       |
                    SET_MIN((IS_P6 & IS_NOT_MIN_OR_EQUAL))
                                                                                                       |
                    SET_MOD((IS_P7 & IS_NOT_EQUAL))
                                                                                                       |
                    SET_ASSGN((IS_P8 & IS_NOT_GT_OR_EQUAL))
                                                                                                       |
                    SET_BOR((IS_P9 & IS_NOT_BAR_OR_EQUAL))
                                                                                                       |
                    SET_BAND((IS_P10 & IS_NOT_AMPERSAND_OR_EQUAL))
                                                                                                       |
                    SET_BXOR((IS_P11 & IS_NOT_EQUAL))
                                                                                                       |
                    SET_GT((IS_P12 & IS_NOT_GT_OR_EQUAL))
                                                                                                       |
                    SET_SAR((IS_P13 & IS_NOT_GT_OR_EQUAL))
                                                                                                       |
                    SET_SHR((IS_P14 & IS_NOT_EQUAL))
                                                                                                       |
                    SET_LT((IS_P15 & IS_NOT_LT_OR_EQUAL))
                                                                                                       |
                    SET_SHL((IS_P16 & IS_NOT_EQUAL))
                                                                                                       |
                    SET_DOT((IS_P17 & IS_NOT_PERIOD))
                                                                                                       |
                    SET_DDOT((IS_P18 & IS_NOT_PERIOD))
                                                                                                       |
                    SET_ELLIP((IS_P18PERIOD))
                                                                                                       |
                    SET_NOT((IS_P19 & IS_NOT_EQUAL))
                                                                                                       |
                    SET_W_CHR((N21))
                                                                                                       |
                    SET_W_STR((IS_P22 & IS_NOT_QUOTATION))
                                                                                                       |
                    SET_MULEQ((IS_P3EQUAL))
                                                                                                       |
                    SET_EXP((IS_P3ASTERISK))
                                                                                                       |
                    SET_COLON((IS_COLON & IS_NOT_P23_OR_P22_OR_P21_OR_P20))
                                                                                                       |
                    SET_LPARAN((IS_LPARANTHESIS & IS_NOT_P23_OR_P22_OR_P21_OR_P20))
                                                                                                       |
                    SET_RPARAN((IS_RPARANTHESIS & IS_NOT_P23_OR_P22_OR_P21_OR_P20))
                                                                                                       |
                    SET_LBRACK((IS_LBRACKET & IS_NOT_P23_OR_P22_OR_P21_OR_P20))
                                                                                                       |
                    SET_RBRACK((IS_RBRACKET & IS_NOT_P23_OR_P22_OR_P21_OR_P20))
                                                                                                       |
                    SET_LBRACE((IS_LBRACE & IS_NOT_P23_OR_P22_OR_P21_OR_P20))
                                                                                                       |
                    SET_RBRACE((IS_RBRACE & IS_NOT_P23_OR_P22_OR_P21_OR_P20))
                                                                                                       |
                    SET_BNOT((IS_TILDE & IS_NOT_P23_OR_P22_OR_P21_OR_P20))
                                                                                                       |
                    SET_DIVEQ((IS_P4EQUAL))
                                                                                                       |
                    SET_PE((IS_P5EQUAL))
                                                                                                       |
                    SET_INC((IS_P5PLUS))
                                                                                                       |
                    SET_MINE((IS_P6EQUAL))
                                                                                                       |
                    SET_DEC((IS_P6HYPHEN))
                                                                                                       |
                    SET_MODEQ((IS_P7EQUAL))
                                                                                                       |
                    SET_EQ((IS_P8EQUAL))
                                                                                                       |
                    SET_FARROW((IS_P8GT))
                                                                                                       |
                    SET_BOREQ((IS_P9EQUAL))
                                                                                                       |
                    SET_LOR((IS_P9BAR))
                                                                                                       |
                    SET_BANDEQ((IS_P10EQUAL))
                                                                                                       |
                    SET_LAND((IS_P10AMPERSAND))
                                                                                                       |
                    SET_BXOREQ((IS_P11EQUAL))
                                                                                                       |
                    SET_GTE((IS_P12EQUAL))
                                                                                                       |
                    SET_SAREQ((IS_P13EQUAL))
                                                                                                       |
                    SET_SHREQ((IS_P14EQUAL))
                                                                                                       |
                    SET_LTE((IS_P15EQUAL))
                                                                                                       |
                    SET_SHLEQ((IS_P16EQUAL))
                                                                                                       |
                    SET_NOTEQ((IS_P19EQUAL))
                                                                                                       |
                    SET_R_CHR((IS_P20APOSTROPHE_OR_P21APOSTROPHE))
                                                                                                       |
                    SET_R_STR((IS_P22QUOTATION))
                                                                                                       |
                    SET_W_NUM((IS_NUMERAL & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P1))  
                                                                                                       |
                    SET_W_ALPHANUM((IS_UNDERSCORE_OR_ALPHABET & IS_NOT_P23_OR_P22_OR_P21_OR_P20))
                                                                                                       |
                    SET_NUM((IS_P2NOTNUMERAL))
                                                                                                       |
                    SET_R_ALPHANUM((IS_P1NOT_ALPHABET_OR_UNDERSCORE))
                                                                                                       |
                    SET_ERROR((IS_N23))
                
                ) << ((w_token % 8) << 3) ;
 
           
                   
            std::cout << "NEXT_STATE: " << (tokens[NEXT_STATE]&0xFFFFFFFF) << std::endl;
            
            // If TOKEN is W_ALPHANUM, then store value Alphanum input in ALPHANUM_BUFFER.
            // If TOKEN is not W_ALPHANUM, then don't shift and allow value to be overwritten
            // in the next round.
//             tokens[ALPHANUM_BUFFER + (buffer_num/64)] <<= ( (IS_W_ALPHANUM & (buffer_num < 56)) * 8);
         
//             std::cout << "IS_W_ALPHANUM: " << IS_W_ALPHANUM << std::endl;
            
        
//             std::cout << "ALPHANUM_BUFFER " << tokens[ALPHANUM_BUFFER] << std::endl;
//             std::cout << "ALPHANUM_BUFFER1: " << tokens[ALPHANUM_BUFFER + 1] << std::endl;
            
             
            
            // If the current ALPHANUM_BUFFER is full, then move on to the next buffer. This
            // is done by incrementing buffer_num.
//             buffer_num += (IS_W_ALPHANUM*8);
        
        
//             std::cout << "ALPHANUM_BUFFER is ==== " << (tokens[ALPHANUM_BUFFER] == 0x6161616161616161) << std::endl;
        
//             std::cout << "Buffer SZ: " <<  (int)buffer_num << std::endl;
        
//             tokens[W_POS] = (tokens[W_POS] & (0xFFFFFFFFFFFFFFFF << (buffer_num % 64)));
//             
            std::cout << "tokens[wpos]" << std::hex << tokens[w_token/8]  << std::endl;
        
        
           
               
            tokens[i] = 0x0;
            tokens[i+1] = 0x0;
            
        
            w_token += ((tokens[w_token/8] & (static_cast<uint64_t>(0xFF)<< ((w_token%8) << 3))) != 0);
          
//             buffer_num += (tokens[ALPHANUM_BUFFER + buffer_num] > 0x00FFFFFFFFFFFFFF);
//             w_lshft_factor += (((tokens[W_POS/8] & (0xFF << w_lshft_factor)))<< 3); 
       
            // Move to next index when current space is full.
            // W_POS moved as well since it's an alias of (i-1)
            i += !(w_token%8);
        
//             w_lshft_factor = (w_lshft_factor < 56)*w_lshft_factor;
 
            
            
            // Shift Token 1 Byte to the left to make room for next token at
            // the Most significant Byte. Do not shift if there was no output.
//             tokens[W_POS] <<= ((tokens[W_POS] & 0xFF) != 0)*8;
            
                
                
            // Set Previous State to the old Next State. When Reading Previous State,
            // only most significant 23-Bits are ever read. That is why we don't care 
            // to do an Arithmetic Shift-Right operation here.
            tokens[PREV_STATE] = tokens[NEXT_STATE];
               
             
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
