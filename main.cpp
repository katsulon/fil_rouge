#include "src/Hero.cpp"

using namespace He_ARC::rpg;

int main()
{
    Hero h1;
    h1.show();
    Hero h2(3,7,10,100,"Gimli");
    h2.show();
    
    h2.interact(h1);
    
    return 0;
}