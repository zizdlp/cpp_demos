// file cats.h

class Felid {
public:
 virtual void meow() = 0;
};

class Cat : public Felid {
public:
 void meow() { std::cout << "Meowing like a regular cat! meow!\n"; }
};

class Tiger : public Felid {
public:
 void meow() { std::cout << "Meowing like a tiger! MREOWWW!\n"; }
};

class Ocelot : public Felid {
public:
 void meow() { std::cout << "Meowing like an ocelot! mews!\n"; }
};
