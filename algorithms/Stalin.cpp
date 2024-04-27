#include "Stalin.h"
#include <vector>


void stalinSort(std::vector<int> &data) {
    for (int i = 1; i < data.size(); ++i) {
        if (data[i - 1] > data[i]) {
            data.erase(data.begin() + i);
            i--;
        }
    }
}
