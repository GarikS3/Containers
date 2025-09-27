#include "../s21_array/s21_array.h"

#include <gtest/gtest.h>

TEST(Array, TestDefaultConstructor) {
  s21::array<int, 10> ar;
  EXPECT_EQ(ar.size(), 10);
  for (size_t i = 0; i < ar.size(); ++i) {
    EXPECT_EQ(ar[i], 0);
  }
}

TEST(Array, InitConstructor) {
  s21::array<int, 5> arr1 = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr1.size(), 5);
  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], static_cast<int>(i + 1));
  }
}

TEST(Array, TestCopyConstructor) {
  s21::array<double, 5> ar1 = {1.1, 2.2, 3.3, 4.4, 5.5};
  s21::array<double, 5> ar2(ar1);

  EXPECT_EQ(ar1.size(), ar2.size());
  for (size_t i = 0; i < ar1.size(); ++i) {
    EXPECT_DOUBLE_EQ(ar1[i], ar2[i]);
  }
}

TEST(Array, TestMoveConstructor) {
  s21::array<int, 4> arr1 = {1, 2, 3, 4};
  s21::array<int, 4> arr2(std::move(arr1));

  for (size_t i = 0; i < arr2.size(); ++i) {
    EXPECT_EQ(arr2[i], static_cast<int>(i + 1));
  }

  for (size_t i = 0; i < arr1.size(); ++i) {
    EXPECT_EQ(arr1[i], 0);
  }
}

TEST(Array, TestCopyAssignment) {
  s21::array<int, 4> ar1 = {1, 2, 3, 4};
  s21::array<int, 4> ar2;
  ar2 = ar1;

  EXPECT_EQ(ar2[0], 1);
  EXPECT_EQ(ar2[1], 2);
  EXPECT_EQ(ar2[2], 3);
  EXPECT_EQ(ar2[3], 4);
}

TEST(Array, MoveAssignment) {
  s21::array<std::string, 3> ar1 = {"a", "b", "c"};
  s21::array<std::string, 3> ar2;
  ar2 = std::move(ar1);

  EXPECT_EQ(ar2[0], "a");
  EXPECT_EQ(ar2[1], "b");
  EXPECT_EQ(ar2[2], "c");

  EXPECT_TRUE(ar1[0].empty());
  EXPECT_TRUE(ar1[1].empty());
  EXPECT_TRUE(ar1[2].empty());
}

TEST(Array, TestAt1) {
  s21::array<int, 3> ar = {1, 4, 8};

  EXPECT_EQ(ar.at(0), 1);
  EXPECT_EQ(ar.at(1), 4);
  EXPECT_EQ(ar.at(2), 8);
}

TEST(Array, TestAt2) {
  s21::array<std::string, 3> ar = {"a", "b", "c"};
  EXPECT_NO_THROW(ar.at(0));
  EXPECT_THROW(ar.at(5), std::out_of_range);
  EXPECT_THROW(ar.at(-2), std::out_of_range);
}

TEST(Array, TestOperatorBrackets1) {
  s21::array<int, 4> ar = {123, 234, 345, 456};

  EXPECT_EQ(ar[0], 123);
  EXPECT_EQ(ar[1], 234);
  EXPECT_EQ(ar[2], 345);
  EXPECT_EQ(ar[3], 456);
}

TEST(Array, TestOperatorBrackets2) {
  s21::array<int, 3> ar = {1, 2, 3};

  ar[1] = 1000;
  EXPECT_EQ(ar[0], 1);
  EXPECT_EQ(ar[1], 1000);
  EXPECT_EQ(ar[2], 3);
}

TEST(Array, TestFront) {
  s21::array<int, 3> ar = {11, 23, 34};
  EXPECT_EQ(ar.front(), 11);
}

TEST(Array, TestBack) {
  s21::array<int, 3> ar = {11, 23, 34};
  EXPECT_EQ(ar.back(), 34);
}

TEST(Array, TestData) {
  s21::array<int, 3> ar = {10, 20, 30};
  int *ptr = ar.data();

  EXPECT_EQ(ar[0], 10);
  EXPECT_EQ(ar[1], 20);
  EXPECT_EQ(ar[2], 30);
  ptr[1] = 1000;
  EXPECT_EQ(ar[1], 1000);
}

TEST(Array, TestBeginEnd1) {
  s21::array<int, 5> ar = {10, 20, 30, 40, 50};
  auto it_begin = ar.begin();
  auto it_end = ar.end();

  EXPECT_EQ(*it_begin, 10);
  EXPECT_EQ(*(it_end - 1), 50);
}

TEST(Array, TestBeginEnd2) {
  s21::array<int, 6> arr = {0, 1, 2, 3, 4, 5};
  auto it1 = arr.begin() + 2;
  auto it2 = arr.end() - 3;

  EXPECT_EQ(*it1, 2);
  EXPECT_EQ(*it2, 3);
}

TEST(Array, TestEmpty1) {
  s21::array<int, 5> ar = {11, 15, 34, 155, 3};
  EXPECT_FALSE(ar.empty());
}

TEST(Array, TestEmpty2) {
  s21::array<int, 0> ar;
  EXPECT_TRUE(ar.empty());
}

TEST(Array, TestSize) {
  s21::array<int, 5> ar = {11, 15, 34, 155, 3};
  EXPECT_EQ(ar.size(), 5);
}

TEST(Array, TestSwap1) {
  s21::array<int, 3> ar1 = {1, 2, 3};
  s21::array<int, 3> ar2 = {10, 20, 30};
  ar1.swap(ar2);

  EXPECT_EQ(ar1[0], 10);
  EXPECT_EQ(ar1[1], 20);
  EXPECT_EQ(ar1[2], 30);

  EXPECT_EQ(ar2[0], 1);
  EXPECT_EQ(ar2[1], 2);
  EXPECT_EQ(ar2[2], 3);
}

TEST(Array, TestSwap2) {
  s21::array<std::string, 3> ar1 = {"a", "b", "c"};
  s21::array<std::string, 3> ar2;
  ar1.swap(ar2);

  EXPECT_TRUE(ar1[0].empty());
  EXPECT_TRUE(ar1[1].empty());
  EXPECT_TRUE(ar1[2].empty());

  EXPECT_EQ(ar2[0], "a");
  EXPECT_EQ(ar2[1], "b");
  EXPECT_EQ(ar2[2], "c");
}

TEST(Array, TestFill1) {
  s21::array<int, 7> ar;
  ar.fill(1234);

  for (size_t i = 0; i < ar.size(); ++i) {
    EXPECT_EQ(ar[i], 1234);
  }
}

TEST(Array, Fill2) {
  s21::array<std::string, 3> ar;
  ar.fill("abc");

  for (size_t i = 0; i < ar.size(); ++i) {
    EXPECT_EQ(ar[i], "abc");
  }
}