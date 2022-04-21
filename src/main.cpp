#include <iostream>
#include <csignal>
#include "Server.hpp"

using namespace std;

static Server server;
static void on_signal(int);

int main(int, char**)
{
    signal(SIGINT, &on_signal);

    cout << "Listening on 9002" << endl;
    server.run(9002);
    cout << "Exiting" << endl;

    return 0;
}

void on_signal(int)
{
    server.stop();
}
