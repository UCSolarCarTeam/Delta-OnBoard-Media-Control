#include "Gordon.h"

    Gordon() {}

    void notify_listeners() {
        for(listener:listeners) 
        {
            listener.heard_something();
        }
    }

    void stumped_toe() {
        std::cout << "gordon::ouch" << std::endl;
        notify_listeners();
    }
};
