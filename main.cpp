#include "randomSelect.h"

int main(int argc, char* argv[]){

    if(argc != 3){
        std::cerr << "Usage: " << argv[0] << " <vector size>, <order stat>" << std::endl;
        return 0;
    }
    int n = atoi(argv[1]);
    std::vector<int> a(n);
    int i = atoi(argv[2]);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1024);

    for(int ind=0; ind<n; ++ind){
        a[ind] = dis(gen);
    }

    printVec(a);

    std::cout << "Order " << i << " statistic is: " << Rselect(a, i) << std::endl;
    return 0;
}


