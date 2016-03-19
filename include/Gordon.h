#pragma once
#include <iostream>

class Gordon : public Observable<I_gobserver> {
public:
    Gordon();
    void stumped_toe();

private:
    void notify_listeners();
};
