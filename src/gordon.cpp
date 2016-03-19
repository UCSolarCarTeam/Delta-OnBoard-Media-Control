#include "gordon.h"
Gordon::Gordon() {}

void Gordon::notify_listeners() {
    for(I_gobserver *listener:listeners) 
    {
        listener->heard_something();
    }
}

void Gordon::stumped_toe() {
    std::cout << "gordon::ouch" << std::endl;
    notify_listeners();
}
