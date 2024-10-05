#include <iostream>
#include "hft_cpp/data_loader.h"

int main() {
    OrderBookLoader loader("../data.csv");
    
    loader.read_data();
    
    return 0;
}