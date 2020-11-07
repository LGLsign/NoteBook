#ifndef STRUCT_HEADER_H
#define STRUCT_HEADER_H

#include <string>

enum MessageType {

	MT_BIND_NAME = 1,
	MT_CHAT_INFO = 2,
	MT_ROOM_INFO = 3

};

struct Header {
	int bodySize;
	int Type;
};

struct BindName {
	char name[32];
	int nameLen;
};

struct ChatInfo {
	char info[256];
	int infoLen;
};

struct RoomInfo {
	BindName name;
	ChatInfo chat;
};

bool parseMessage(const std::string& input, int* type, std::string& outBuffer);
bool parseMessage2(const std::string& input, int* type, std::string& outBuffer);
bool parseMessage3(const std::string& input, int* type, std::string& outBuffer);
bool parseMessage4(const std::string& input, int* type, std::string& outBuffer);

#endif
