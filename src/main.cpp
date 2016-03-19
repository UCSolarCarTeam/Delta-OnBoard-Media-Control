#include "gordon.h"
#include "ben.h"

int main() {

    Ben ben = Ben();
    Ben ben2 = Ben();
    Ben ben3 = Ben();
    Ben ben4 = Ben();
    Ben ben5 = Ben();
    Gordon gordon = Gordon();
    gordon.add_listener(&ben);
    gordon.add_listener(&ben2);
    gordon.add_listener(&ben3);
    gordon.add_listener(&ben4);
    gordon.add_listener(&ben5);
    gordon.stumped_toe();
    
    return 0;
}
