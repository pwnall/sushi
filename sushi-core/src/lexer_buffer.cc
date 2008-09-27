#include "lexer_buffer.h"

namespace sushi {

LexerBuffer::LexerBuffer(std::wistream *in_stream, wchar_t eos_ch) :
	buffer_(), eos_ch_(eos_ch), in_stream_(in_stream) {

	seen_eos_ = in_stream_->eof();
}

wchar_t LexerBuffer::read_char() {
	wchar_t ch; // the character to be returned
	if(buffer_.empty() == false) {
		ch = buffer_.back();
		buffer_.pop_back();
	}
	else if(seen_eos_ == false) {
		ch = in_stream_->get();
		seen_eos_ = in_stream_->eof();
	  if(ch == -1)
	    ch = eos_ch_;
	}
	else
		ch = eos_ch_;

	return ch;
}

// "Unreads" a previously read character.
void LexerBuffer::unread_char(wchar_t ch) {
	seen_eos_ = false;
	buffer_.push_back(ch);
}

bool LexerBuffer::eos() {
	return seen_eos_;
}

} // namespace sushi
