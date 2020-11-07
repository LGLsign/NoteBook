chatServer:*.h chatServer.cpp structHeader.cpp Protocal.pb.cc
	g++ -O2 -std=c++14 -o server chatServer.cpp structHeader.cpp Protocal.pb.cc -lboost_system -lboost_serialization -lpthread -lprotobuf -L/usr/local/protobuf/lib

chatClient:*.h chatClient.cpp structHeader.cpp Protocal.pb.cc
	g++ -O2 -std=c++14 -o client chatClient.cpp structHeader.cpp Protocal.pb.cc -lboost_system -lpthread -lboost_serialization -lprotobuf -L/usr/local/protobuf/lib

clean:
	rm server client
