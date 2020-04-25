#include "../Lexer/Lexer.cpp"
#include <gtest/gtest.h>
 

TEST(LexerTest, PositiveNumbers) { 
    
    uint64_t tokens[SIZE] = {0};
    uint64_t end_of_tokens_list = lexer(tokens);
    
    uint64_t test_tokens[SIZE] = {0};
    test_tokens[W_TOKEN_INIT] = 0x7B00 | NUM;
    
    for(size_t i = W_TOKEN_INIT; i < end_of_tokens_list; ++i) {
        ASSERT_EQ(tokens[i],test_tokens[i]);
    }
    

}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}