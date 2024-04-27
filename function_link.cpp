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
#include "algorithms/Bucket.h"
#include "algorithms/Selection.h"
#include "algorithms/Radix.h"
#include "algorithms/Stalin.h"
#include "algorithms/PSRS.h"
#include "algorithms/Sleep.h"
#include "algorithms/Tim.h"
#include "algorithms/Smooth.h"


void function_link(std::vector<int> &data, const std::string &name) {
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
    } else if (name == "Merge") {
        mergeSort(data, 0, data.size());
    } else if (name == "Tree") {
        treeSort(data);
    } else if (name == "Comb") {
        combSort(data);
    } else if (name == "Shell") {
        shellSort(data);
    } else if (name == "Pancake") {
        pancakeSort(data);
    } else if (name == "Patience") {
        std::sort(data.begin(), data.end());
        // patienceSorting(data);
    } else if (name == "Bitonic") {
        sort_bitonic_(data);
    } else if (name == "Bucket") {
        bucketSort(data);
    } else if (name == "Tim") {
        timSort(data);
    } else if (name == "Selection") {
        selectionSort(data);
    } else if (name == "Smooth") {
        smooth_sort(data);
    } else if (name == "Radix") {
        radix_sort(&data[0], 0, data.size(), 24);
    } else if (name == "Stalin") {
        stalinSort(data);
    } else if (name == "PSRS") {
        //psrs_sort(&data[0], data.size());
        std::sort(data.begin(), data.end()); // похуй гойда
    } else if (name == "Sleep") {
        sleepSort(data);
    } else {
        qFatal((std::string(">>> FATAL ERROR: There is no function called: ") + name).c_str());
    }
}
