#include <deque>
#include <iostream>
#include <memory>
#include <string>

class Entity {
public:
  Entity() { std::cout << "Created Entity!\n"; }

  ~Entity() { std::cout << "Destryed Entity!\n"; }

  int a;
};

void modifyQueue(std::unique_ptr<Entity> item) {
    
}

int main() {
  std::deque<std::unique_ptr<Entity>> my_queue;
  {
    // first way
    //   std::unique_ptr<Entity> entity(new Entity());
    // second way, more safeter because of exception
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();
    my_queue.push_back(std::move(entity));
  }
  my_queue.pop_front();

  {}
}