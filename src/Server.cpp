#include <Server.hpp>

Server::Server()
{
    auto error_ch = websocketpp::log::elevel::all;
    auto access_ch = websocketpp::log::elevel::all
            ^ websocketpp::log::alevel::frame_payload;

    this->endpoint.set_error_channels(error_ch);
    this->endpoint.set_access_channels(access_ch);

    using namespace std::placeholders;

    endpoint.init_asio();
    endpoint.set_open_handler(
        bind(&Server::on_open, this, _1));
    endpoint.set_close_handler(
        bind(&Server::on_close, this, _1));
    endpoint.set_message_handler(
        bind(&Server::on_message, this, _1, _2));

    init_details();
}

Server::~Server()
{
}

void Server::run(uint16_t port)
{
    endpoint.listen(port);
    endpoint.start_accept();
    endpoint.run();
}

void Server::stop()
{
    endpoint.stop_listening();
}
