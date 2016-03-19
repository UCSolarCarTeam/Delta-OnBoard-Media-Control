#pragma once
#include <iostream>
#include "Observable.h"
#include "I_gobserver.h"

class Gordon : public Observable<I_gobserver> {
public:
    Gordon();
    void stumped_toe();

private:
    void notify_listeners();
};
