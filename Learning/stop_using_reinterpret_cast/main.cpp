#include <cstring>

struct S {
    int i;
    int j;
};

void update_data(char *blob, int new_value) {
    reinterpret_cast<S *>(blob)[2].j = new_value;
}

void update_data_not_ub(char *blob, int new_value) {
    S obj[3];
    memcpy(obj, blob, sizeof(obj));
    obj[2].j = new_value;
    memcpy(blob, obj, sizeof(obj));
}