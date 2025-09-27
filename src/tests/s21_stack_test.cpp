#include "test.h"

TEST(Stack, TestConstructorDefaultInt) {
  s21::stack<int> s;
  std::stack<int> s2;

  ASSERT_EQ(s.size(), 0);
  ASSERT_EQ(s2.size(), s.size());
}

TEST(Stack, TestConstructorDefaultDbl) {
  s21::stack<double> s;
  std::stack<double> s2;

  ASSERT_EQ(s.size(), 0);
  ASSERT_EQ(s2.size(), s.size());
}

TEST(Stack, TestConstructorDefaultStr) {
  s21::stack<std::string> s;
  std::stack<std::string> s2;
  ASSERT_EQ(s.size(), 0);
  ASSERT_EQ(s2.size(), s.size());
}

TEST(Stack, TestInitializerListConstructorInt) {
  std::initializer_list arr = {1, 2, 3};
  s21::stack<int> s{arr};
  ASSERT_EQ(s.top(), 3);
  ASSERT_EQ(s.size(), 3);
}

TEST(Stack, TestInitializerListConstructorDbl) {
  std::initializer_list arr = {1.1, 2.2, 3.3};
  s21::stack<double> s{arr};
  ASSERT_EQ(s.top(), 3.3);
  ASSERT_EQ(s.size(), 3);
}

TEST(Stack, TestConstructorCopyInt) {
  s21::stack<int> My_S{1, 2};
  std::stack<int> Std_S;
  Std_S.push(1);
  Std_S.push(2);

  s21::stack<int> My_S1(My_S);
  std::stack<int> Std_S1(Std_S);

  ASSERT_EQ(My_S.size(), My_S1.size());
  ASSERT_EQ(My_S.top(), My_S1.top());
  ASSERT_EQ(My_S1.size(), Std_S1.size());
  ASSERT_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestConstructorCopyDbl) {
  s21::stack<double> My_S{1.4, 2.3};
  std::stack<double> Std_S;
  Std_S.push(1.4);
  Std_S.push(2.3);

  s21::stack<double> My_S1(My_S);
  std::stack<double> Std_S1(Std_S);

  ASSERT_EQ(My_S.size(), My_S1.size());
  ASSERT_DOUBLE_EQ(My_S.top(), My_S1.top());
  ASSERT_EQ(My_S1.size(), Std_S1.size());
  ASSERT_DOUBLE_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestOperatorCopyInt) {
  s21::stack<int> My_S{1, 2};
  std::stack<int> Std_S;
  Std_S.push(1);
  Std_S.push(2);

  s21::stack<int> My_S1 = My_S;
  std::stack<int> Std_S1 = Std_S;

  ASSERT_EQ(My_S.size(), My_S1.size());
  ASSERT_EQ(My_S.top(), My_S1.top());
  ASSERT_EQ(My_S1.size(), Std_S1.size());
  ASSERT_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestOperatorCopyDbl) {
  s21::stack<double> My_S{1.4, 2.3};
  std::stack<double> Std_S;
  Std_S.push(1.4);
  Std_S.push(2.3);

  s21::stack<double> My_S1 = My_S;
  std::stack<double> Std_S1 = Std_S;

  ASSERT_EQ(My_S.size(), My_S1.size());
  ASSERT_DOUBLE_EQ(My_S.top(), My_S1.top());
  ASSERT_EQ(My_S1.size(), Std_S1.size());
  ASSERT_DOUBLE_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestConstructorMoveInt) {
  s21::stack<int> My_S{1, 2};
  std::stack<int> Std_S;
  Std_S.push(1);
  Std_S.push(2);

  s21::stack<int> My_S1(std::move(My_S));
  std::stack<int> Std_S1(std::move(Std_S));

  ASSERT_EQ(My_S1.size(), Std_S1.size());
  ASSERT_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestConstructorMoveDbl) {
  s21::stack<double> My_S{1.4, 2.3};
  std::stack<double> Std_S;
  Std_S.push(1.4);
  Std_S.push(2.3);

  s21::stack<double> My_S1(std::move(My_S));
  std::stack<double> Std_S1(std::move(Std_S));

  ASSERT_EQ(My_S1.size(), Std_S1.size());
  ASSERT_DOUBLE_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestOperatorMoveInt) {
  s21::stack<int> My_S{1, 2};
  std::stack<int> Std_S;
  Std_S.push(1);
  Std_S.push(2);

  s21::stack<int> My_S1 = std::move(My_S);
  std::stack<int> Std_S1 = std::move(Std_S);

  ASSERT_EQ(My_S1.size(), Std_S1.size());
  ASSERT_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestOperatorMoveDbl) {
  s21::stack<double> My_S{1.4, 2.3};
  std::stack<double> Std_S;
  Std_S.push(1.4);
  Std_S.push(2.3);

  s21::stack<double> My_S1 = std::move(My_S);
  std::stack<double> Std_S1 = std::move(Std_S);

  ASSERT_EQ(My_S1.size(), Std_S1.size());
  ASSERT_DOUBLE_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestTopOneElementInt) {
  int v1 = 1;
  s21::stack<int> s;
  std::stack<int> s2;
  s.push(v1);
  s2.push(v1);

  ASSERT_EQ(s.top(), s2.top());
  ASSERT_EQ(s2.top(), v1);
}

