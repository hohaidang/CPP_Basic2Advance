#include <deque>
#include <iostream>
#include <memory>
#include <string>

class Entity {
public:
  Entity() { std::cout << "Created Entity!\n"; }

  ~Entity() { std::cout << "Destryed Entity!\n"; }
};

int main() {
  std::deque<Entity *> my_queue;
  {
    auto entity = new Entity();
    my_queue.push_back(entity);
  }
  my_queue.pop_front();
}