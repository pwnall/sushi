/*
 * lexer_buffer.h
 *
 *  Created on: Aug 12, 2008
 *      Author: Victor Costan
 */

#ifndef __LEXER_BUFFER_H_
#define __LEXER_BUFFER_H_

#include <istream>
#include <vector>

namespace sushi {

// Buffers data
class LexerBuffer {
public:
	// Creates a lexer buffer feeding off the given input stream.
	// The buffer will start returning eos_ch when the end-of-stream is reached.
	// The caller retains ownership of the stream.
	LexerBuffer(std::wistream *in_stream, wchar_t eos_ch);

	// Reads a character from the buffer.
	wchar_t read_char();

	// "Unreads" a previously read character.
	void unread_char(wchar_t ch);

	// Indicates if the end-of-stream has been reached.
	bool eos();

	// The character returned by read_char() upon end-of-stream.
	static const wchar_t kEofChar = '\0';

private:
	// holds the characters pushed back in
	std::vector<wchar_t> buffer_;
	// the character to be returned for end-of-stream
	wchar_t eos_ch_;
	// input source
	std::wistream *in_stream_;
	// set when end-of-stream is encountered
	bool seen_eos_;
};

} // namespace sushi

#endif /* __LEXER_BUFFER_H_ */
