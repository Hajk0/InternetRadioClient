#ifndef CLIENT_H
#define CLIENT_H

#include "sender.h"
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

class Client
{
private:
    int clientSock;
    sockaddr_in serverAddr{};
    int PORT = 12345;
    const char* ip = "192.168.75.41";


public:
    Client();
    int connectToServer();
    void disconnectFromServer();
    int addToQueue(string);
    int skipSong();
    string getAvaiableSongs();
    int sendSong(string songPath);
    //int connectToServerQT();
};

#endif // CLIENT_H