TEST(Stack, TestTopOneElementDbl) {
  double v1 = 1.5;
  s21::stack<double> s;
  std::stack<double> s2;
  s.push(v1);
  s2.push(v1);

  ASSERT_EQ(s.top(), s2.top());
  ASSERT_EQ(s2.top(), v1);
}

TEST(Stack, TestTopOneElementStr) {
  std::string v1 = "OneTwo";
  s21::stack<std::string> s;
  std::stack<std::string> s2;
  s.push(v1);
  s2.push(v1);

  ASSERT_EQ(s.top(), s2.top());
  ASSERT_EQ(s2.top(), v1);
}

TEST(Stack, TestTopTwoElementsInt) {
  int v1 = 1, v2 = 5;
  s21::stack<int> s;
  s.push(v1);
  s.push(v2);

  std::stack<int> s2;
  s2.push(v1);
  s2.push(v2);

  ASSERT_EQ(s.top(), s2.top());
  ASSERT_EQ(s.top(), v2);
}

TEST(Stack, TestTopTwoElementsDbl) {
  double v1 = 1.8, v2 = 5.3;
  s21::stack<double> s;
  s.push(v1);
  s.push(v2);

  std::stack<double> s2;
  s2.push(v1);
  s2.push(v2);

  ASSERT_EQ(s.top(), s2.top());
  ASSERT_EQ(s.top(), v2);
}

TEST(Stack, TestTopTwoElementsStr) {
  std::string v1 = "One", v2 = "Two";
  s21::stack<std::string> s;
  s.push(v1);
  s.push(v2);

  std::stack<std::string> s2;
  s2.push(v1);
  s2.push(v2);

  ASSERT_EQ(s.top(), s2.top());
  ASSERT_EQ(s.top(), v2);
}

TEST(Stack, TestPushEmptyInt) {
  int v1 = 1;
  s21::stack<int> s;
  std::stack<int> s2;
  s.push(v1);
  s2.push(v1);

  ASSERT_EQ(s.top(), s2.top());
  ASSERT_EQ(s2.top(), v1);
}

TEST(Stack, TestPushEmptyDbl) {
  double v1 = 1.7;
  s21::stack<double> s;
  std::stack<double> s2;
  s.push(v1);
  s2.push(v1);

  ASSERT_EQ(s.top(), s2.top());
  ASSERT_EQ(s2.top(), v1);
}

TEST(Stack, TestPushEmptyStr) {
  std::string v1 = "One";
  s21::stack<std::string> s;
  std::stack<std::string> s2;
  s.push(v1);
  s2.push(v1);

  ASSERT_EQ(s.top(), s2.top());
  ASSERT_EQ(s2.top(), v1);
}

TEST(Stack, TestPushOneElementInt) {
  int v1 = 1, v2 = 4;
  s21::stack<int> s;
  std::stack<int> s2;
  s.push(v1);
  s.push(v2);
  s2.push(v1);
  s2.push(v2);

  ASSERT_EQ(s.top(), s2.top());
  ASSERT_EQ(s2.top(), v2);
}

TEST(Stack, TestPushOneElementDbl) {
  double v1 = 1.9, v2 = 3.5;
  s21::stack<double> s1;
  std::stack<double> s2;
  s1.push(v1);
  s1.push(v2);
  s2.push(v1);
  s2.push(v2);

  ASSERT_EQ(s1.top(), s2.top());
  ASSERT_EQ(s2.top(), v2);
}

