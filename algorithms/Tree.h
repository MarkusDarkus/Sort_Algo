#ifndef TREE_H
#define TREE_H

#include <algorithm>
#include <vector>

struct Node;
struct Node *newNode(int item);
void storeSorted(Node *root, std::vector<int>& arr, int &i);
Node* insert(Node* node, int key);
void treeSort(std::vector<int>& arr);

#endif // TREE_H
