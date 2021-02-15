#include "net_common.hpp"
#include "net_connection.hpp"
#include "net_message.hpp"
#include "net_tsqueue.hpp"

namespace olc {
namespace net {
template <typename T> class server_interface {
public:
  server_interface(uint16_t port) {}

  virtual ~server_interface() {}
  bool Start() {}
  bool Stop() {}
  void WaitForClientConnection() {}
  // send msg to specific client
  void MessageClient(std::shared_ptr<connection<T>> client,
                     const message<T> &msg) {}

  // send msg to all client
  void
  MessageAllClient(const message<T> &msg,
                   std::shared_ptr<connection<T>> pIgnoreClient = nullptr) {}

protected:
  // called when client is accepted to connect
  virtual bool OnClientConnect(std::shared_ptr<connection<T>> client) {
    return false;
  }

  // called when a client appears to have disconnected
  virtual void OnClientDisconnect(std::shared_ptr<connection<T>> client) {
  }

  // called when a message arrives
  virtual void OnMessage(std::shared_ptr<connection<T>> client, message<T> &msg)
  protected:
  // thread safe queue for incoming message packets
  ts_queue<owned_message<T>> m_qMessageIn;
};
} // namespace net
} // namespace olc