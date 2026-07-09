#include <iostream>

class Player {
    private:
        int health = 100;
    
    public:
        void setHealth(int newHealth) {
            if (newHealth < 0) {
                health = 0;
            } else {
                health = newHealth;
            }
        }
        int getHealth() {
            return health;
        }
};

int main() {
    Player p1;

    p1.setHealth(100);

    std::cout << "Player Health: " << p1.getHealth() << std::endl;

    return 0;
}
