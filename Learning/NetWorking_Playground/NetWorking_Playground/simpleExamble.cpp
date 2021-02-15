// reference: https://www.youtube.com/watch?v=2hNdkYInj4g&t=191s
#include <chrono>
#include <iostream>
#include <vector>

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

std::vector<char> vBuffer(1 * 1024);

// ham nay se cu doc data lien tuc asynchronuse va print ra man hinh
void GrabSomeData(asio::ip::tcp::socket &socket) {
  // vBuffer.size() o day de cho biet bao nhieu byte duoc doc moi lan
  socket.async_read_some(asio::buffer(vBuffer.data(), vBuffer.size()),
                         [&](std::error_code ec, std::size_t length) {
                           if (!ec) {
                             std::cout << "\n\nRead " << length << "bytes\n\n";
                             for (int i = 0; i < length; ++i)
                               std::cout << vBuffer[i];
                             GrabSomeData(socket);
                           }
                         });
}

int main() {
  asio::error_code ec;
  asio::io_context context;

  // cho context 1 cai fake task de no khong the finish truoc ham main
  asio::io_context::work idleWork(context);

  // start context
  std::thread thrContext = std::thread([&]() { context.run(); });

  // connect vao ip address
  // asio::ip::tcp::endpoint endpoint(asio::ip::make_address("93.184.216.34",
  // ec), 80); // examble.com
  asio::ip::tcp::endpoint endpoint(asio::ip::make_address("51.38.81.49", ec),
                                   80);
  // asio::ip::tcp::endpoint endpoint(asio::ip::make_address("127.0.0.1", ec),
  // 80);

  // tao socket
  asio::ip::tcp::socket socket(context);

  // try to connect
  socket.connect(endpoint, ec);
  if (!ec) {
    std::cout << "Connected!\n";
  } else {
    std::cout << "Failed to connect to address:\n" << ec.message() << '\n';
  }
  if (socket.is_open()) {
    // start viec nhan du lieu truoc de khi write vao web,
    // se luon co 1 thread ready cho viec nhan du lieu
    GrabSomeData(socket);

    std::string sRequest = "GET /index.html HTTP/1.1\r\n"
                           "HOST: example.com\r\n"
                           "Connection: close\r\n\r\n";
    socket.write_some(asio::buffer(sRequest.data(), sRequest.size()),
                      ec); // write data to socket

    // cho chuong trinh main cho`, trong khi 1 thread khac se doc data transfer
    // o background
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(20000ms);

    context.stop();
    if (thrContext.joinable())
      thrContext.join();
  }

  system("pause");
  return 0;
}