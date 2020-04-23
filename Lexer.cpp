#include <iostream>
#include <chrono>

#define SIZE 2000 
#define PREV_STATE       0                 // Previous State (P0 - P23)
#define NEXT_STATE       1                 // Next State (N0 - N23)
#define W_TOKEN_INIT     2                 // Used to initailize w_token. Tokens are initially outputted here.
#define NUM_BUFFER      (2+(w_token/8))    // Buffer to compute number while IS_W_NUM is on. Two spaces from w_token.
#define INPUT_INIT       6                 // Initial Buffer where input is read into. Four spaces from w_token.
#define ALPHANUM_BUFFER  i+1               // Buffer to get alphanum input when IS_W_ALPHANUM is on.


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

#define CHR        (0x1)

#define STR        (0x2)

#define MUL        (0x3)

#define DIV        (0x4)

#define PLUS       (0x5)

#define MIN        (0x6)

#define MOD        (0x7)

#define ASSGN      (0x8)

#define BOR        (0x9)

#define BAND       (0xA)

#define BXOR       (0xB)

#define GT         (0xC)

#define SAR        (0xD)

#define SHR        (0xE)

#define LT         (0xF)

#define SHL        (0x10)

#define DOT        (0x11)

#define DDOT       (0x12)

#define ELLIP      (0x13)

#define NOT        (0x14)

#define W_CHR      (0x15)

#define W_STR      (0x16)

#define MULEQ      (0x17)

#define EXP        (0x18)

#define COLON      (0x19)

#define LPARAN     (0x1A)

#define RPARAN     (0x1B)

#define LBRACK     (0x1C)

#define RBRACK     (0x1D)

#define LBRACE     (0x1E)

#define RBRACE     (0x1F)

#define BNOT       (0x20)

#define DIVEQ      (0x21)

#define PE         (0x22)

#define INC        (0x23)

#define MINE       (0x24)

#define DEC        (0x25)

#define MODEQ      (0x26)

#define EQ         (0x27)

#define FARROW     (0x28)

#define BOREQ      (0x29)

#define LOR        (0x2A)

#define BANDEQ     (0x2B)

#define LAND       (0x2C)

#define BXOREQ     (0x2D)

#define GTE        (0x2E)

#define SAREQ      (0x2F)

#define SHREQ      (0x30)

#define LTE        (0x31)

#define SHLEQ      (0x32)

#define NOTEQ      (0x33)

#define R_CHR      (0x34)

#define R_STR      (0x35)

#define W_NUM      (0x36) /* May be removed */

#define W_ALPHANUM (0x37) /* May be removed */

#define NUM        (0x38)

#define R_ALPHANUM (0x39) /* May be removed */

#define ERROR      (0x3A)

#define VAR        (0x3B)

#define IS         (0x3C)



/* END OF TOKEN DEFINITIONS */


/* For setting outputs that ARE Tokens */
#define SET_CHR(CONDITION)        (CHR & CONDITION)

#define SET_STR(CONDITION)        (STR * CONDITION)

#define SET_MUL(CONDITION)        (MUL * CONDITION)

#define SET_DIV(CONDITION)        (DIV * CONDITION)

#define SET_PLUS(CONDITION)       (PLUS * CONDITION)

#define SET_MIN(CONDITION)        (MIN * CONDITION)

#define SET_MOD(CONDITION)        (MOD * CONDITION)

#define SET_ASSGN(CONDITION)      (ASSGN * CONDITION)

#define SET_BOR(CONDITION)        (BOR * CONDITION)

#define SET_BAND(CONDITION)       (BAND * CONDITION)

#define SET_BXOR(CONDITION)       (BXOR * CONDITION)

#define SET_GT(CONDITION)         (GT * CONDITION)

#define SET_SAR(CONDITION)        (SAR * CONDITION)

#define SET_SHR(CONDITION)        (SHR * CONDITION)

#define SET_LT(CONDITION)         (LT * CONDITION)

#define SET_SHL(CONDITION)        (SHL * CONDITION)

