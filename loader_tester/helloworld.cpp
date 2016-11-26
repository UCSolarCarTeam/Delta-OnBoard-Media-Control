#include <iostream>


int main()
{
    int a = 5;
    int b = 10;
    int *checker;
    int *pointer;
    int **doublePointer;
    checker = &a;
    pointer = &b;
    doublePointer = & checker;




    /******************************************
     * Debug
     */

    std::cout << "--Variable A--" << std::endl;
    std::cout << a << std::endl;

    std::cout << "--Variable B--" << std::endl;
    std::cout << *checker << std::endl;
    std::cout << checker << std::endl;
    
    std::cout << "--Variable C--" << std::endl;
    std::cout << *pointer << std::endl;
    std::cout <<  pointer << std::endl;

    std::cout << "--Variable D--" << std::endl;
    std::cout << **doublePointer << std::endl;
    std::cout << *doublePointer << std::endl;
    std::cout <<  doublePointer << std::endl;
}
