#include "../Lexer/Lexer.cpp"
#include <gtest/gtest.h>

 

TEST(LexerNumberTest, PositiveNumbers) { 
    
    uint64_t tokens[SIZE] = {0};
    uint64_t end_of_tokens_list = lexer(tokens);
    
    ASSERT_EQ(7, end_of_tokens_list);
    
    uint64_t test_tokens[SIZE]  = {0};
    // Testing the following numbers:
    // 123 100000000 281474976710655 0 1
    test_tokens[W_TOKEN_INIT]   = (static_cast<uint64_t>(NUM) << 56) | static_cast<uint64_t>(0x7B00) | NUM;
    test_tokens[W_TOKEN_INIT+1] = (static_cast<uint64_t>(0xFF) << 56)|(static_cast<uint64_t>(NUM) << 48) | 0x5f5e100;
    test_tokens[W_TOKEN_INIT+2] = (static_cast<uint64_t>(NUM) << 40) | static_cast<uint64_t>(0xFFFFFFFFFF);
    test_tokens[W_TOKEN_INIT+3] = (static_cast<uint64_t>(0x1) << 40) | (static_cast<uint64_t>(NUM) << 32) | 0x0 ;
    test_tokens[W_TOKEN_INIT+4] = 0;
    
    for(size_t i = W_TOKEN_INIT; i < end_of_tokens_list; ++i) {
        EXPECT_EQ(test_tokens[i], tokens[i]) << std::hex << "test_tokens[i]: " << test_tokens[i] << '\n' << "tokens[i]: " << tokens[i];
    }

}

