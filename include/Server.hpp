#ifndef INCLUDE_SERVER_HPP
#define INCLUDE_SERVER_HPP

#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <string>
#include <memory>

using conn_hdl = websocketpp::connection_hdl;
using websocketpp::lib::bind;
using std::string;
using std::shared_ptr;


class Server
{
public:
    Server();
    ~Server();

    void run(uint16_t);
    void stop();

    typedef websocketpp::config::asio config;
    typedef websocketpp::server<config> server_t;
    typedef server_t::message_ptr msg_ptr;

private:
    server_t endpoint;
    struct Details;
    shared_ptr<Details> details;

    void init_details();

    void on_open(conn_hdl);
    void on_close(conn_hdl);
    void on_message(conn_hdl, msg_ptr);

};

#endif // INCLUDE_SERVER_HPP
