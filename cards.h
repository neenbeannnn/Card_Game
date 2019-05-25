//cards.h
//Authors: Nina Huang
//All class declarations go here
#include <iostream>
using namespace std;

#ifndef CARDS_H
#define CARDS_H

class Card{
public:
  Card(string element);
  ~Card();
  string getData() const;
  void printCard();
  friend bool operator==(const Card &a, const Card &b);
private:
  string data;
  Card *next;
};

class CardList{
public:
  CardList();
  ~CardList();
  void addCard(string element);
  void removeCard(Card &element);
  bool search(const Card &a) const;
  bool moveCurrentUp();
  Card* getCurrent() const;
  void setCurrent();
  friend ostream& operator<<(ostream &os, const CardList &c);
private:
  //private member variables
  struct Node{
    Card *data;
    Node *next;
  };
  Node *current;
  Node *head;
  Node *tail;

  Node* findCard(Node *root, string element) const;
  Node* findCardBefore(Node *a, string element) const;
};

class Player{
public:
  Player(string name, CardList hand);
  ~Player();
  string getName() const;

private:
  string name;
  CardList hand;
};


#endif

// Use this file to define all your classes and public functions
// You should design your program with OOP prinicples using classes
// An example of class design would be having Card, CardList and Player as Classes.
// Card represent Node in your LinkedList which has some data in it
// CardList can be your LinkedList Class which has operations such as append, remove etc
// Player class represents your game player
// Think about the public functions that should be part of each class. (All public function need to be tested in unit testing)
// One of the important functions is search / find which is essential for players to find cars in their opponent's "hand"
// Make sure you overload the desired operators
// This is not the fixed design. We are not expecting exactly 3 classes. You can do with less or more.
// Important thing to consider is abstraction.
