#include "PracticalSocket.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::string processString(std::string);
// add 3 string input response pairs to the static map

int main(int argc, char *argv[])
{
    try
    {
        TCPServerSocket servSock(9431);
        for (;;)
        {
            TCPSocket *sock = servSock.accept();
            uint32_t val;
            if (sock->recvFully(&val, sizeof(val)) == sizeof(val))
            {
                val = ntohl(val);
                std::cout << "receiving " << val << " bytes:" << std::endl;
                char *buffer = new char[val + 1];
                if (sock->recvFully(buffer, val) == val)
                {
                    buffer[val] = '\0';
                    std::string input(buffer);
                    std::string response = processString(input);
                    std::cout << "received: " << input << std::endl;
                    val = htonl(response.length());
                    sock->send(&val, sizeof(val));
                    sock->send(response.c_str(), response.length());
                }
                delete[] buffer;
            }
            delete sock;
        }
    }
    catch (SocketException e)
    {
        std::cerr << e.what() << '\n';
    }
}

std::string processString(std::string inStr)
{
    static std::map<std::string, std::string> strMap = {{"hello world", "Goodbye"},
                                                        {"how are you?", "OK"},
                                                        {"is the weather nice today?", "No"},
                                                        {"goodbye", "Have a nice day!"}};
    std::transform(inStr.begin(), inStr.end(), inStr.begin(), ::tolower);
    if (strMap.count(inStr))
    {
        return strMap[inStr];
    }
    else
    {
        strMap[inStr] = "I don't know what to say.";
        return inStr;
    }
}