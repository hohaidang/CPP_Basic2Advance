/* Ham main nay mo ta cach su dung glog */
/* Van chua dung duoc glog o tren Windows. Chua test cho iOS */
#include "glog/logging.h"
#include "glog/stl_longging.h"

#include <iostream>
#include <map>
#include <vector>
using namespace std;
bool g_cond = true;

void my_function() {
    vector<int> my_vector = {1, 2, 3, 4};
    map<int, int> my_map = {{1, 2,} , {2, 3}};
    LOG(INFO) << "Printing my_vector: " << "{" << my_vector << "}";
    LOG(INFO) << "Printing a my_map " << my_map; // can print map and vector
    LOG(WARNING) << "This is a warning message";
    LOG(ERROR) << "This is error message";
    LOG_IF(INFO, g_cond == true) << "g_cond is true!";
    CHECK(5 == 4) << "Check failed!";
}

int main(int argc, char *argv[]) {
    google::InitGoogleLogging(argv[0]); // init google log

    // Log both to log file and sderr
    //FLAGS_alsologtostderr = true;
    my_function();
    return 0;
}