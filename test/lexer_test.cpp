#include "../Lexer/Lexer.cpp"
#include <gtest/gtest.h>
 

TEST(LexerTest, PositiveNumbers) { 
    
    uint64_t tokens[SIZE] = {0};
    uint64_t end_of_tokens_list = lexer(tokens);
    
    uint64_t test_tokens[SIZE]  = {0};
    test_tokens[W_TOKEN_INIT]   = (static_cast<uint64_t>(NUM) << 56) | static_cast<uint64_t>(0x7B00) | NUM;
    test_tokens[W_TOKEN_INIT+1] = (static_cast<uint64_t>(0xFF) << 56)|(static_cast<uint64_t>(NUM) << 48) | 0x5f5e100;
    test_tokens[W_TOKEN_INIT+2] = (static_cast<uint64_t>(NUM) << 40) | static_cast<uint64_t>(0xFFFFFFFFFF);
    test_tokens[W_TOKEN_INIT+3] = (static_cast<uint64_t>(0x1) << 40) | (static_cast<uint64_t>(NUM) << 32) | 0x0 ;
    test_tokens[W_TOKEN_INIT+4] = 0;
    
    for(size_t i = W_TOKEN_INIT; i < end_of_tokens_list; ++i) {
        ASSERT_EQ(test_tokens[i], tokens[i]) << std::hex << "test_tokens[i]: " << test_tokens[i] << '\n' << "tokens[i]: " << tokens[i];
    }
    

}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}