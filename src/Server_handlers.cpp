#include <iostream>
using namespace std;

#include <Server.hpp>
#include <Server_Details.hpp>


void Server::init_details()
{
    details = std::make_shared<Details>();
}

void Server::on_open(conn_hdl hdl)
{
    details->clients.insert(hdl);
}

void Server::on_close(conn_hdl hdl)
{
    details->clients.erase(hdl);
}

void Server::on_message(conn_hdl hdl, msg_ptr msg)
{
    auto self = hdl.lock();
    for(auto it : details->clients)
    {
        auto other = it.lock();
        if(self != other)
            endpoint.send(it, msg);
    }
}

