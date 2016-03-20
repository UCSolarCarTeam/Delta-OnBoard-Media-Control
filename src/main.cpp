#include "gordon.h"
#include "ben.h"

int main() {

    Ben ben = Ben();
    Ben ben1 = Ben();
    Ben ben2 = Ben();
    Ben ben3 = Ben();
    Ben ben4 = Ben();
    Ben ben5 = Ben();
    Ben ben6 = Ben();
    Ben ben7 = Ben();
    Ben ben8 = Ben();
    Ben ben9 = Ben();
    Ben ben10 = Ben();
    Ben ben11 = Ben();
    Ben ben12 = Ben();
    Ben ben13 = Ben();
    Gordon gordon = Gordon();
    gordon.add_listener(&ben);
    gordon.add_listener(&ben1);
    gordon.add_listener(&ben2);
    gordon.add_listener(&ben3);
    gordon.add_listener(&ben4);
    gordon.add_listener(&ben5);
    gordon.add_listener(&ben6);
    gordon.add_listener(&ben7);
    gordon.add_listener(&ben8);
    gordon.add_listener(&ben9);
    gordon.add_listener(&ben10);
    gordon.add_listener(&ben11);
    gordon.add_listener(&ben12);
    gordon.add_listener(&ben13);
    gordon.stumped_toe();
    
    return 0;
}
