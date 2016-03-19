#pragma once
#include <vector>

template <class T>
class Observable {
public:
    T add_listeners(T listener) {
        listeners.push_back(listener);
    }

private:
    std::vector<T> listeners;
}
