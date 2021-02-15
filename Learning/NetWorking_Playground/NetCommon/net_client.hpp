#include "net_common.hpp"
#include "net_connection.hpp"
#include "net_message.hpp"
#include "net_tsqueue.hpp"

namespace olc {
namespace net {
template <typename T> class client_interface {
public:
  client_interface() : m_socket(m_context) {}
  ~client_interface() { Disconnect(); }
  bool Connect(std::string &url, const uint16_t port) {
    try {
      // resolver se giup phan giai ten mien thanh dia chi ip
      asio::ip::tcp::resolver resolver(m_context);
      asio::ip::tcp::resolver::result_type endpoints =
          resolver.resolve(url, std::to_string(port));

      // create connection
      m_connection = std::make_unique<connection<T>>(); // TODO

      m_connection->ConnectToServer(endpoints);
      // Start context thread
      thrContext = std::thread([this]() { m_context.run(); });
    } catch (std::exception &e) {
      std::cerr << "Client Exception: " << e.what() << '\n';
      return false;
    }
    return true;
  }

  void Disconnect() {
    if(IsConneced()) {
      m_connection->Disconnect();
    }
    m_context.stop();
    if(thrContext.joinable())
      thrContext.join();
    
    m_connection.release();
  }

  bool isConnected() {
    if (m_connection)
      return m_connection->IsConnected();
    else
      return false;
  }

  ts_queue<owned_message<T>> &Incoming() { return m_qMessageIn; }

protected:
  asio::io_context m_context;
  // need a thread of context to execute work command;
  std::thread thrContext;
  asio::ip::tcp::socket m_socket;
  std::unique_ptr<connection<T>> m_connection;

private:
  ts_queue<owned_message<T>> m_qMessageIn;
};
} // namespace net
} // namespace olc