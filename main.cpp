#include "Hero.cpp"

int main()
{
    Hero h1;
    h1.show();
    Hero h2(3,7,10,100,"Gimli");
    h2.show();
    
    h1.interact(h2);
    
    return 0;
}