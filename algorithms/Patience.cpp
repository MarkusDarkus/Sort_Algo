#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
#include <bits/stdc++.h>


std::vector<double> merge_piles(std::vector<std::vector<double> >& v)
{
	std::vector<double> ans;
	while (1) {
		int minu = INT_MAX;
		int index = -1;
		for (int i = 0; i < v.size(); i++) {
			if (minu > v[i][v[i].size() - 1]) {
				minu = v[i][v[i].size() - 1];
				index = i;
			}
		}
		ans.push_back(minu);
		v[index].pop_back();
		if (v[index].empty()) {
			v.erase(v.begin() + index);
		}
		if (v.size() == 0)
			break;
	}
	return ans;
}


std::vector<double> patienceSorting(std::vector<double>& arr)
{
	std::vector<std::vector<double>> piles;
	for (int i = 0; i < arr.size(); i++) {
		if (piles.empty()) {
			std::vector<double> temp;
			temp.push_back(arr[i]);
			piles.push_back(temp);
		}
		else {
			int flag = 1;
			for (int j = 0; j < piles.size(); j++) {
				if (arr[i] < piles[j][piles[j].size() - 1]) {
					piles[j].push_back(arr[i]);
					flag = 0;
					break;
				}
			}
			if (flag) {
				std::vector<double> temp;
				temp.push_back(arr[i]);
				piles.push_back(temp);
			}
		}
	}
	std::vector<double> ans;
	ans = merge_piles(piles);
	return ans;
}