#define SET_DOT(CONDITION)        (DOT * CONDITION)

#define SET_DDOT(CONDITION)       (DDOT * CONDITION)

#define SET_ELLIP(CONDITION)      (ELLIP * CONDITION)

#define SET_NOT(CONDITION)        (NOT * CONDITION)

#define SET_W_CHR(CONDITION)      (W_CHR * CONDITION)

#define SET_W_STR(CONDITION)      (W_STR * CONDITION)

#define SET_MULEQ(CONDITION)      (MULEQ * CONDITION)

#define SET_EXP(CONDITION)        (EXP * CONDITION)

#define SET_COLON(CONDITION)      (COLON * CONDITION)

#define SET_LPARAN(CONDITION)     (LPARAN * CONDITION)

#define SET_RPARAN(CONDITION)     (RPARAN * CONDITION)

#define SET_LBRACK(CONDITION)     (LBRACK* CONDITION)

#define SET_RBRACK(CONDITION)     (RBRACK * CONDITION)

#define SET_LBRACE(CONDITION)     (LBRACE * CONDITION)

#define SET_RBRACE(CONDITION)     (RBRACE * CONDITION)

#define SET_BNOT(CONDITION)       (BNOT * CONDITION)

#define SET_DIVEQ(CONDITION)      (DIVEQ * CONDITION)

#define SET_PE(CONDITION)         (PE * CONDITION)

#define SET_INC(CONDITION)        (INC * CONDITION)

#define SET_MINE(CONDITION)       (MINE * CONDITION)

#define SET_DEC(CONDITION)        (DEC * CONDITION)

#define SET_MODEQ(CONDITION)      (MODEQ * CONDITION)

#define SET_EQ(CONDITION)         (EQ * CONDITION)

#define SET_FARROW(CONDITION)     (FARROW * CONDITION)

#define SET_BOREQ(CONDITION)      (BOREQ * CONDITION)

#define SET_LOR(CONDITION)        (LOR * CONDITION)

#define SET_BANDEQ(CONDITION)     (BANDEQ * CONDITION)

#define SET_LAND(CONDITION)       (LAND * CONDITION)

#define SET_BXOREQ(CONDITION)     (BXOREQ * CONDITION)

#define SET_GTE(CONDITION)        (GTE * CONDITION)

#define SET_SAREQ(CONDITION)      (SAREQ * CONDITION)

#define SET_SHREQ(CONDITION)      (SHREQ * CONDITION)

#define SET_LTE(CONDITION)        (LTE * CONDITION)

#define SET_SHLEQ(CONDITION)      (SHLEQ * CONDITION)

#define SET_NOTEQ(CONDITION)      (NOTEQ * CONDITION)

#define SET_R_CHR(CONDITION)      (R_CHR * CONDITION)

#define SET_R_STR(CONDITION)      (R_ST * CONDITION)

#define SET_W_NUM(CONDITION)      (W_NUM * CONDITION)      /* May be removed */

#define SET_W_ALPHANUM(CONDITION) (W_ALPHANUM * CONDITION) /* May be removed */

#define SET_NUM(CONDITION)        (NUM * CONDITION)        /* May be removed */

#define SET_R_ALPHANUM(CONDITION) (R_ALPHANUM * CONDITION) /* May be removed */

#define SET_ERROR(CONDITION)      (ERROR * CONDITION)

/* Ouputs that are NOT Tokens */
#define IS_W_ALPHANUM ((IS_UNDERSCORE_OR_ALPHABET & IS_NOT_P23_OR_P22_OR_P21_OR_P20) | IS_P1NUMERAL)

#define IS_R_ALPHANUM (IS_P1NOT_ALPHABET_OR_UNDERSCORE_OR_NUMERAL)

#define IS_W_NUM      (IS_NUMERAL & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P1)

#define IS_R_NUM      (IS_P2NOTNUMERAL)

#define IS_W_CHR      (N21)
                                                                                                      
#define IS_W_STR      (IS_P22 & IS_NOT_QUOTATION)