TEST(LexerNumberTest, NumbersAndVariables) { 
    
    uint64_t tokens[SIZE] = {0};
    uint64_t end_of_tokens_list = lexer(tokens);
    
    ASSERT_EQ(19, end_of_tokens_list);
    
    std::vector<uint64_t> test_tokens(SIZE, 0);
    
    test_tokens[W_TOKEN_INIT]   =   
        // foo999 == VAR
        VAR | (static_cast<uint64_t>(0x06) << 8) | (static_cast<uint64_t>('f') << 16) |
        
       (static_cast<uint64_t>('o') << 24) | (static_cast<uint64_t>('o') << 32) | (static_cast<uint64_t>('9') << 40) |
      
       (static_cast<uint64_t>('9') << 48) | (static_cast<uint64_t>('9') << 56);
   
    test_tokens[W_TOKEN_INIT+1] = 
        // 999foo == NUM, VAR
        NUM | (static_cast<uint64_t>(0x3e7) << 8) | (static_cast<uint64_t>(VAR) << 56);
             
    test_tokens[W_TOKEN_INIT+2] =  
        // continued...
        0x03 | (static_cast<uint64_t>('f') << 8) |
                                
       (static_cast<uint64_t>('o') << 16) | (static_cast<uint64_t>('o') << 24) |
        
        // 281474976710655bar == NUM, VAR
       (static_cast<uint64_t>(NUM) << 32) | static_cast<uint64_t>(0xFFFFFF) << 40;
    
    test_tokens[W_TOKEN_INIT+3] =
        // continued...
        0xFFFFFF | (static_cast<uint64_t>(VAR) << 24) | (static_cast<uint64_t>(0x3) << 32) |
       (static_cast<uint64_t>('b') << 40) | (static_cast<uint64_t>('a') << 48) | (static_cast<uint64_t>('r') << 56);
    
    test_tokens[W_TOKEN_INIT+4] =
        // qux281474976710655 == VAR
        VAR | (static_cast<uint64_t>(0x12) << 8) | (static_cast<uint64_t>('q') << 16) | (static_cast<uint64_t>('u') << 24) |
        (static_cast<uint64_t>('x') << 32) | (static_cast<uint64_t>('2') << 40) | (static_cast<uint64_t>('8') << 48) | 
        (static_cast<uint64_t>('1') << 56);
    
    test_tokens[W_TOKEN_INIT+5] = 
        // continued...
        '4' | (static_cast<uint64_t>('7') << 8) | (static_cast<uint64_t>('4') << 16) | (static_cast<uint64_t>('9') << 24) |
        (static_cast<uint64_t>('7') << 32) | (static_cast<uint64_t>('6') << 40) | (static_cast<uint64_t>('7') << 48) |
        (static_cast<uint64_t>('1') << 56);
    
    test_tokens[W_TOKEN_INIT+6] = 
        // continued...
        '0' | (static_cast<uint64_t>('6') << 8) | (static_cast<uint64_t>('5') << 16) | (static_cast<uint64_t>('5') << 24) |
        // 777baz777 == NUM, VAR
        (static_cast<uint64_t>(NUM) << 32) | (static_cast<uint64_t>(0x309) << 40);
    
    test_tokens[W_TOKEN_INIT+7] =
        // continued...
        (static_cast<uint64_t>(VAR) << 24) | (static_cast<uint64_t>(0x6) << 32) | (static_cast<uint64_t>('b') << 40) |
        (static_cast<uint64_t>('a') << 48) | (static_cast<uint64_t>('z') << 56);
    
    test_tokens[W_TOKEN_INIT+8] = 
        // continued...
        '7' | (static_cast<uint64_t>('7') << 8) | (static_cast<uint64_t>('7') << 16) |
        // bongo123bang == VAR
        (static_cast<uint64_t>(VAR) << 24) | (static_cast<uint64_t>(0xC) << 32) | (static_cast<uint64_t>('b') << 40) |
        (static_cast<uint64_t>('o') << 48) | (static_cast<uint64_t>('n') << 56);
    
    test_tokens[W_TOKEN_INIT+9] =
        // continued...
        'g' | (static_cast<uint64_t>('o') << 8) | (static_cast<uint64_t>('1') << 16) | (static_cast<uint64_t>('2') << 24) |
        (static_cast<uint64_t>('3') << 32) | (static_cast<uint64_t>('b') << 40) | (static_cast<uint64_t>('a') << 48) |
        (static_cast<uint64_t>('n') << 56);
    
    test_tokens[W_TOKEN_INIT+10] =
        // continued...
        'g' |
        // camelCasing == VAR
        (static_cast<uint64_t>(VAR) << 8) | (static_cast<uint64_t>(0xB) << 16) | (static_cast<uint64_t>('c') << 24) |
        (static_cast<uint64_t>('a') << 32) | (static_cast<uint64_t>('m') << 40) | (static_cast<uint64_t>('e') << 48) |
        (static_cast<uint64_t>('l') << 56);
    
    test_tokens[W_TOKEN_INIT+11] = 
        // continued...
        'C' | (static_cast<uint64_t>('a') << 8) | (static_cast<uint64_t>('s') << 16) | (static_cast<uint64_t>('i') << 24) |
        (static_cast<uint64_t>('n') << 32) | (static_cast<uint64_t>('g') << 40) |
        // _under_scored_7_77_ == VAR
        (static_cast<uint64_t>(VAR) << 48) | (static_cast<uint64_t>(0x13) << 56);
    
    test_tokens[W_TOKEN_INIT+12] =
        // continued...
        '_' | (static_cast<uint64_t>('u') << 8) | (static_cast<uint64_t>('n') << 16) | (static_cast<uint64_t>('d') << 24) |
        (static_cast<uint64_t>('e') << 32) | (static_cast<uint64_t>('r') << 40) | (static_cast<uint64_t>('_') << 48) |
        (static_cast<uint64_t>('s') << 56);
    
    test_tokens[W_TOKEN_INIT+13] = 
        // continued...
        'c' | (static_cast<uint64_t>('o') << 8) | (static_cast<uint64_t>('r') << 16) | (static_cast<uint64_t>('e') << 24) |
        (static_cast<uint64_t>('d') << 32) | (static_cast<uint64_t>('_') << 40) | (static_cast<uint64_t>('7') << 48) |
        (static_cast<uint64_t>('_') << 56);
   
    test_tokens[W_TOKEN_INIT+14] =
        // continued...
        '7' | (static_cast<uint64_t>('7') << 8) | (static_cast<uint64_t>('_') << 16) |
        // 777_ == NUM, VAR
        (static_cast<uint64_t>(NUM) << 24) | (static_cast<uint64_t>(0x309) << 32);
    
    test_tokens[W_TOKEN_INIT+15] =
        // continued...
        (static_cast<uint64_t>(VAR) << 16) | (static_cast<uint64_t>(0x1) << 24) | (static_cast<uint64_t>('_') << 32) |
        // _0 == VAR
        (static_cast<uint64_t>(VAR) << 40) | (static_cast<uint64_t>(0x2) << 48) | (static_cast<uint64_t>('_') << 56);
    
    test_tokens[W_TOKEN_INIT+16]=
        // continued...
        '0';
        
    for(size_t i = W_TOKEN_INIT; i < end_of_tokens_list; ++i) {
        EXPECT_EQ(test_tokens[i], tokens[i]) << std::hex << "test_tokens[i]: " << test_tokens[i] << '\n' << "tokens[i]: " << tokens[i];
    }

}

TEST(LexerNumberTest, NumbersAndOperators) { 
    
    uint64_t tokens[SIZE] = {0};
    uint64_t end_of_tokens_list = lexer(tokens);
    
    ASSERT_EQ(4, end_of_tokens_list);
    
    std::vector<uint64_t> test_tokens(SIZE, 0);

    test_tokens[W_TOKEN_INIT] =
        // ++97 == INC, NUM
        INC | (static_cast<uint64_t>(NUM) << 8) | (static_cast<uint64_t>(0x61) << 16);
    
    for(size_t i = W_TOKEN_INIT; i < end_of_tokens_list; ++i) {
        EXPECT_EQ(test_tokens[i], tokens[i]) << std::hex << "test_tokens[i]: " << test_tokens[i] << '\n' << "tokens[i]: " << tokens[i];
    }

}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}