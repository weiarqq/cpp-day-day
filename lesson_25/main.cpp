#include <iostream>
#include <memory>

struct Obj {
  private:
    int a;
    int b;

  public:
    int c;
    Obj(int x, int y) : a(x), b(y), c(x + y) {}
};

int main() {
    Obj obj(1, 2);
    std::cout << obj.c << '\n';

    std::unique_ptr<Obj> p1 = std::make_unique<Obj>(3, 4);
    // std::unique_ptr<Obj> p2 = p1; // 编译错误，unique_ptr不支持拷贝
    std::unique_ptr<Obj> p2 = std::move(p1);

    std::shared_ptr<Obj> sp1 = std::make_shared<Obj>(1, 2);
    std::shared_ptr<Obj> sp2 = sp1; // shared_ptr支持拷贝
    std::cout << "use_count: " << sp1.use_count();

    std::shared_ptr<Obj> sp3 = std::move(sp1); // sp1变为空，sp3指向原来的对象

    std::shared_ptr<Obj> sp4_shared = std::make_shared<Obj>(5, 6);
    std::weak_ptr<Obj> sp4 = sp4_shared; // weak_ptr不影响引用计数

    // Obj obj3(7, 8);
    // Obj* obj4 = new Obj(9, 10); // 普通指针需要手动释放内存
}
