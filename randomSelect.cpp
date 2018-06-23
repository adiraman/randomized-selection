#include "randomSelect.h"

void interchange(int* a, int* b)
{

    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}

void printVec(const std::vector<int>& v)
{
    for (auto i : v) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

int partition(std::vector<int>& v, const int l, const int r)
{

    int pivot = v[l];

    // i = index that keeps track of the interface between all the
    //     less than and greater than pivot elements
    // j = index that keeps track of the interface between all the
    //     seen ( partitioned ) and unseen ( unpartitioned ) elements
    int i = l;
    for (int j = l + 1; j <= r; ++j) {
        if (v[j] <= pivot) {
            interchange(&v[i + 1], &v[j]);
            ++i;
        }
    }

    interchange(&v[l], &v[i]);
    return i;
}

void choosePivot(std::vector<int>& v, const int l, const int r)
{

    // Choose the pivot point uniformly at random from the given
    // vector. For more info on how to do this refer
    // http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;  // used to obtain a seed for random # gen
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd
    std::uniform_int_distribution<> dis(l, r);

    int pivotInd = dis(gen);

    // bring the pivot element at the beginning
    if (pivotInd != l) {
        interchange(&v[l], &v[pivotInd]);
    }

    return;
}

int Rs(std::vector<int>& v, const int l,
    const int r, const int stat)
{

    // Base case exit condition
    if (l == r)
        return v[l];

    // error handling
    if (stat == 0) {
        std::cerr << "Cannot have " << stat << " order statistics !" << std::endl;
        return -1;
    }

    choosePivot(v, l, r);

    int p = partition(v, l, r); // index where the partition is
    int i = p - l + 1;          // partition is the ith order statistic
    int retVal;

    if (stat == i)
        retVal = v[p];
    else if (stat < i)
        retVal = Rs(v, l, p - 1, stat);
    else
        retVal = Rs(v, p + 1, r, stat - i);
    return retVal;
}

int Rselect(std::vector<int>& v, const int stat)
{
    int l = 0;
    int r = v.size() - 1;
    return Rs(v, l, r, stat);
}
