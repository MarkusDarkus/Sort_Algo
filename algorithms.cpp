#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED
// DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED DEPRECATED
void insertionSort(std::vector<double> &arr)
{
    if (arr.empty()) {
        return;
    }
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        size_t j = i - 1;
        while (j < arr.size() && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(std::vector<double> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}

void bubbleSort(std::vector<double> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void gnomeSort(std::vector<double> &arr)
{
    int n = arr.size();
    int index = 0;
    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            std::swap(arr[index], arr[index - 1]);
            index--;
        }
    }
}

void cocktailSort(std::vector<double> &arr)
{
    int n = arr.size();
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        end--;
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        start++;
    }
}

void heapify(std::vector<double> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(std::vector<double> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

template<class T>
void quickSortR(T *a, long N)
{
    long i = 0, j = N - 1;
    T temp, p;
    p = a[N >> 1];
    do {
        while (a[i] < p)
            i++;
        while (a[j] > p)
            j--;
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
        quickSortR(a, j);
    if (N > i)
        quickSortR(a + i, N - i);
}

void merge(std::vector<double> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[middle + 1 + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(std::vector<double> &arr, int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

/*
// Структура для представления узла в двоичном дереве
struct Node {
    int data;
    Node* left;
    Node* right;  
    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};  

// Вспомогательная функция для вставки узла в двоичное дерево
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }  
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }  
    return root;
}

// Рекурсивная функция для обхода двоичного дерева в порядке возрастания
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

// Функция для сортировки с помощью двоичного дерева
void treeSort(std::vector<double>& arr, int n) {
    Node* root = nullptr;  // Вставляем каждый элемент массива в двоичное дерево
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }  // Обходим дерево в порядке возрастания и перезаписываем элементы в массив
    int index = 0;
    inOrderTraversal(root, arr, index);
}
    
int main() {
 int arr[] = {7, 2, 5, 1, 9, 3};
 int n = sizeof(arr) / sizeof(arr[0]);  std::cout << "Исходный массив: ";
 for (int i = 0; i < n; i++) {
 std::cout << arr[i] << " ";
 }
 std::cout << std::endl;  treeSort(arr, n);  std::cout << "Отсортированный массив: ";
 for (int i = 0; i < n; i++) {
 std::cout << arr[i] << " ";
 }
 std::cout << std::endl;  return (0);
} */

/*
template <typename std::enable_if_t<std::is_integral_v<T>, T>>
void countingSort(std::vector<T>& array) {
    T max = std::max_element(array.begin(), array.end());
    auto count = std::vector<T>(max+1, T(0));  for (T elem : array)
    ++count[elem]; 
    T b = 0;
    for (size_t i = 0; i < max+1; ++i) {
        for (T j = 0; j < count[i]; ++j) {
            array[b++] = i;
        }
    } 
}
*/

// int main()
// {
//     std::vector<int> arr = {9, 2, 7, 5, 1, 6, 8, 3, 4};
//     //insertionSort(arr);
//     for (const auto &num : arr) {
//         std::cout << num << " ";
//     }
//     return (0);
// }
