#include "client.h"
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

Client::Client() {
    this->ip = "127.0.0.1";
    this->PORT = 12345;
}
/*
int Client::connectToServer() {
    if ((this->clientSock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Creating socket error");
        return 1;
    }

    this->serverAddr.sin_family = AF_INET;
    this->serverAddr.sin_addr.s_addr = inet_addr(this->ip);
    this->serverAddr.sin_port = this->PORT;

    int connectResult = connect(this->clientSock, (struct sockaddr*)&(this->serverAddr), sizeof(this->serverAddr));
    if (connectResult == -1) {
        perror("Connecting error");
        close(this->clientSock);
        return 1;
    }

    std::cout << "Połączono z serwerem." << std::endl;

    close(this->clientSock);

    return 0;
}*/
int Client::connectToServer() {
    // Tworzenie gniazda
    if ((this->clientSock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Creating socket error");
        return 1;
    }

    // Konfiguracja adresu serwera
    this->serverAddr.sin_family = AF_INET;
    this->serverAddr.sin_port = htons(this->PORT); // Konwersja portu do odpowiedniego formatu sieciowego
    this->serverAddr.sin_addr.s_addr = inet_addr(this->ip); // Ustawienie adresu IP serwera

    // Sprawdzenie poprawności adresu IP
    if (this->serverAddr.sin_addr.s_addr == INADDR_NONE) {
        perror("Invalid address");
        close(this->clientSock);
        return 1;
    }

    // Nawiązywanie połączenia
    if (connect(this->clientSock, (struct sockaddr*)&(this->serverAddr), sizeof(this->serverAddr)) == -1) {
        perror("Connecting error");
        close(this->clientSock);
        return 1;
    }

    std::cout << "Połączono z serwerem." << std::endl;

    // Tutaj można umieścić kod obsługi komunikacji z serwerem, jeśli to konieczne

    // Zamknięcie gniazda po zakończeniu komunikacji
    //close(this->clientSock);

    return 0;
}

/*int Client::connectToServer() {
    // Tworzenie gniazda
    if ((this->clientSock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Creating socket error");
        return 1;
    }

    // Konfiguracja adresu serwera
    this->serverAddr.sin_family = AF_INET;
    this->serverAddr.sin_port = htons(this->PORT); // Konwersja portu do odpowiedniego formatu sieciowego
    if (inet_pton(AF_INET, this->ip, &this->serverAddr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(this->clientSock);
        return 1;
    }

    // Nawiązywanie połączenia
    if (connect(this->clientSock, (struct sockaddr*)&(this->serverAddr), sizeof(this->serverAddr)) == -1) {
        perror("Connecting error");
        close(this->clientSock);
        return 1;
    }

    std::cout << "Połączono z serwerem." << this->clientSock << std::endl;

    return 0;
}*/

void Client::disconnectFromServer() {
    //shutdown(this->clientSock, SHUT_RDWR);
    close(this->clientSock);
    std::cout << "Disconnected from server " << this->clientSock << std::endl;
}

int Client::addToQueue(string songName) {
    if (send(this->clientSock, "ADD QUEUE POLAND-LILYACHTY", 27, 0) == -1) {
        perror("Sending request failed");
        close(this->clientSock);
        return 1;
    }

    return 0;
}
