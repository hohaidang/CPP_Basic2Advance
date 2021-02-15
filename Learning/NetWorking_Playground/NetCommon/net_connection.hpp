#include "net_common.hpp"
#include "net_message.hpp"
#include "net_tsqueue.hpp"

namespace olc {
namespace net {
template <typename T>
class connection : std::enable_shared_from_this<connection<T>> {
public:
  connection() {}
  virtual ~connection() {}

public:
  bool ConnectToServer();
  bool Disconnect();
  bool IsConnected() const;

public:
  bool Send(const message<T> &msg);

protected:
  // each connection has a unique socket to remote
  asio::ip::tcp::socket m_socket;
  // this context is shared with whole asio instance
  asio::io_context &m_asioContext;
  ts_queue<message<T>> m_qMessageOut;
  ts_queue<owned_message<T>> m_qMessageIn;
}
} // namespace net
} // namespace olc