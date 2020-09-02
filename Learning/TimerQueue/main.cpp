/*
 * main.cpp
 *
 *  Created on: Jun 29, 2020
 *      Author: hohaidang
 */





#include "TimerQueue.h"
#include <future>

namespace Timing {

using Clock = std::chrono::high_resolution_clock;
static thread_local Clock::time_point ms_previous;
double now() {
    static auto start = Clock::now();
    return std::chrono::duration<double, std::milli>(Clock::now() - start)
        .count();
}

void sleep(unsigned ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

}  // namespace Timing

int main() {
    TimerQueue q;
 	TimerQueue q2;
     // Create timer with ID 1
     q.add(10000, [start = Timing::now()](bool aborted) mutable {
         printf("ID 1: aborted=%s, Elapsed %4.2fms\n",
                aborted ? "true " : "false", Timing::now() - start);
     });

     // Create Timer with ID 2
     q.add(10001, [start = Timing::now()](bool aborted) mutable {
         printf("ID 2: aborted=%s, Elapsed %4.2fms\n",
                aborted ? "true " : "false", Timing::now() - start);
     });

     // Should cancel timers with ID 1 and 2
     q.cancelAll();

     // Create timer with ID 3
     q.add(1000, [start = Timing::now()](bool aborted) mutable {
         printf("ID 3: aborted=%s, Elapsed %4.2fms\n",
                aborted ? "true " : "false", Timing::now() - start);
     });

     // Create timer with ID 4
     auto id = q.add(2000, [start = Timing::now()](bool aborted) mutable {
         printf("ID 4: aborted=%s, Elapsed %4.2fms\n",
                aborted ? "true " : "false", Timing::now() - start);
     });

     // Cancel timer with ID 4
     auto ret = q.cancel(id);
     assert(ret == 1);

     // Give just enough time to execute timer with ID 3 before destroying the
     // TimerQueue
     Timing::sleep(1500);

     // At this point, when destroying TimerQueue, the timer with ID 4 is still
     // pending and will be cancelled implicitly by the destructor
    return 0;
}
