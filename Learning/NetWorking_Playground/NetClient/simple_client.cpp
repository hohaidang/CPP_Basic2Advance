#include <olc_net.hpp>

enum class MsgType : uint32_t {
	FireBullet = 0,
	MovingPlayer
};

int main() {
	olc::net::ts_queue<int> my_queue;
	int a = 5;
	my_queue.push_back(a);
	auto b = my_queue.pop_front();

	system("pause");
	return 0;
}