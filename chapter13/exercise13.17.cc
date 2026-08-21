/*
Write versions of ```Numbered``` and ```f``` corresponding to the previous
three exercises and check whether you correctly predicted the output.
*/

#include <iostream>
#include <vector>
#include <random>

int generate_sn() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 100);
    int random_num = distrib(gen);
    return random_num;
}

class Numbered_V1 {
public:
    int mysn;
    Numbered_V1(): mysn(0) {  }
    Numbered_V1(const Numbered_V1& x) {
        mysn = x.mysn;
    }
    Numbered_V1& operator=(const Numbered_V1& x) { 
        mysn = x.mysn;
        return *this; 
    }
    ~Numbered_V1() { }
};

class Numbered_V2 {
public:
    int mysn;
    Numbered_V2(): mysn(generate_sn()) {  }
    Numbered_V2(const Numbered_V2& x) {
        mysn = generate_sn();
    }
    Numbered_V2& operator=(const Numbered_V2& x) { 
        mysn = generate_sn();
        return *this; 
    }
    ~Numbered_V2() { }
};

void f_v1(Numbered_V1 s) { 
    std::cout << s.mysn << std::endl; 
}

void f_v2(Numbered_V2 s) { 
    std::cout << s.mysn << std::endl; 
}

void f_v2_byref(const Numbered_V2 &s) { 
    std::cout << s.mysn << std::endl; 
}

int main() {
    std::cout << "----------- f_v1 abc1 ------------" << std::endl;
    Numbered_V1 a1, b1 = a1, c1 = b1;
    f_v1(a1); f_v1(b1); f_v1(c1);

    std::cout << "------------- f_v2 abc2 ----------" << std::endl;
    Numbered_V2 a2, b2 = a2, c2 = b2;
    f_v2(a2); f_v2(b2); f_v2(c2);

    std::cout << "------------- f_v2_byref abc2 ----" << std::endl;
    f_v2_byref(a2); f_v2_byref(b2); f_v2_byref(c2);

    std::cout << "------------- serial nums abc2 ---" << std::endl;
    std::cout << a2.mysn << std::endl;
    std::cout << b2.mysn << std::endl;
    std::cout << c2.mysn << std::endl;

    return 0;
}