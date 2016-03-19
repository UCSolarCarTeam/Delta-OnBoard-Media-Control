int main() {

    Ben ben = Ben();
    Gordon gordon = Gordon();
    gordon.add_listener(ben);
    gordon.stumped_toe();
    
    return 0;
}
