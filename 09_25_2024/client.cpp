#include "PracticalSocket.h"
#include <iostream>
#include <limits>

void resetStream();

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./client <server host>" << std::endl;
        return 1;
    }

    try
    {
        std::cout << argv[1] << std::endl;
        TCPSocket sock(argv[1], 9431);
        int input = 0;
        std::cout << "Enter the starting number: ";
        std::cin >> input;
        while (!std::cin)
        {
            resetStream();
            std::cout << "Enter the starting number: ";
            std::cin >> input;
        }
        uint32_t val = static_cast<uint32_t>(input);
        val = htonl(val);
        sock.send(&val, sizeof(val));
        if (sock.recvFully(&val, sizeof(val)) == sizeof(val))
        {
            val = ntohl(val);
            std::cout << "Server Reponse: " << val << std::endl;
        }
    }
    catch (SocketException e)
    {
        std::cerr << e.what() << '\n';
    }
}

void resetStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}