TEST(Stack, TestPopOneElementInt) {
  int v1 = 1;
  s21::stack<int> s1;
  std::stack<int> s2;
  s1.push(v1);
  s2.push(v1);
  s1.pop();
  s2.pop();

  ASSERT_EQ(s1.size(), s2.size());
  ASSERT_EQ(s2.size(), 0);
}

TEST(Stack, TestPopOneElementDbl) {
  double v1 = 1.9;
  s21::stack<double> s1;
  std::stack<double> s2;
  s1.push(v1);
  s2.push(v1);
  s1.pop();
  s2.pop();

  ASSERT_EQ(s1.size(), s2.size());
  ASSERT_EQ(s2.size(), 0);
}

TEST(Stack, TestSwapOneElementInt) {
  int v1 = 1, v2 = 4;
  s21::stack<int> My_S, My_S1;
  std::stack<int> Std_S, Std_S1;
  My_S.push(v1);
  My_S1.push(v2);
  Std_S.push(v1);
  Std_S1.push(v2);

  My_S.swap(My_S1);
  Std_S.swap(Std_S1);

  ASSERT_EQ(My_S.size(), My_S1.size());
  ASSERT_EQ(Std_S.size(), Std_S1.size());
  ASSERT_EQ(My_S1.size(), v1);
  ASSERT_EQ(My_S.top(), Std_S.top());
  ASSERT_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestSwapOneElementDbl) {
  double v1 = 1.4, v2 = 4.3;
  s21::stack<double> My_S, My_S1;
  std::stack<double> Std_S, Std_S1;
  My_S.push(v1);
  My_S1.push(v2);
  Std_S.push(v1);
  Std_S1.push(v2);

  My_S.swap(My_S1);
  Std_S.swap(Std_S1);

  ASSERT_EQ(My_S.size(), My_S1.size());
  ASSERT_EQ(Std_S.size(), Std_S1.size());
  ASSERT_EQ(My_S1.size(), 1);
  ASSERT_EQ(My_S.top(), Std_S.top());
  ASSERT_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestSwapFourElementInt) {
  int v1[4]{1, 2, 3, 4};
  int v2[4]{5, 6, 7, 8};
  s21::stack<int> My_S, My_S1;
  std::stack<int> Std_S, Std_S1;
  for (int i = 0; i < 4; i++)
    My_S.push(v1[i]);
  for (int i = 0; i < 4; i++)
    My_S1.push(v2[i]);

  for (int i = 0; i < 4; i++)
    Std_S.push(v1[i]);
  for (int i = 0; i < 4; i++)
    Std_S1.push(v2[i]);

  My_S.swap(My_S1);
  Std_S.swap(Std_S1);

  ASSERT_EQ(My_S.size(), My_S1.size());
  ASSERT_EQ(Std_S.size(), Std_S1.size());
  ASSERT_EQ(My_S1.size(), 4);
  ASSERT_EQ(My_S.top(), Std_S.top());
  ASSERT_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestSwapFourElementDbl) {
  double v1[4]{1.5, 2.4, 3.3, 4.2};
  double v2[4]{5.4, 6.5, 7.6, 8.7};
  s21::stack<double> My_S, My_S1;
  std::stack<double> Std_S, Std_S1;
  for (int i = 0; i < 4; i++)
    My_S.push(v1[i]);
  for (int i = 0; i < 4; i++)
    My_S1.push(v2[i]);

  for (int i = 0; i < 4; i++)
    Std_S.push(v1[i]);
  for (int i = 0; i < 4; i++)
    Std_S1.push(v2[i]);

  My_S.swap(My_S1);
  Std_S.swap(Std_S1);

  ASSERT_EQ(My_S.size(), My_S1.size());
  ASSERT_EQ(Std_S.size(), Std_S1.size());
  ASSERT_EQ(My_S1.size(), 4);
  ASSERT_EQ(My_S.top(), Std_S.top());
  ASSERT_EQ(My_S1.top(), Std_S1.top());
}

TEST(Stack, TestInsertManyEmptyInt) {
  s21::stack<int> s;

  s.insert_many_back(2, 3);

  ASSERT_EQ(s.size(), 2);
  ASSERT_EQ(s.top(), 3);
}

TEST(Stack, TestInsertManyTwoElementsInt) {
  int v1 = 1, v2 = 2;
  s21::stack<int> s;
  s.push(v1);
  s.push(v2);

  s.insert_many_back(3, 4);

  ASSERT_EQ(s.size(), 4);
  ASSERT_EQ(s.top(), 4);
}