#define IS_R_CHR      (IS_P20APOSTROPHE_OR_P21APOSTROPHE)
                                                                                                       
#define IS_R_STR      (IS_P22QUOTATION)


/* For setting the NEXT_STATE */                                                                                                    
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

#define IS_P1NOT_ALPHABET_OR_UNDERSCORE_OR_NUMERAL ((((tokens[i] & 0x7) == 0) & ((tokens[PREV_STATE] & 0x2) != 0)) != 0)

#define IS_N23 ((tokens[NEXT_STATE] & 0x800000) != 0)


int main() {

   // (1)   Index is the PREV_STATE.   (CONSTANT Index: Permanently 1 -- For Now --)
   // (2)   Index is the NEXT_STATE.   (CONSTANT)
   // (3)   Index is w_token space.    (VARIABLE Index: Changes when current space reaches capacity.)
   // (5)   Index is NUM_BUFFER.       (VARIABLE)
   // (7)   Index is input space.      (VARIABLE)
   // (8)   Index is ALPHANUM_BUFFER   (VARIABLE)
    uint64_t tokens[SIZE] = {0x0}; // 16,000 BYTES : 250/512 CACHE-LINES
        
    tokens[PREV_STATE] = 0x1;
    uint32_t i = INPUT_INIT;
    uint32_t w_token = W_TOKEN_INIT*8;
    uint32_t start_to_alphanum = 0;
    
    while(((tokens[i] = getchar()) != 0x23 )) {
/*temp*/std::cout << std::hex;       
/*temp*/std::cout << "PREV_STATE: " << tokens[PREV_STATE] << std::endl;
               
        // Premptively store alphanum in temporary buffer in case of a IS_W_ALPHANUM.
        // Information of alphanum is going to be lost in next step. 
        tokens[ALPHANUM_BUFFER] = tokens[i]; 
        
        
        // Set the corresponding bit of current input to 1. So far, there are 27 possible inputs (counting a-z and A-Z as 1 etc.).
        // This means that 27 bits out of the 64-bit data type (tokens[i]) are used. Ony one bit can be set to 1 at a time.
        // The position of the 1 indicates what the input was and it can be used as a bool flag throughout the loop. Why not just
        // store the ASCII directly into the 64-bit and just compare like that? Because doing the flag method allows for easier
        // comparison between input and previous state. Notice how the inputs below are made to align with their corresponding
        // states. For instance, notice how '*' is shifted 3 bits. The '*' happens to be at state S3. To check if the input is 
        // '*' and the Previous State is P3, all is needed is the expression: (tokens[i] & 0x8) & tokens[PREV_STATE]. If those
        // 1's align, then the statement is true. Compare that to: (tokens[i] == '*') & (tokens[PREV_STATE] == 0x8). This 
        // benefit can be seen better when more terms are involved. See: P3ASTERISK_OR_P5PLUS_OR_P6HYPHEN_OR_P9BAR_OR_P10AMPERSAND
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

/*temp*/std::cout << "tokens[i]: " << tokens[i] << std::endl;      
        // Set the Next State N0...N23.
        tokens[NEXT_STATE] = 
            
            // N0 
            SET_NEXT_STATE(0, 

                (IS_TILDE_OR_BRACK_OR_BRACE_OR_PARAN_OR_COLON_OR_WS & IS_NOT_P23_OR_P22_OR_P21_OR_P20) |
                (IS_EQUAL & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P18_OR_P17_OR_P2_OR_P1_OR_P0)           |
                 P3ASTERISK_OR_P5PLUS_OR_P6HYPHEN_OR_P9BAR_OR_P10AMPERSAND                             |
                 P18PERIOD_OR_P21APOSTROPHE                                                            |
                 P20APOSTROPHE_OR_P22QUOTATION                                                         |
                 IS_P8GT
            )  
                                                                                                                        |
            // N1
            SET_NEXT_STATE(1,                 
                (IS_UNDERSCORE_OR_ALPHABET & IS_NOT_P23_OR_P22_OR_P21_OR_P20)|
                 IS_P1NUMERAL   

            )                                                                                                    
                                                                                                                        |
            // N2
            SET_NEXT_STATE(2,
                IS_NUMERAL & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P1
            )
                                                                                                                        |
            // N3
            SET_NEXT_STATE(3,

                IS_ASTERISK & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P3
            )
                                                                                                                        |
            // N4
            SET_NEXT_STATE(4,

                IS_FSLASH & IS_NOT_P23_OR_P22_OR_P21_OR_P20            
            )
                                                                                                                        |
            // N5
            SET_NEXT_STATE(5,
                IS_PLUS & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P5          
            )
                                                                                                                        |
            // N6
            SET_NEXT_STATE(6,
                IS_HYPHEN & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P6
            )
                                                                                                                        |
            // N7
            SET_NEXT_STATE(7,
                IS_PERCENT & IS_NOT_P23_OR_P22_OR_P21_OR_P20
            )
                                                                                                                        |
            // N8
            SET_NEXT_STATE(8,
                IS_EQUAL & IS_P0_OR_P1_OR_P2_OR_P17_OR_P18                      
            )
                                                                                                                        |
            // N9
            SET_NEXT_STATE(9,
                IS_BAR & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P9
            )
                                                                                                                        |
            // N10
            SET_NEXT_STATE(10,
                IS_AMPERSAND & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P10
            )
                                                                                                                        |
            // N11
            SET_NEXT_STATE(11,
                IS_CARET & IS_NOT_P23_OR_P22_OR_P21_OR_P20                     
            )
                                                                                                                        |
            // N12
            SET_NEXT_STATE(12,
                IS_GT & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P13_OR_P12_OR_P8                  
            )
                                                                                                                        |
            // N13
            SET_NEXT_STATE(13,
                IS_P12GT                  
            )
                                                                                                                        |
            // N14
            SET_NEXT_STATE(14,
                 IS_P13GT                           
            )
                                                                                                                        |
            // N15
            SET_NEXT_STATE(15,
                IS_LT & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P15            
            )
                                                                                                                        |
            // N17
            SET_NEXT_STATE(16,

                IS_P15LT

            )
                                                                                                                        |
            // N17
            SET_NEXT_STATE(17,

                IS_PERIOD & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P18_OR_P17                           

            )    
                                                                                                                        |
            // N18
            SET_NEXT_STATE(18,

                 IS_P17PERIOD                                       

            ) 
                                                                                                                        |
            // N19
            SET_NEXT_STATE(19,
                IS_EXCLAMATION & IS_NOT_P23_OR_P22_OR_P21_OR_P20

            )
                                                                                                                        |
            // N20
            SET_NEXT_STATE(20,
                IS_APOSTROPHE & IS_NOT_P23_OR_P22_OR_P21_OR_P20
            )
                                                                                                                        |
            // N21
            SET_NEXT_STATE(21,

                IS_P20NOTAPOSTROPHE                   
            )   
                                                                                                                        |
            // N22
            SET_NEXT_STATE(22,
                (IS_QUOTATION & IS_NOT_P23_OR_P22_OR_P21_OR_P20) |
                 IS_P22NOTQUOTATION             
            )
                                                                                                                        |
            // N23
            SET_NEXT_STATE(23,
                IS_P21NOTAPOSTROPHE |
                IS_P23
            )                          
                                                                                                                        ;
/*temp*/std::cout << "NEXT_STATE: " << tokens[NEXT_STATE] << std::endl;                                                                                                                ;
        // Write the Token output, if any, to the Token space via the w_token "pointer".
        // There may be two outputs, hence the two writes to tokens[w_token/8]. However, 
        // if the first writes, then w_token write "pointer" is adjusted.
        tokens[w_token/8] |= 
                    
            static_cast<uint64_t>(
                
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
                SET_MULEQ((IS_P3EQUAL))
                                                                                                   |
                SET_EXP((IS_P3ASTERISK))
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
                
            
            ) << ((w_token % 8) << 3);
        
/*temp*/std::cout << "tokens[w_token]1: " << tokens[w_token/8] << std::endl;        
        // Move write "pointer" one space over in Token array if above wrote in a Token to current spot.
        w_token += ((tokens[w_token/8] & (static_cast<uint64_t>(0xFF) << ((w_token % 8) << 3))) != 0);
/*temp*/std::cout << "w_token1: " << w_token << std::endl;        
        // Write the Token output, if any, to the Token space via the w_token "pointer". 
        tokens[w_token/8] |= 
 
            static_cast<uint64_t>( 
            
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
                SET_ERROR((IS_N23))
                
            ) << ((w_token % 8) << 3) ;
      
        
/*temp*/std::cout << "tokens[w_token]2: " << tokens[w_token/8] << std::endl;        
/*temp*/std::cout << "IS_W_ALPHANUM: " << IS_W_ALPHANUM << std::endl;        

        
        
        // When IS_R_ALPHANUM is on and the alphanums from start_to_alphanum to w_token match a keyword, then write at
        // start_to_alphanum the corresponding 1 Byte Token. Note: part of keyword may be in adjacent parts of the Tokens
        // array. This needs to be considered when matching.
        tokens[start_to_alphanum/8] |= 
            static_cast<uint64_t>(
                (
                    !(
                        ((static_cast<uint64_t>(0x7369)) << (((start_to_alphanum+2)%8)*8)) ^ 
                        (tokens[(start_to_alphanum+2)/8] & ((static_cast<uint64_t>(0xFFFF)) << (((start_to_alphanum+2)%8)*8)))
                     ) &
                    
                    !(
                        ((static_cast<uint64_t>(0x7369)) >> ((6-(start_to_alphanum%8))*8)) ^ 
                        (tokens[w_token/8] & (static_cast<uint64_t>(0xFFFF) >> ((6-(start_to_alphanum%8))*8)))
                     ) &
                    
                     // Check if Length is 2. If not, then no match.
                     (
                        (tokens[(start_to_alphanum+1)/8] & static_cast<uint64_t>(0xFF) << (((start_to_alphanum+1)%8)*8)) == 
                         
                        (static_cast<uint64_t>(0x2) << (((start_to_alphanum+1)%8)*8))
                     )  
                
                )*IS
        
            )*IS_R_ALPHANUM << ((start_to_alphanum%8)*8);
        
        
        
        // When IS_R_ALPHANUM is on and a Keyword Token has not been written at this point, then the 
        // alphanums are part of a VAR Token. Writes VAR Token at the beginning of the alphanums.
        tokens[start_to_alphanum/8] |=
            static_cast<uint64_t>(
                !((tokens[start_to_alphanum/8] & ((static_cast<uint64_t>(0xFF)) << ((start_to_alphanum%8)*8))))&IS_R_ALPHANUM
            
            )*VAR << ((start_to_alphanum%8)*8);
        
        // When IS_R_STR or IS_R_CHR, write the corresponding Token at the beginning of the alphanum/s.
        tokens[start_to_alphanum/8] |=
            (static_cast<uint64_t>(IS_R_STR)*STR + static_cast<uint64_t>(IS_R_CHR)*CHR) << ((start_to_alphanum%8)*8);
        
        // Read Number from NUM_BUFFER and write it at 6 Byte location reserved for it in Token array.
        tokens[(start_to_alphanum)/8]   |= static_cast<uint64_t>(IS_R_NUM)*(((tokens[NUM_BUFFER] << 8) | NUM) << (((start_to_alphanum)%8)*8));  
        tokens[(start_to_alphanum+6)/8] |= static_cast<uint64_t>(IS_R_NUM)*(tokens[NUM_BUFFER] >> ((8 - ((start_to_alphanum+1)%8))*8));  
        
/*temp*/std::cout << "tokens[(start_to_alphanum+1)/8]: " << tokens[(start_to_alphanum+1)/8] << std::endl; 
/*temp*/std::cout << "tokens[(start_to_alphanum+7)/8]: " << tokens[(start_to_alphanum+7)/8] << std::endl;         
        // Reset start_to_alphanum to zero if either IS_R_ALPHANUM, IS_R_NUM, IS_R_STR, or IS_R_CHR are on. 
        // For IS_R_ALPHANUM, the VAR/KEYWORD is already known at the this point.
        start_to_alphanum = !(IS_R_ALPHANUM | IS_R_NUM | IS_R_CHR | IS_R_STR)*(start_to_alphanum);
        
        // Save current w_token (the write "pointer" for tokens) if either IS_W_ALPHANUM, IS_W_NUM, IS_W_CHR, or IS_W_STR are on, 
        // AND start_to_alphanum is off. This means alphanums (can be part of a keyword, variable, number, string, or character) 
        // are being written into Tokens space, and the start position needs to be saved so either VAR/KEYWORD/NUM/CHR/STR are
        // later written there when Token is known. Otherwise, retain start_to_alphanum's current value.
        start_to_alphanum = ((w_token*(IS_W_ALPHANUM | IS_W_NUM | IS_W_STR | IS_W_CHR)*!start_to_alphanum) + start_to_alphanum);
/*temp*/std::cout << "start_to_alphanum: " << start_to_alphanum<< std::endl;
        // When IS_W_ALPHANUM, IS_W_STR, or IS_W_CHR are on and it's the beginning of an alphanum, w_token skips ahead and reserves 
        // two bytes for Token (VAR/KEYWORD/STR/CHR) and Length and continues writing the alphanum starting at the third byte. 
        // The alphanum was premptively stored at tokens[i+1] (ALPHANUM_BUFFER), so copy it over from there. If IS_W_ALPHANUM, 
        // IS_W_STR, or IS_W_CHR are on and it's not the beginning, then don't skip, and just write alphanum at w_token position.
        tokens[(w_token+2*(start_to_alphanum == w_token))/8] |=   
            static_cast<uint64_t>((IS_W_ALPHANUM | IS_W_STR | IS_W_CHR)*tokens[ALPHANUM_BUFFER]) << (((w_token+2*(start_to_alphanum == w_token))%8)<<3);
/*temp*/ std::cout << "ALPHA IS BEING WRITTEN AT INDEX: " << ((w_token+2*(start_to_alphanum == w_token))/8) << std::endl;
/*temp*/ std::cout << "NUM BUFFER: " << NUM_BUFFER << std::endl;
   
        // While IS_W_ALPHANUM, IS_W_STR, or IS_W_CHR are on, increment the length stored at the beginning
        // of the alphanums after the Token. NOTE: For now, the same goes with Keywords and Chars although 
        // it's not needed since the lengths are already known. But this may change later.
        tokens[(start_to_alphanum+1)/8] += static_cast<uint64_t>(IS_W_ALPHANUM | IS_W_STR | IS_W_CHR) << (((start_to_alphanum+1)%8)*8);

        // Clear out buffer (NUM_BUFFER) after writing Number.
        tokens[NUM_BUFFER] = !IS_R_NUM*tokens[NUM_BUFFER];
        

     
/*temp*/std::cout << "tokens[w_token]3: " << tokens[w_token/8] << std::endl; 
/*temp*/std::cout << "tokens[w_token+2]: " << tokens[(w_token+2)/8] << std::endl; 
        

/*temp*/std::cout << "w_token2: " << w_token << std::endl;
        // Increment w_token by either 0 if no Token output, by 1 if there is a Token output, 
        // by 3 if either IS_W_ALPHANUM, IS_W_STR, or IS_W_CHR are on and it is the beginning 
        // of an alphanum, or by 7 if IS_W_NUM is on and it is the beginning of an alphanum. 
        // Incrementing by 3 is to account for the two bytes that are reserved for the Token 
        // and Length of VAR/KEYWORD, and 1 byte for the alphanum itself. Incrementing by 7
        // when IS_W_NUM is on is to account for the 1 byte reserved for NUM Token,and the 
        // 6 bytes reserved for the number (48 bit data type) itself. Incrementing by 4, 8,
        // 10, or 11 are not cases since (1) if start_to_alphanum equals w_token, then that
        // space is reserved and no ouput was written there,(2) IS_W_ALPHANUM, IS_W_CHR,
        // IS_W_STR, or IS_W_NUM are never on concurrently.
        w_token +=
            (
                ((tokens[w_token/8] & (static_cast<uint64_t>(0xFF) << ((w_token % 8) << 3))) != 0) + 
            
                ((start_to_alphanum == w_token)*(3*(IS_W_ALPHANUM | IS_W_STR | IS_W_CHR) + 7*IS_W_NUM))
            );
/*temp*/std::cout << "w_token3: " << w_token << std::endl; 
        
        // While IS_W_NUM is on, get the current number in ALPHANUM_BUFFER and compute the number in NUM_BUFFER.
        tokens[NUM_BUFFER] = 
             IS_W_NUM*(tokens[NUM_BUFFER] * 10 + (tokens[ALPHANUM_BUFFER] - '0')) +
            !IS_W_NUM*tokens[NUM_BUFFER];
/*temp*/std::cout << "NUM_BUFFER: " << tokens[NUM_BUFFER] << std::endl; 
        
    
        // Clear out input space and the space where alphanum was premptively stored since
        // i may be changed in next step. Input space needs to be cleared out since Token
        // space may overtake it. 
/*temp*/std::cout << "tokens[i]: " << tokens[i] << std::endl;     
        tokens[i] = 0x0; 
/*temp*/std::cout << "tokens[i+1]: " << tokens[i+1] << std::endl;        
        tokens[i+1] = 0x0;            
        // The "pointer" used for writing Tokens (w_token) should never catch up to the input "pointer" (i).
        // Such case will cause input (from getchar) to be written over Tokens and vice versa. Since one cycle 
        // can cause two Token outputs, and one output from the two may be a Number, for instance, that alone 
        // skips 8 bytes, i is always checked to be at least 3 spaces ahead of w_token for safety.
        i += (i <= 3+(w_token/8));
/*temp*/std::cout << "i: " << i << std::endl; 
           
//                     SET_R_CHR((IS_P20APOSTROPHE_OR_P21APOSTROPHE))
//                                                                                                        |
//                     SET_R_STR((IS_P22QUOTATION))
//                                                                                                        |
//                     SET_W_NUM((IS_NUMERAL & IS_NOT_P23_OR_P22_OR_P21_OR_P20_OR_P1))  
//                                                                                                        |
//                     SET_W_ALPHANUM((IS_UNDERSCORE_OR_ALPHABET & IS_NOT_P23_OR_P22_OR_P21_OR_P20))
//                                                                                                        |
//                     SET_NUM((IS_P2NOTNUMERAL))
//                                                                                                        |
//                     SET_R_ALPHANUM((IS_P1NOT_ALPHABET_OR_UNDERSCORE))                   
//                                                                                                        |
//                     SET_W_CHR((N21))
//                                                                                                        |
//                     SET_W_STR((IS_P22 & IS_NOT_QUOTATION))
//                                 
//                     SET_CHR((N20))                                   
//                                                                                                        |
//                     SET_STR((IS_QUOTATION & IS_NOT_P23_OR_P22_OR_P21_OR_P20))        
//                                                                                                        |        
        
        // Set new previous state to old next state.
        tokens[PREV_STATE] = tokens[NEXT_STATE];
               
/*temp*/std::cout << "===================================================== "  << std::endl;             
    }
                     
/*temp*/std::cout << "Tokens1: " << tokens[(W_TOKEN_INIT*8)/8] << std::endl; 
/*temp*/std::cout << "Tokens2: " << tokens[((W_TOKEN_INIT*8)/8)+1] << std::endl; 
/*temp*/std::cout << "Tokens3: " << tokens[((W_TOKEN_INIT*8)/8)+2] << std::endl; 
/*temp*/std::cout << "Tokens4: " << tokens[((W_TOKEN_INIT*8)/8)+3] << std::endl; 
 
}



