#include <deque>
#include <iostream>
#include <memory>
#include <string>

template<typename T>
class ThreadSafeQueue{
public:
    ThreadSafeQueue() : m_size(0) {}
    void push(T &item) {
        m_queue.push_back(std::move(item)); // phai move cho nay, vi deque se lay gia tri chu khong co reference
        ++m_size;
    }
    
    // return reference to unique ptr
    T& front() {
        return m_queue.front();
    }
private:
    size_t m_size;
    std::deque<T> m_queue;
};

class Entity {
public:
  Entity() : a_(0) { std::cout << "Created Entity!\n"; }

  ~Entity() { std::cout << "Destryed Entity!\n"; }

  int a_;
};

// pass unique ptr by referece, does not have to move
void modifyQueue(std::unique_ptr<Entity> &item) {
    // item->a_ = 15;
    // return std::move(item);
}

// pass unique ptr to another pointer
void modifyQueue2(Entity *item) {
    item->a_ = 20;
}

// unique pointer, luon luon nho, tai 1 thoi diem chi co 1 ham gain duoc pointer, hoac la pass bang reference
int main() {
  {
      std::unique_ptr<Entity> entity(new Entity());
      entity->a_ = 15;
      ThreadSafeQueue<std::unique_ptr<Entity>> dang_queue;
      dang_queue.push(entity);
      auto &entity2 = dang_queue.front(); // return reference

      std::deque<std::unique_ptr<Entity>> my_queue;
      std::unique_ptr<Entity> entity3(new Entity());
      entity3->a_ = 15;
      my_queue.push_back(std::move(entity3));
      std::unique_ptr<Entity> &entity4 = my_queue.front();
      std::cout << "entity4 = " << entity4->a_;
      modifyQueue2(entity4.get());

        // normal queue without smart pointer
      Entity n_entity = Entity();
      ThreadSafeQueue<Entity> n_queue;
      n_queue.push(n_entity);
      
  }
}