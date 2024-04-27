#include <algorithm>

#include <QtGlobal>
#include "function_link.h"
#include "algorithms/Bubble.h"
#include "algorithms/Gnome.h"
#include "algorithms/Heap.h"
#include "algorithms/Insertion.h"
#include "algorithms/Cocktail.h"
#include "algorithms/Quick.h"
#include "algorithms/Merge.h"
#include "algorithms/Tree.h"
#include "algorithms/Comb.h"
#include "algorithms/Shell.h"
#include "algorithms/Pancake.h"
#include "algorithms/Patience.h"
#include "algorithms/Bitonic.h"


int function_link(std::vector<int> &data, const std::string &name) {
    if (name == "Bubble") {
        bubbleSort(data);
    } else if (name == "Gnome") {
        gnomeSort(data);
    } else if (name == "Heap") {
        heapSort(data);
    } else if (name == "Insertion") {
        insertionSort(data);
    } else if (name == "Cocktail") {
        cocktailSort(data);
    } else if (name == "Quick") {
        std::sort(data.begin(), data.end());
        // quickSort(data);
    } else if (name == "Merge") {
        std::sort(data.begin(), data.end());
        // mergeSort(data);
    } else if (name == "Tree") {
        std::sort(data.begin(), data.end());
        // treeSort(data);
    } else if (name == "Comb") {
        combSort(data);
    } else if (name == "Shell") {
        std::sort(data.begin(), data.end());
        // shellSort(data);
    } else if (name == "Pancake") {
        std::sort(data.begin(), data.end());
        // pancakeSort(data);
    } else if (name == "Patience") {
        patienceSorting(data);
    } else if (name == "Bitonic") {
        std::sort(data.begin(), data.end());
        // sort_bitonic_(data);
    } else {
        qWarning((std::string("There is no function called: ") + name).c_str());
        return -1;
    }
    return 0;
}
