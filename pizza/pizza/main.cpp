#include <iostream>

using namespace std;


class PizzaInterface {
public:
    virtual int getPriceMultiplier() = 0;
};

class BaseInterface {
public:
    virtual int getPrice() = 0;
};

class ToppingInterface {
public:
    virtual int getPrice() = 0;
};



class SmallPizza : public PizzaInterface {
    int priceMutliplier;

public:
    SmallPizza(int priceMutliplier) {
        this->priceMutliplier = priceMutliplier;
    }
    
    int getPriceMultiplier() {
        return this->priceMutliplier;
    }
};

class MediumPizza : public PizzaInterface {
    int priceMutliplier;

public:
    
    MediumPizza(int priceMutliplier) {
        this->priceMutliplier = priceMutliplier;
    }
    
    int getPriceMultiplier() {
        return this->priceMutliplier;
    }
    
};

class LargePizza : public PizzaInterface {
    int priceMutliplier;

public:
    
    LargePizza(int priceMutliplier) {
        this->priceMutliplier = priceMutliplier;
    }
    
    int getPriceMultiplier() {
        return this->priceMutliplier;
    }
    
};


class CheeseBase: public BaseInterface {
    int price;
public:
    CheeseBase(int price) {
        this->price = price;
    }
    
    int getPrice() {
        return this->price;
    }
};


class TomatoTopping : public ToppingInterface {
    int price;
public:
    TomatoTopping(int price) {
        this->price = price;
    }
    
    int getPrice() {
        return this->price;
    }
    
};

class ChickenTopping : public ToppingInterface {
    int price;
public:

    ChickenTopping(int price) {
        this->price = price;
    }
    
    int getPrice() {
        return this->price;
    }
};

class MushroomTopping : public ToppingInterface {
    int price;
    
public:
    MushroomTopping(int price) {
        this->price = price;
    }
    
    int getPrice() {
        return this->price;
    }
};




class Pizza {
    PizzaInterface* pizza;
    BaseInterface* base;
    vector<ToppingInterface*> toppings;
    
public:
    
    Pizza(PizzaInterface* pizza, BaseInterface* base) {
        this->pizza = pizza;
        this->base = base;
        this->toppings = vector<ToppingInterface*>();
    }
    
    int getPrice() {
        int price = this->base->getPrice();
        for(auto &x: toppings) {
            price += x->getPrice();
        }
        return price * this->pizza->getPriceMultiplier();
    }
    
    Pizza* withTopping(ToppingInterface* topping) {
        this->toppings.push_back(topping);
        return this;
    }
};



int main(int argc, const char * argv[]) {
    PizzaInterface* pizza = new MediumPizza(1);
    BaseInterface* base = new CheeseBase(10);
    ToppingInterface* tomatoTopping = new TomatoTopping(1);
    ToppingInterface* chickenTopping = new ChickenTopping(5);
    
    
    PizzaBuilderInterface *pizzaBuilder = new PizzaBuilder(pizza, base);
    pizzaBuilder = pizzaBuilder->withTopping(tomatoTopping)->withTopping(chickenTopping);
    
    cout << pizzaBuilder->getPrice() << endl;
    
    return 0;
}
