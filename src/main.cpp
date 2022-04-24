#include <iostream>
#include <csignal>
#include "Server.hpp"

using namespace std;

static Server server;
static void on_signal(int);

int main(int, char**)
{
    signal(SIGINT, &on_signal);

    uint16_t port = 9091;
    cout << "Listening on " << port << endl;
    server.run(port);
    cout << "Exiting" << endl;

    return 0;
}

void on_signal(int)
{
    server.stop();
}
