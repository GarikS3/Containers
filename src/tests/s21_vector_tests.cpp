#include <gtest/gtest.h>

#include "../s21_vector/s21_vector.h"

TEST(Vector, TestDefaultConstructor) {
  s21::vector<char> vec;

  EXPECT_TRUE(vec.empty());
  EXPECT_EQ(vec.size(), 0);
  EXPECT_EQ(vec.capacity(), 0);
}

TEST(Vector, TestParamConctructor) {
  s21::vector<int> vec(7);

  EXPECT_EQ(vec.size(), 7);
  EXPECT_EQ(vec.capacity(), 7);
  for (size_t i = 0; i < vec.size(); ++i) {
    EXPECT_EQ(vec[i], 0);
  }
}

TEST(Vector, TestInitConstructor) {
  s21::vector<std::string> vec{"one", "two", "three"};

  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec.capacity(), 3);
  EXPECT_EQ(vec[0], "one");
  EXPECT_EQ(vec[1], "two");
  EXPECT_EQ(vec[2], "three");
}

TEST(Vector, TestCopyConstructor) {
  s21::vector<int> vec = {2, 5, 10, 22};
  s21::vector<int> copy(vec);

  EXPECT_EQ(vec.size(), copy.size());
  for (size_t i = 0; i < copy.size(); ++i) {
    EXPECT_EQ(vec[i], copy[i]);
  }
}

TEST(Vector, TestMoveConstructor) {
  s21::vector<int> vec = {10, 25, 33, 41, 68};
  s21::vector<int> moved(std::move(vec));

  EXPECT_TRUE(vec.empty());
  EXPECT_EQ(moved.size(), 5);
  EXPECT_EQ(moved[0], 10);
  EXPECT_EQ(moved[1], 25);
  EXPECT_EQ(moved[2], 33);
  EXPECT_EQ(moved[3], 41);
  EXPECT_EQ(moved[4], 68);
}

TEST(Vector, TestAssignmentOperator1) {
  s21::vector<float> vec1 = {1.1, 3.3, 5.5, 7.7, 9.9};
  s21::vector<float> vec2 = {1.0, 2.0, 3.0};
  vec1 = std::move(vec2);

  EXPECT_TRUE(vec2.empty());
  EXPECT_EQ(vec1.size(), 3);
  EXPECT_EQ(vec1[0], 1.0);
  EXPECT_EQ(vec1[1], 2.0);
  EXPECT_EQ(vec1[2], 3.0);
}

TEST(Vector, TestAssignmentOperator2) {
  s21::vector<int> vec1;
  s21::vector<int> vec2 = {3, 5, 8};
  vec1 = std::move(vec2);

  EXPECT_TRUE(vec2.empty());
  EXPECT_EQ(vec1.size(), 3);
  EXPECT_EQ(vec1[0], 3);
  EXPECT_EQ(vec1[1], 5);
  EXPECT_EQ(vec1[2], 8);
}

TEST(Vector, TestAssignmentOperator3) {
  s21::vector<int> vec1 = {3, 5, 8};
  s21::vector<int> vec2;
  vec1 = std::move(vec2);

  EXPECT_TRUE(vec1.empty());
  EXPECT_TRUE(vec2.empty());
}

TEST(Vector, TestAt1) {
  s21::vector<int> vec{1, 4, 8};

  EXPECT_EQ(vec.at(0), 1);
  EXPECT_EQ(vec.at(1), 4);
  EXPECT_EQ(vec.at(2), 8);
}

TEST(Vector, TestAt2) {
  s21::vector<std::string> vec{"a", "b", "c"};
  EXPECT_NO_THROW(vec.at(0));
  EXPECT_THROW(vec.at(5), std::out_of_range);
  EXPECT_THROW(vec.at(-2), std::out_of_range);
}

TEST(Vector, TestOperatorBrackets1) {
  s21::vector<int> vec{123, 234, 345, 456};

  EXPECT_EQ(vec[0], 123);
  EXPECT_EQ(vec[1], 234);
  EXPECT_EQ(vec[2], 345);
  EXPECT_EQ(vec[3], 456);
}

