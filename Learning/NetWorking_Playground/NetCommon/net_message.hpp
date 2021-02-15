#include "net_common.hpp"

namespace olc {
namespace net {
template <typename T> struct message_header {
  T id{}; // id nay se la 1 enum
  uint32_t length = 0;
};

template <typename T> struct message : message_header<T> {
  std::vector<uint8_t> payload; // xu ly tung byte nen la uint8_t
  size_t size() { return sizeof(message_header<T>) + payload.size(); }

  // overload std::cout, print message
  friend std::ostream &operator<<(std::ostream &os, message<T> &msg) {
    os << "ID: " << int(msg.id) << "Msg Length: " << msg.size() << '\n';
    return os;
  }

  // push data vao trong message
  template <typename DataTypes>
  friend message<T> &operator<<(message<T> &msg, DataTypes &data) {
    static_assert(std::is_standard_layout<DataTypes>::value,
                  "DataTypes is too complex");
    size_t i = msg.payload.size();
    msg.payload.resize(i + sizeof(data));
    memcpy(msg.payload.data() + i, &data, sizeof(data));
    msg.length = msg.size();
    return msg;
  }

  // pop data ra khoi message
  template <typename DataTypes>
  friend message<T> &operator>>(message<T> &msg, DataTypes &data) {
    static_assert(std::is_standard_layout<DataTypes>::value,
                  "DataTypes is too complex");
    size_t i = msg.payload.size() - sizeof(data);
    memcpy(&data, msg.payload.data() + i, sizeof(data));
    msg.payload.resize(i);
    msg.length = msg.size();
    return msg;
  }
};

// forward declare of connection
template <typename T> class connection;

// struct nay dung trong server vi trong sever co nhieu connection tu nhieu
// clients
template <typename T> struct owned_message {
  std::shared_ptr<connection<T>> remote = nullptr;
  message<T> msg;

  friend std::ostream &operator<<(std::ostream &os, owned_message<T> &msg) {
    os << msg.msg;
    return os;
  }
};
} // namespace net
} // namespace olc