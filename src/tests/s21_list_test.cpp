#include "../s21_list/s21_list.h"

#include <gtest/gtest.h>

TEST(List, TestDefaultConstructor) {
  s21::list<int> lst;

  EXPECT_TRUE(lst.empty());
  EXPECT_EQ(lst.size(), 0);
  EXPECT_EQ(lst.begin(), lst.end());
}

TEST(List, TestParamConstructor) {
  s21::list<int> lst = {1, 2, 3, 4};

  EXPECT_EQ(lst.size(), 4);
  EXPECT_EQ(lst.front(), 1);
  EXPECT_EQ(lst.back(), 4);
}

TEST(List, TestCopyConstructor) {
  s21::list<int> lst = {2, 5, 10};
  s21::list<int> copy(lst);

  EXPECT_EQ(lst.size(), copy.size());
  EXPECT_EQ(lst.front(), copy.front());
  EXPECT_EQ(lst.back(), copy.back());
}

TEST(List, TestMoveConstructor) {
  s21::list<int> lst = {10, 25, 33, 41, 68};
  s21::list<int> moved(std::move(lst));

  EXPECT_TRUE(lst.empty());
  EXPECT_EQ(moved.size(), 5);
  EXPECT_EQ(moved.front(), 10);
  EXPECT_EQ(moved.back(), 68);
}

TEST(List, TestAssignmentOperator1) {
  s21::list<int> list1;
  s21::list<int> list2 = {3, 5, 8};
  list1 = std::move(list2);

  EXPECT_EQ(list1.size(), 3);
  EXPECT_TRUE(list2.empty());
  EXPECT_EQ(list1.front(), 3);
  EXPECT_EQ(list1.back(), 8);
}

TEST(List, TestAssignmentOperator3) {
  s21::list<int> list1 = {3, 5, 8};
  s21::list<int> list2;
  list1 = std::move(list2);

  EXPECT_TRUE(list1.empty());
  EXPECT_TRUE(list2.empty());
}

TEST(List, TestAssignmentOperator2) {
  s21::list<float> list1 = {1.1, 3.3, 5.5, 7.7, 9.9};
  s21::list<float> list2 = {1.0, 2.0, 3.0};
  list1 = std::move(list2);

  EXPECT_EQ(list1.size(), 3);
  EXPECT_TRUE(list2.empty());
  EXPECT_EQ(list1.front(), 1.0);
  EXPECT_EQ(list1.back(), 3.0);
}

TEST(List, TestFront) {
  s21::list<float> lst{2.5, 4.3, 3.1, 4.7, 5.8};
  EXPECT_EQ(lst.front(), 2.5);
}

TEST(List, TestBack) {
  s21::list<float> lst{5.0, 4.0, 3.0, 2.0, 1.0};
  EXPECT_EQ(lst.back(), 1.0);
}

TEST(List, TestBegin) {
  s21::list<int> list = {1, 2, 3};
  auto it = list.begin();
  EXPECT_EQ(*it, 1);
}

TEST(List, TestEnd) {
  s21::list<int> lst = {5, 6, 7};

  auto it = lst.begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(it, lst.end());
}

TEST(List, TestEmpty) {
  s21::list<int> lst;
  EXPECT_EQ(lst.empty(), true);
}

TEST(List, TestEmpty2) {
  s21::list<int> lst{1, 2, 3};
  EXPECT_EQ(lst.empty(), false);
}

TEST(List, TestSize) {
  s21::list<int> lst{1, 2, 3, 4};
  EXPECT_EQ(lst.size(), 4);
}

TEST(List, TestClear) {
  s21::list<int> lst{123, 8, 26, 554, 64};
  lst.clear();

  EXPECT_TRUE(lst.empty());
  EXPECT_EQ(lst.size(), 0);
}

TEST(List, TestInsert1) {
  s21::list<int> lst = {22, 33};
  auto it = lst.insert(lst.begin(), 11);

  EXPECT_EQ(lst.size(), 3);
  EXPECT_EQ(*it, 11);
  EXPECT_EQ(lst.front(), 11);
  EXPECT_EQ(*(++it), 22);
}

TEST(List, TestInsert2) {
  s21::list<int> lst = {1, 3, 4};
  auto inserted_it = lst.insert(++lst.begin(), 2);

  EXPECT_EQ(*inserted_it, 2);
  EXPECT_EQ(lst.size(), 4);
  auto it = lst.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
}

TEST(List, TestErase1) {
  s21::list<int> lst = {1, 2, 3, 4};
  lst.erase(++lst.begin());
  auto it = lst.begin();

  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
}

