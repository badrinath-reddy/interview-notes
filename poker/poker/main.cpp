#include <iostream>

using namespace std;

class Card {
public:
    int number;
    char symbol;
};

class AbstractHand {
public:
    string name;
    virtual bool isPossible(vector<Card*> cards) = 0;
};

class High : public AbstractHand {
public:
    bool isPossible(vector<Card*> cards) {
        return true;
    }
    
}

class Pair : public AbstractHand {
    
};

class FullHouse : public AbstractHand {
    
};

class ThreeOfAKind : public AbstractHand {
    
};


class Game {
    vector<AbstractHand*> possibleHands;
    
public:
    AbstractHand* getBestHand(vector<Card*> cards) {
        for(auto &hand: possibleHands) {
            if(hand->isPossible(cards)) {
                return hand;
            }
        }
        return NULL;
    }
    
    void setHandsFromBestToWorst(vector<AbstractHand*> hands) {
        this->possibleHands = hands;
    }
};




int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    return 0;
}
