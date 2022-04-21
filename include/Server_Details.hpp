#ifndef INCLUDE_SERVER_DETAILS_HPP
#define INCLUDE_SERVER_DETAILS_HPP

#include <Server.hpp>
#include <set>


typedef std::set<
    conn_hdl,
    std::owner_less<conn_hdl>
> set_t;


struct Server::Details
{
    set_t clients;
};

#endif // INCLUDE_SERVER_DETAILS_HPP
