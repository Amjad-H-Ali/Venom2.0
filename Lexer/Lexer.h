#include <stdint.h>

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

uint64_t lexer(uint64_t* tokens);