TEST(Vector, TestOperatorBrackets2) {
  s21::vector<int> vec{1, 2, 3};

  vec[1] = 1000;
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 1000);
  EXPECT_EQ(vec[2], 3);
}

TEST(Vector, TestFront) {
  s21::vector<int> vec = {10, 20, 30, 40, 50};
  EXPECT_EQ(vec.front(), 10);
}

TEST(Vector, TestBack) {
  s21::vector<int> vec = {10, 20, 30, 40, 50};
  EXPECT_EQ(vec.back(), 50);
}

TEST(Vector, TestAccessToArray) {
  s21::vector<int> vec{10, 20, 30};
  int *ptr = vec.data();

  EXPECT_EQ(ptr[0], 10);
  EXPECT_EQ(ptr[1], 20);
  EXPECT_EQ(ptr[2], 30);
}

TEST(Vector, TestEmpty1) {
  s21::vector<int> vec;
  EXPECT_EQ(vec.empty(), true);
}

TEST(Vector, TestEmpty2) {
  s21::vector<int> vector{15, 35, 46};
  EXPECT_EQ(vector.empty(), false);
}

TEST(Vector, TestSize) {
  s21::vector<int> vector{11, 15, 34, 155, 3};
  EXPECT_EQ(vector.size(), 5);
}

TEST(Vector, TestCapacity) {
  s21::vector<int> vector{11, 15, 34};
  EXPECT_EQ(vector.capacity(), 3);
}

TEST(Vector, TestReserve1) {
  s21::vector<int> vec{1, 2, 3};
  vec.reserve(10);

  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec.capacity(), 10);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
}

TEST(Vector, TestReserve2) {
  s21::vector<int> vec(10);
  vec.reserve(5);

  EXPECT_EQ(vec.capacity(), 10);
}

TEST(Vector, TestClear) {
  s21::vector<double> vec{123.55, 8.15, 26.488, 55.1, 64.0};
  vec.clear();
  EXPECT_EQ(vec.empty(), true);
}

TEST(Vector, TestInsert1) {
  s21::vector<int> vec{1, 2, 3};
  auto it = vec.insert(vec.begin(), 10);

  EXPECT_EQ(vec.size(), 4);
  EXPECT_EQ(*it, 10);
  EXPECT_EQ(vec[0], 10);
  EXPECT_EQ(vec[1], 1);
  EXPECT_EQ(vec[2], 2);
  EXPECT_EQ(vec[3], 3);
}

TEST(Vector, TestInsert2) {
  s21::vector<int> vec{1, 2, 3};
  auto it = vec.insert(vec.end(), 10);

  EXPECT_EQ(vec.size(), 4);
  EXPECT_EQ(*it, 10);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 10);
}

TEST(Vector, TestInsert3) {
  s21::vector<int> vec{1, 2, 3, 4};
  auto it = vec.insert(vec.begin() + 2, 10);

  EXPECT_EQ(vec.size(), 5);
  EXPECT_EQ(*it, 10);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 10);
  EXPECT_EQ(vec[3], 3);
  EXPECT_EQ(vec[4], 4);
}

TEST(Vector, TestInsertAfterEnd) {
  s21::vector<double> vec{11.0, 22.0, 33.0};
  EXPECT_THROW(vec.insert(vec.end() + 1, 44.0), std::out_of_range);
}

TEST(Vector, TestErase1) {
  s21::vector<int> vec = {10, 20, 30};
  vec.erase(vec.begin());

  EXPECT_EQ(vec.size(), 2);
  EXPECT_EQ(vec[0], 20);
  EXPECT_EQ(vec[1], 30);
}

TEST(Vector, TestErase2) {
  s21::vector<int> vec{11, 22, 33};
  vec.erase(vec.end() - 1);

  EXPECT_EQ(vec.size(), 2);
  EXPECT_EQ(vec[0], 11);
  EXPECT_EQ(vec[1], 22);
}

