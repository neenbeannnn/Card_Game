// This file should contain unit tests for all the
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

// A test case to append a single card node to a CardList
void testAppend_case1(){
  string testname = "testAppend_case1";
  string expected = "s 3";
  CardList actual;
  actual.addCard("s 3");
  cout<<testname<<": "<<endl;
  cout<<"Expected: "<<expected<<endl;
  cout<<"Actual: "<<actual<<endl;
}

//A test case to append multiple nodes to a CardList
void testAppend_case2(){
  string testname = "testAppend_case2";
  string expected = "s 3\nh 9\ns 10";
  CardList actual;
  actual.addCard("s 3");
  actual.addCard("h 9");
  actual.addCard("s 10");
  cout<<testname<<": "<<endl;
  cout<<"Expected: "<<expected<<endl;
  cout<<"Actual: "<<actual<<endl;
}

//A test case to remove 1 card from a CardList with 1 node
void testRemove_case1(){
  string testname = "testRemove_case1";
  string expected = " ";
  CardList actual;
  actual.addCard("s 3");
  Card toBeRemoved = Card("s 3");
  actual.removeCard(toBeRemoved);
  cout<<testname<<": "<<endl;
  cout<<"Expected: "<<expected<<endl;
  cout<<"Actual: "<<actual<<endl;
}

//A test case to remove 1 card from a CardList with multiple nodes
void testRemove_case2(){
  string testname = "testRemove_case2";
  string expected = "h 9";
  CardList actual;
  actual.addCard("s 3");
  actual.addCard("h 9");
  Card toBeRemoved = Card("s 3");
  actual.removeCard(toBeRemoved);
  cout<<testname<<": "<<endl;
  cout<<"Expected: "<<expected<<endl;
  cout<<"Actual: "<<actual<<endl;
}

//A test case to remove multiple cards from a CardList with multiple nodes
void testRemove_case3(){
  string testname = "testRemove_case3";
  string expected = "h 9";
  CardList actual;
  actual.addCard("s 3");
  actual.addCard("h 9");
  actual.addCard("s 10");
  Card toBeRemoved = Card("s 3");
  Card toBeRemoved2 = Card("s 10");
  actual.removeCard(toBeRemoved);
  actual.removeCard(toBeRemoved2);
  cout<<testname<<": "<<endl;
  cout<<"Expected: "<<expected<<endl;
  cout<<"Actual: "<<actual<<endl;
}

//A test case to search for a node that is not present in a CardList with multiple cards
void testSearch_case1(){
  string testname = "testSearch_case1";
  bool expected = false;
  CardList actual;
  actual.addCard("s 3");
  actual.addCard("h 9");
  actual.addCard("s 10");
  Card toSearchFor = Card("h 10");
  bool result = actual.search(toSearchFor);
  assertEquals(result, expected, testname);
}

//A test case to search for a node that is present in a CardList with multiple cards
void testSearch_case2(){
  string testname = "testSearch_case1";
  bool expected = true;
  CardList actual;
  actual.addCard("s 3");
  actual.addCard("h 9");
  actual.addCard("s 10");
  Card toSearchFor = Card("s 10");
  bool result = actual.search(toSearchFor);
  assertEquals(result, expected, testname);
}

//A test case of the == operator on 2 cards that are not equal
void testDoubleEqualOperator_case1(){
  string testname = "testDoubleEqualOperator_case1";
  bool expected = false;
  Card a = Card("s 4");
  Card b = Card("s 5");
  bool actual = (a==b);
  assertEquals(actual, expected, testname);
}

//A test case of the == operator on 2 cards that are equal
void testDoubleEqualOperator_case2(){
  string testname = "testDoubleEqualOperator_case2";
  bool expected = true;
  Card a = Card("s 4");
  Card b = Card("s 4");
  bool actual = (a==b);
  assertEquals(actual, expected, testname);
}

void runAll(){
  testAppend_case1();
  testAppend_case2();
  testRemove_case1();
  testRemove_case2();
  testRemove_case3();
  testSearch_case1();
  testSearch_case2();
  testDoubleEqualOperator_case1();
  testDoubleEqualOperator_case2();
}

int main(){
  runAll();
  return 0;
}
