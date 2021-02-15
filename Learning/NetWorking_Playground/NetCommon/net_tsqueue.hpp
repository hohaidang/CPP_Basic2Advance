#include "net_common.hpp"

namespace olc {
namespace net {
template <typename T> class ts_queue {
public:
  const T &front() {
    std::lock_guard<std::mutex> lock(muxQueue);
    return queue.front();
  }

  const T &back() {
    std::lock_guard<std::mutex> lock(muxQueue);
    return queue.back();
  }

  void push_back(const T &item) {
    std::lock_guard<std::mutex> lock(muxQueue);
    queue.emplace_back(std::move(item));
    std::unique_lock<std::mutex> ul(muxBlocking);
    cvBlocking.notify_one();
  }

  T pop_front() {
    std::lock_guard<std::mutex> lock(muxQueue);
    auto t = std::move(queue.front());
    queue.pop_front();
    return t;
  }

  std::deque<T> queue;
  std::mutex muxQueue;
  std::condition_variable cvBlocking;
  std::mutex muxBlocking;
};
} // namespace net
} // namespace olc