TEST(Vector, TestErase3) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  vec.erase(vec.begin() + 2);

  EXPECT_EQ(vec.size(), 4);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  ;
  EXPECT_EQ(vec[2], 4);
  EXPECT_EQ(vec[3], 5);
}

TEST(Vector, TestErase4) {
  s21::vector<double> vec{11.0, 22.0, 33.0};
  EXPECT_THROW(vec.erase(vec.end()), std::out_of_range);
}

TEST(Vector, TestTestPushBack1) {
  s21::vector<int> vec = {10};
  vec.push_back(20);
  vec.push_back(30);

  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec[0], 10);
  EXPECT_EQ(vec[1], 20);
  EXPECT_EQ(vec[2], 30);
}

TEST(Vector, TestPushBack2) {
  s21::vector<int> vec;
  vec.push_back(1000);

  EXPECT_EQ(vec.size(), 1);
  EXPECT_EQ(vec[0], 1000);
}

TEST(Vector, TestPopBack1) {
  s21::vector<int> vec = {10, 50, 80, 95};
  vec.pop_back();
  vec.pop_back();

  EXPECT_EQ(vec.size(), 2);
  EXPECT_EQ(vec[0], 10);
  EXPECT_EQ(vec[1], 50);
}

TEST(Vector, TestPopBack2) {
  s21::vector<std::string> vec;
  vec.pop_back();

  EXPECT_EQ(vec.size(), 0);
  EXPECT_EQ(vec.capacity(), 0);
}

TEST(Vector, TestSwap1) {
  s21::vector<int> vec1 = {1, 2, 3};
  s21::vector<int> vec2 = {10, 20, 30, 40};
  vec1.swap(vec2);

  EXPECT_EQ(vec1.size(), 4);
  EXPECT_EQ(vec1.front(), 10);
  EXPECT_EQ(vec1.back(), 40);

  EXPECT_EQ(vec2.size(), 3);
  EXPECT_EQ(vec2.front(), 1);
  EXPECT_EQ(vec2.back(), 3);
}

TEST(Vector, TestSwap2) {
  s21::vector<int> vec1 = {1, 2, 3};
  s21::vector<int> vec2;
  vec1.swap(vec2);

  EXPECT_EQ(vec1.empty(), true);
  EXPECT_EQ(vec2.size(), 3);
  EXPECT_EQ(vec2.front(), 1);
  EXPECT_EQ(vec2.back(), 3);
}

TEST(Vector, TestInsertMany1) {
  s21::vector<int> vec = {1, 2, 5, 6};
  auto it = vec.insert_many(vec.begin() + 2, 3, 4);
  EXPECT_EQ(vec.size(), 6);
  EXPECT_EQ(*it, 3);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
}

TEST(Vector, TestInsertMany2) {
  s21::vector<std::string> vec = {"d", "e"};
  auto it = vec.insert_many(vec.begin(), "a", "b", "c");

  EXPECT_EQ(vec.size(), 5);
  EXPECT_EQ(it, vec.begin());
  EXPECT_EQ(vec[0], "a");
  EXPECT_EQ(vec[1], "b");
  EXPECT_EQ(vec[2], "c");
  EXPECT_EQ(vec[3], "d");
  EXPECT_EQ(vec[4], "e");
}

TEST(Vector, TestInsertManyBack1) {
  s21::vector<int> vec = {10, 20};
  vec.insert_many_back(30, 40, 50);

  EXPECT_EQ(vec.size(), 5);
  EXPECT_EQ(vec[0], 10);
  EXPECT_EQ(vec[1], 20);
  EXPECT_EQ(vec[2], 30);
  EXPECT_EQ(vec[3], 40);
  EXPECT_EQ(vec[4], 50);
}

TEST(Vector, TestInsertManyBack2) {
  s21::vector<int> vec;
  vec.insert_many_back(1, 2, 3);

  EXPECT_EQ(vec.size(), 3);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
}