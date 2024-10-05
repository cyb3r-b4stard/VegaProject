#include <iostream>
#include <fstream>
#include <sstream>
#include "hft_cpp/data_loader.h"

bool OrderBook::update(
    std::string new_time, 
    double new_ask_price, double new_ask_volume,
    double new_bid_price, double new_bid_volume) {
    
    time = new_time;
    ask = OrderBookSide(new_ask_price, new_ask_volume);
    bid = OrderBookSide(new_bid_price, new_bid_volume);
}

double OrderBook::get_best_ask() {
    return ask.price;
}

double OrderBook::get_best_bid() {
    return bid.price;
}

bool OrderBookLoader::read_data() {
    std::string line;
    std::string time;
    
    double ask_price;
    double ask_volume;
    double bid_price;
    double bid_volume;

    std::ifstream file(file_path);

    while (std::getline(file, line)) {
        std::stringstream sstream(line);
        
        std::getline(sstream, time, ',');

        sstream >> ask_price >> bid_price >> ask_volume >> bid_volume;

        order_book.update(time, ask_price, ask_volume, bid_price, bid_volume);

        std::cout << order_book << '\n';
    }

    return true;
}

OrderBook OrderBookLoader::get_order_book() const {
    return order_book;
}