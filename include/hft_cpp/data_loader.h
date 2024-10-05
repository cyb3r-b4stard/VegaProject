#pragma once

#include <iostream>
#include <string>

class OrderBookSide{
private:
    double price;
    double volume;
public:
    OrderBookSide() = default;
    OrderBookSide(double _price, double _volume)
        : price(_price), volume(_volume)
    {}
    OrderBookSide(const OrderBookSide& other)
        : price(other.price), volume(other.volume)
    {}

    friend class OrderBook;

    friend std::ostream& operator<<(std::ostream& os, const OrderBookSide& obs) {
        os << "[ price: " << obs.price << " , volume: " << obs.volume << " ]";
        return os;
    }
};

class OrderBook {
private:
    std::string time;
    OrderBookSide ask;
    OrderBookSide bid;
public:
    OrderBook() = default;
    OrderBook(const std::string& _time, const OrderBookSide& _ask, const OrderBookSide& _bid)
        : time(_time), ask(_ask), bid(_bid)
    {}
    OrderBook(const OrderBook& other)
        : time(other.time), ask(other.ask), bid(other.bid)
    {}

    double get_best_ask();
    double get_best_bid();

    bool update(
        std::string new_time, 
        double new_ask_price, double new_ask_volume, 
        double new_bid_price, double new_bid_volume
    );

    friend std::ostream& operator<<(std::ostream& os, const OrderBook& ob) {
        os << "Order book time: " << ob.time << " ask: " << ob.ask << " bid: " << ob.bid;

        return os;
    }
};

class OrderBookLoader {
private:
    std::string file_path;
    OrderBook order_book;
public:
    OrderBookLoader(const std::string& _file_path)
        : file_path(_file_path),
          order_book(
            std::string(""),
            OrderBookSide(0, 0),
            OrderBookSide(0, 0)
          )
    {}

    OrderBook get_order_book() const;

    bool read_data();
};