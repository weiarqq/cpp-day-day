// 多继承
/*

class 类名: public 父类1, public 父类2,...{
}



*/
#include <iostream>
using namespace std;

class PlanA {
public:
  int m_A;
  int m_Base;
  PlanA() : m_A(1), m_Base(-1) {}
};

class PlanB {
public:
  int m_B;
  int m_Base;
  PlanB() : m_B(2), m_Base(-1) {}
};
class PlanC {
public:
  int m_C;
  int m_Base;
  PlanC() : m_C(3) {}
};

class Plan : public PlanA, public PlanB, public PlanC {};
int main() {
  Plan plan;
  plan.m_A = 11;
  plan.m_B = 11;
  plan.m_C = 11;
  plan.PlanA::m_Base = 12;
  plan.PlanB::m_Base = 13; // 多继承下访问父类之间同名变量

  return 0;
}