/*
 * lexer_token.h
 *
 *  Created on: Aug 12, 2008
 *      Author: Victor Costan
 */

#ifndef __LEXER_TOKEN_H_
#define __LEXER_TOKEN_H_

#include <string>

namespace sushi {

class LexerToken {
public:
	enum Type {
		// shouldn't come out of the lexer
		kInvalid,
		// an identifier (keyword, variable name, etc.)
		kIdentifier,
		// a number literal
		kNumber,
		// a string literal
		kString,
		// the newline (you guessed it)
		kNewline,
		// whitespace (used internally, shouldn't come out of the lexer)
		kWhitespace,
		// the end of stream
		kEos
	};

	Type type() { return type_; }

	size_t start_line() { return start_line_; }
	size_t start_char() { return start_char_; }

private:
  size_t start_line_;
  size_t start_char_;
	Type type_;
};

} // namespace sushi

#endif /* __LEXER_TOKEN_H_ */
