#include <iostream>

class Wizard {
    private:
        int mana{};
        int health{};

    public:
        Wizard(int startingMana, int startingHealth) {
            mana = startingMana;
            health = startingHealth;
        }

        void useMana(int amount) {
            if (mana <= 0) {
                std::cout << "You have 0 mana";
                mana = 0;
            } else if (amount > mana) {
                std::cout << "You dont have enough mana you have " << mana << std::endl;
            } else {
                mana -= amount;
                std::cout << "You used a spell\nMana left: " << getMana() << std::endl;

            }
        }
        int getMana() {
            return mana;
        }
        int getHealth() {
            return health;
        }
}; 

int main() {
    Wizard w1(50,100);
    Wizard w2(150, 100);

    w1.useMana(10);
    
    std::cout << "Wizard2 health: " << w2.getHealth() << std::endl;
    
}
