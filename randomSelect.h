#ifndef RANDOM_SELECT_H
#define RANDOM_SELECT_H

#include <iostream>
#include <vector>
#include <random>

void interchange(int* a, int* b);

void printVec(const std::vector<int>& v);

int partition(std::vector<int>& v, const int l, const int r);

void choosePivot(std::vector<int>& v, const int l, const int r);

int Rs(std::vector<int>& v, const int l,
        const int r, const int stat);

int Rselect(std::vector<int>& v, const int stat);

#endif /* ifndef RANDOM_SELECT_H */
