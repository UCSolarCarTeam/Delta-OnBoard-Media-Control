#include <vector>

template <class T>
class I_observable {
public:
    T add_listeners(T listener) 
    {
        listeners.push_back(listener);
    }

private:
    std::vector<T> listeners;
}
