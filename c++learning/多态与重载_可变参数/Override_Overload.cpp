#include <iostream> //9.25尝试多态与重载重写运用
                    //证明不重写则 父类指针指向子类对象后 不重写则调用父类函数

class Animal {
public:
    virtual void sound() {  //virtual虚函数，之后学
        std::cout << "Animal makes a sound" << std::endl;
    }
    void sound(const std::string& type) {  // 重载方法
        std::cout << "Animal makes a " << type << " sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {  // 重写父类的 sound() 方法
        std::cout << "Dog barks" << std::endl;
    }
};

int main() {
    Animal* myAnimal = new Dog();  // 父类指针指向子类对象
    myAnimal->sound();  // 调用子类 Dog 的 sound() 方法
    myAnimal->sound("loud");      // 调用 Animal 类的重载方法 sound(string)
    delete myAnimal;
    return 0;
}
