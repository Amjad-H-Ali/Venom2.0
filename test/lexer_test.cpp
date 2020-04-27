#include "../Lexer/Lexer.cpp"
#include <gtest/gtest.h>

 

TEST(LexerTest, PositiveNumbers) { 
    
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

TEST(LexerTest, NumbersAndVariables) { 
    
    uint64_t tokens[SIZE] = {0};
    uint64_t end_of_tokens_list = lexer(tokens);
    
    ASSERT_EQ(13, end_of_tokens_list);
    
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
        (static_cast<uint64_t>(VAR) << 24) | (static_cast<uint64_t>(0xc) << 32) | (static_cast<uint64_t>('b') << 40) |
        (static_cast<uint64_t>('o') << 48) | (static_cast<uint64_t>('n') << 56);
    
    test_tokens[W_TOKEN_INIT+9] =
        // continued...
        'g' | (static_cast<uint64_t>('o') << 8) | (static_cast<uint64_t>('1') << 16) | (static_cast<uint64_t>('2') << 24) |
        (static_cast<uint64_t>('3') << 32) | (static_cast<uint64_t>('b') << 40) | (static_cast<uint64_t>('a') << 48) |
        (static_cast<uint64_t>('n') << 56);
    
    test_tokens[W_TOKEN_INIT+10] =
        // continued...
        'g';
    
    for(size_t i = W_TOKEN_INIT; i < end_of_tokens_list; ++i) {
        EXPECT_EQ(test_tokens[i], tokens[i]) << std::hex << "test_tokens[i]: " << test_tokens[i] << '\n' << "tokens[i]: " << tokens[i];
    }

}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}