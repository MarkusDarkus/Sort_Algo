#include <QtGlobal>
#include "function_link.h"
#include "algorithms/Bubble.h"
#include "algorithms/Gnome.h"
#include "algorithms/Heap.h"


void function_link(std::vector<int> &data, const std::string &name) {
    if (name == "Bubble") {
        bubbleSort(data);
    } else if (name == "Gnome") {
        gnomeSort(data);
    } else if (name == "Heap") {
        heapSort(data);
    } else {
        qFatal((std::string("There is no function called: ") + name).c_str());
    }
}