TEST(List, TestErase2) {
  s21::list<int> lst = {1, 2, 3};
  lst.erase(lst.begin());
  lst.erase(lst.begin());
  lst.erase(lst.begin());

  EXPECT_TRUE(lst.empty());
  EXPECT_EQ(lst.begin(), lst.end());
}

TEST(List, TestPushBack1) {
  s21::list<int> lst = {1, 2, 3};
  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);

  EXPECT_EQ(lst.size(), 6);
  EXPECT_EQ(lst.front(), 1);
  EXPECT_EQ(lst.back(), 30);
}

TEST(List, TestPushBack2) {
  s21::list<int> lst;
  lst.push_back(5);
  lst.push_back(15);
  lst.push_back(25);

  EXPECT_EQ(lst.size(), 3);
  EXPECT_EQ(lst.front(), 5);
  EXPECT_EQ(lst.back(), 25);
}

TEST(List, TestPopBack1) {
  s21::list<int> lst = {10, 20, 30};
  lst.pop_back();

  EXPECT_EQ(lst.size(), 2);
  EXPECT_EQ(lst.front(), 10);
  EXPECT_EQ(lst.back(), 20);
}

TEST(List, TestPopBack2) {
  s21::list<float> lst = {1234.5};
  lst.pop_back();

  EXPECT_EQ(lst.size(), 0);
  EXPECT_TRUE(lst.empty());
}

TEST(List, TestPushFront1) {
  s21::list<int> lst = {1, 2, 3};
  lst.push_front(10);
  lst.push_front(20);
  lst.push_front(30);

  EXPECT_EQ(lst.size(), 6);
  EXPECT_EQ(lst.front(), 30);
  EXPECT_EQ(lst.back(), 3);
}

TEST(List, TestPushFront2) {
  s21::list<int> lst;
  lst.push_front(3);
  lst.push_front(13);
  lst.push_front(23);

  EXPECT_EQ(lst.size(), 3);
  EXPECT_EQ(lst.front(), 23);
  EXPECT_EQ(lst.back(), 3);
}

TEST(List, TestPopFront1) {
  s21::list<int> lst = {33, 44, 55};
  lst.pop_front();

  EXPECT_EQ(lst.size(), 2);
  EXPECT_EQ(lst.front(), 44);
  EXPECT_EQ(lst.back(), 55);
}

TEST(List, TestPopFront2) {
  s21::list<int> lst = {100};
  lst.pop_front();

  EXPECT_EQ(lst.size(), 0);
  EXPECT_TRUE(lst.empty());
}

TEST(List, TestSwap1) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2 = {10, 20, 30, 40};
  list1.swap(list2);

  EXPECT_EQ(list1.size(), 4);
  EXPECT_EQ(list1.front(), 10);
  EXPECT_EQ(list1.back(), 40);

  EXPECT_EQ(list2.size(), 3);
  EXPECT_EQ(list2.front(), 1);
  EXPECT_EQ(list2.back(), 3);
}

TEST(List, TestSwap2) {
  s21::list<int> list1 = {1, 2, 3};
  s21::list<int> list2;
  list1.swap(list2);

  EXPECT_EQ(list1.empty(), true);
  EXPECT_EQ(list2.size(), 3);
  EXPECT_EQ(list2.front(), 1);
  EXPECT_EQ(list2.back(), 3);
}

TEST(List, TestMerge1) {
  s21::list<int> list1 = {11, 33, 55};
  s21::list<int> list2 = {22, 44, 66};
  list1.merge(list2);

  EXPECT_TRUE(list2.empty());
  EXPECT_EQ(list1.size(), 6);
  auto it = list1.begin();
  EXPECT_EQ(*it++, 11);
  EXPECT_EQ(*it++, 22);
  EXPECT_EQ(*it++, 33);
  EXPECT_EQ(*it++, 44);
  EXPECT_EQ(*it++, 55);
  EXPECT_EQ(*it++, 66);
}

TEST(List, TestMerge2) {
  s21::list<int> list1;
  s21::list<int> list2 = {10, 20, 30};
  list1.merge(list2);

  auto it = list1.begin();
  EXPECT_EQ(*it++, 10);
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(*it++, 30);
  EXPECT_TRUE(list2.empty());
}

TEST(List, TestMerge3) {
  s21::list<int> lst = {1, 2, 3};
  lst.merge(lst);

  EXPECT_EQ(lst.size(), 3);
  EXPECT_EQ(lst.front(), 1);
  EXPECT_EQ(lst.back(), 3);
}

