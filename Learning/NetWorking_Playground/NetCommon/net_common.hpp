// reference: https://www.youtube.com/watch?v=2hNdkYInj4g&t=191s
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <mutex>
#include <condition_variable>
#include <memory>

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif

#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>