#include "structHeader.h"
#include "serilizationObject.h"
#include "JsonObject.h"
#include "Protocal.pb.h"

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cstring>

template<typename T>
std::string seriliaze(const T& obj) {
    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << obj;
    return ss.str();
}

bool parseMessage(const std::string& input, int* type, std::string& outBuffer) {
    auto pos = input.find_first_of(" ");
    if (pos == std::string::npos)
        return false;
    if (pos == 0)
        return false;

    auto command = input.substr(0, pos);
    if (command == "BindName") {
        std::string name = input.substr(pos + 1);
        if (name.size() > 32)
            return false;
        if (type)
            *type = MT_BIND_NAME;
        BindName bindInfo;
        bindInfo.nameLen = name.size();
        std::memcpy(&(bindInfo.name), name.data(), name.size());
        auto buffer = reinterpret_cast<const char*>(&bindInfo);
        outBuffer.assign(buffer, buffer + sizeof(bindInfo));
        return true;
    }
    else if (command == "Chat") {
        std::string chat = input.substr(pos + 1);
        if (chat.size() > 256)
            return false;
        ChatInfo info;
        info.infoLen = chat.size();
        std::memcpy(&(info.info), chat.data(), chat.size());
        auto buffer = reinterpret_cast<const char*>(&info);
        outBuffer.assign(buffer, buffer + sizeof(info));
        if (type)
            *type = MT_CHAT_INFO;
        return true;
    }
    return false;
}
        
bool parseMessage2(const std::string& input, int* type, std::string& outBuffer) {
    auto pos = input.find_first_of(" ");
    if (pos == std::string::npos)
        return false;
    if (pos == 0) 
        return false;
    auto cmd = input.substr(0, pos);
    if (cmd == "BindName") {
        std::string name = input.substr(pos + 1);
        if (name.size() > 32)
            return false;
        if (type)
            *type = MT_BIND_NAME;
        outBuffer = seriliaze(SBindName(std::move(name)));
        return true;
    }
    else if (cmd == "Chat") {
        std::string chat = input.substr(pos + 1);
        if (chat.size() > 256)
            return false;
        outBuffer = seriliaze(SChatInfo(std::move(chat)));
        if (type)
            *type = MT_CHAT_INFO;
        return true;
    }
    return false;
}

bool parseMessage3(const std::string& input, int* type, std::string& outBuffer) {
    auto pos = input.find_first_of(" ");
    if (pos == std::string::npos)
        return false;
    if (pos == 0)
        return false;
    
    auto cmd = input.substr(0, pos);
    if (cmd == "BindName") {
        std::string name = input.substr(pos + 1);
        if (name.size() > 32)
            return false;
        if (type)
            *type = MT_BIND_NAME;
        ptree tree;
        tree.put("name", name);
        outBuffer = ptreeToJsonString(tree);
        return true;
    }
    else if (cmd == "Chat") {
        std::string chat = input.substr(pos + 1);
        if (chat.size() > 256)
            return false;
        if (type)
            *type = MT_CHAT_INFO;
        ptree tree;
        tree.put("information", chat);
        outBuffer = ptreeToJsonString(tree);
        return true;
    }
    else {
    }
    return false;
}
bool parseMessage4(const std::string& input, int* type, std::string& outBuffer) {
     auto pos = input.find_first_of(" ");
    if (pos == std::string::npos)
        return false;
    if (pos == 0)
        return false;
    
    auto cmd = input.substr(0, pos);
    if (cmd == "BindName") {
        std::string name = input.substr(pos + 1);
        if (name.size() > 32)
            return false;
        if (type)
            *type = MT_BIND_NAME;
        PBindName bindName;
        bindName.set_name(name);
        auto ok = bindName.SerializeToString(&outBuffer);
        return ok;
    }
    else if (cmd == "Chat") {
        std::string chat = input.substr(pos + 1);
        if (chat.size() > 256)
            return false;
        if (type)
            *type = MT_CHAT_INFO;
        PChat pchat;
        pchat.set_info(chat);
        auto ok = pchat.SerializeToString(&outBuffer);
        return ok;
    }
    else {
    }
    return false;
}
