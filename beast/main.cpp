#include "server/http_connection.h"
#include "services/config/aws/appconfig.h"
#include "services/config/aws/init.h"
#include "services/database/postgresql/pq.h"
#include <boost/asio.hpp>
#include <boost/beast/http.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <spdlog/spdlog.h>

namespace beast = boost::beast;   // from <boost/beast.hpp>
namespace http = beast::http;     // from <boost/beast/http.hpp>
namespace net = boost::asio;      // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp; // from <boost/asio/ip/tcp.hpp>

// "Loop" forever accepting new connections.
void http_server(tcp::acceptor &acceptor, tcp::socket &socket) {
  acceptor.async_accept(socket, [&](beast::error_code ec) {
    if (!ec)
      std::make_shared<http_connection>(std::move(socket))->start();
    http_server(acceptor, socket);
  });
}

int main(int argc, char *argv[]) {
  #ifndef NDEBUG
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
  #endif
  spdlog::debug("Hello, {}", "World!");
//  std::cout << "Hello, World!" << std::endl;
  initAws();
  initConfig();

  try {
    auto address_str = "0.0.0.0";
    auto port_str = "3500";
    char *p_end;
    auto const address = net::ip::make_address(address_str);
    auto port = static_cast<unsigned short>(std::strtol(port_str, &p_end, 10));

    net::io_context ioc{1};

    tcp::acceptor acceptor{ioc, {address, port}};
    tcp::socket socket{ioc};
    http_server(acceptor, socket);

    ioc.run();
  } catch (std::exception const &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
}
