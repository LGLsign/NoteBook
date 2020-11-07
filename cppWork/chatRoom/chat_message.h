#ifndef CHAT_MESSAGE_H
#define CHAT_MESSAGE_H

#include "structHeader.h"
#include "serilizationObject.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

class chat_message {
public:
	enum { header_length = sizeof(Header) };
	enum { max_body_length = 512 };

	chat_message(){}

	const char* data() const { return data_; }
	char* data() { return data_; }

	std::size_t length() const { return header_length + m_header.bodySize; }
	std::size_t body_length() const { return m_header.bodySize;}

	const char* body() const { return data_ + header_length; }
	char* body() { return data_ + header_length; }

	int type() const { return m_header.Type;}

	void setMessage(int msgType, const void* buffer, size_t bufSize) {
		assert(bufSize <= max_body_length);
		m_header.bodySize = bufSize;
		m_header.Type = msgType;
		std::memcpy(body(), buffer, bufSize);
		std::memcpy(data(), &m_header, sizeof(m_header));
	}

    void setMessage (int msgType, const std::string& buffer) {
        setMessage(msgType, buffer.data(), buffer.size());
    }

	bool decode_header() {
		std::memcpy(&m_header, data(), header_length);
		if (m_header.bodySize > max_body_length) {
			return false;
		}
		return true;
	}

private:
	char data_[header_length + max_body_length];
	Header m_header;
};

#endif

