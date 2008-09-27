#include <sstream>

#include "../src/lexer_buffer.h"

#include "test_suite.h"

TEST(LexerBufferCanReadChars) {
  std::wistringstream ts(L"sushi");
  sushi::LexerBuffer buf(&ts, '\0');

  EXPECT_EQ('s', buf.read_char());
  EXPECT_EQ('u', buf.read_char());
  EXPECT_EQ('s', buf.read_char());
  EXPECT_EQ('h', buf.read_char());
  EXPECT_EQ('i', buf.read_char());
  return;
}

TEST(LexerBufferReportsEos) {
  std::wistringstream ts(L"sushi");
  sushi::LexerBuffer buf(&ts, '\0');
  for(size_t i = 0; i < 5; i++) {
    buf.read_char();
    EXPECT(!buf.eos());
  }
  EXPECT_EQ('\0', buf.read_char());
  EXPECT(buf.eos());
  return;
}

TEST(LexerBufferCanUnwindChars) {
  std::wistringstream ts(L"sushi");
  sushi::LexerBuffer buf(&ts, '\0');

  EXPECT_EQ('s', buf.read_char());
  EXPECT_EQ('u', buf.read_char());
  buf.unread_char('u');
  buf.unread_char('s');
  EXPECT_EQ('s', buf.read_char());
  EXPECT_EQ('u', buf.read_char());
  EXPECT_EQ('s', buf.read_char());
  EXPECT_EQ('h', buf.read_char());
  buf.unread_char('h');
  EXPECT_EQ('h', buf.read_char());
  EXPECT_EQ('i', buf.read_char());
  return;
}