TEST(List, TestSplice1) {
  s21::list<int> list1;
  s21::list<int> list2 = {1, 2, 3};
  list1.splice(list1.begin(), list2);

  auto it = list1.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(list1.size(), 3);
  EXPECT_TRUE(list2.empty());
}

TEST(List, TestSplice2) {
  s21::list<int> list1 = {1, 2};
  s21::list<int> list2 = {3, 4};
  list1.splice(list1.end(), list2);

  auto it = list1.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(list1.size(), 4);
  EXPECT_TRUE(list2.empty());
}

TEST(List, TestSplice3) {
  s21::list<int> list1 = {1, 2, 5};
  s21::list<int> list2 = {3, 4};
  auto it = ++ ++list1.begin();
  list1.splice(it, list2);

  it = list1.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(list1.size(), 5);
  EXPECT_TRUE(list2.empty());
}

TEST(List, TestReverse1) {
  s21::list<int> lst = {5, 4, 3, 2, 1};
  lst.reverse();

  EXPECT_EQ(lst.size(), 5);
  auto it = lst.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
}

TEST(List, TestReverse2) {
  s21::list<int> list = {45466};
  list.reverse();

  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.front(), 45466);
}

TEST(List, TestUnique1) {
  s21::list<int> lst = {1, 1, 2, 3, 3, 3, 4, 4, 5};
  lst.unique();

  EXPECT_EQ(lst.size(), 5);
  auto it = lst.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
}

TEST(List, TestUnique2) {
  s21::list<int> lst = {5, 5, 5, 1, 3, 3};
  lst.unique();

  EXPECT_EQ(lst.size(), 3);
  auto it = lst.begin();
  EXPECT_EQ(*it++, 5);
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 3);
}

TEST(List, TestSort1) {
  s21::list<int> lst;
  lst.push_back(3);
  lst.push_back(2);
  lst.push_back(1);
  lst.sort();

  auto it = lst.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
}

TEST(List, TestSort2) {
  s21::list<int> lst = {38, 12, 43, 26};
  lst.sort();

  auto it = lst.begin();
  EXPECT_EQ(*it++, 12);
  EXPECT_EQ(*it++, 26);
  EXPECT_EQ(*it++, 38);
  EXPECT_EQ(*it++, 43);
}

TEST(List, TestSort3) {
  s21::list<int> lst = {5, 1, 2, 3, 2, 1};
  lst.sort();

  auto it = lst.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 5);
}

TEST(List, TestSort4) {
  s21::list<int> lst = {10, 20, 30};
  lst.sort();

  auto it = lst.begin();
  EXPECT_EQ(*it++, 10);
  EXPECT_EQ(*it++, 20);
  EXPECT_EQ(*it++, 30);
}

TEST(List, TestInsertMany1) {
  s21::list<int> lst = {1, 4};
  lst.insert_many(++lst.begin(), 2, 3);

  EXPECT_EQ(lst.size(), 4);
  auto it = lst.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
}

TEST(List, TestInsertMany2) {
  s21::list<std::string> lst;
  lst.insert_many(lst.begin(), "Hello", "world");

  EXPECT_EQ(lst.size(), 2);
  EXPECT_EQ(lst.front(), "Hello");
  EXPECT_EQ(lst.back(), "world");
}

TEST(List, TestInsertMany3) {
  s21::list<int> lst = {1, 2};
  auto it = lst.insert_many(++lst.begin());

  EXPECT_EQ(lst.size(), 2);
  EXPECT_EQ(*it, 2);
}

TEST(List, TestInsertManyBack1) {
  s21::list<int> lst = {1, 2};
  lst.insert_many_back(3, 4, 5);

  EXPECT_EQ(lst.size(), 5);
  auto it = lst.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
}

TEST(List, TestInsertManyBack2) {
  s21::list<int> lst;
  lst.insert_many_back(1, 2, 3);

  EXPECT_EQ(lst.size(), 3);
  auto it = lst.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
}

TEST(List, InsertManyFront1) {
  s21::list<int> lst = {4, 5};
  lst.insert_many_front(1, 2, 3);

  EXPECT_EQ(lst.size(), 5);
  auto it = lst.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
  EXPECT_EQ(*it++, 4);
  EXPECT_EQ(*it++, 5);
}

TEST(List, InsertManyFront2) {
  s21::list<int> lst;
  lst.insert_many_front(1, 2, 3);

  EXPECT_EQ(lst.size(), 3);
  auto it = lst.begin();
  EXPECT_EQ(*it++, 1);
  EXPECT_EQ(*it++, 2);
  EXPECT_EQ(*it++, 3);
}
