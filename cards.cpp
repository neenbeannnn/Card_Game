//cards.cpp
//Authors: Nina Huang
//Implementation of the classes defined in cards.h
#include <iostream>
#include "cards.h"
using namespace std;

//Function definitions for Player class
Player::Player(string name, CardList hand){
  this->name = name;
  this->hand = hand;
}

Player::~Player(){
}

string Player::getName() const{
  return this->name;
}

//Function definitions for CardList class
CardList::CardList(){
  this->head = nullptr;
  this->tail = nullptr;
  this->current = nullptr;
}

CardList::~CardList(){
}m

//adds card to the end of the card list
void CardList::addCard(string element){
  Card *a = new Card(element);
  Node *b = new Node();
  b->data = a;
  b->next = nullptr;
  if(this->head == nullptr){
    this->head = b;
    this->tail = head;
    this->current = head;
    return;
  }
  this->tail->next = b;
  this->tail = this->tail->next;
}

void CardList::removeCard(Card &element){
    if(this->search(element) == false)
      return;
    Node *card = findCard(this->head, element.getData());
    Node *tmp = card->next;
    //case:
    if(this->head == card){
      delete card;
      this->head = tmp;
    }
    else{
      Node *prev = findCardBefore(this->head, element.getData());
      if(this->tail == card){
        delete card;
        prev->next = nullptr;
        this->tail = prev;
      }
      else{
        prev->next = tmp;
        delete card;
      }
    }
}

// returns true if the card is found in the deck, false if not found
bool CardList::search(const Card &a) const{
  if(findCard(this->head, a.getData()))
    return true;
  return false;
}


bool CardList::moveCurrentUp(){
    if(this->current->next){
      this->current = this->current->next;
      return true;
    }
    return false;
}

Card* CardList::getCurrent() const{
  return this->current->data;
}

//sets the head card as the current card
void CardList::setCurrent(){
  this->current = this->head;
}

//private helper functions
CardList::Node* CardList::findCard(Node *root, string element) const{
  if(!root)
    return nullptr;
  if(root->data->getData() == element)
    return root;
  return findCard(root->next, element);
}

CardList::Node* CardList::findCardBefore(Node *a, string element) const{
  if(this->search(a->data->getData()) == false)
    return nullptr;
  Node *prev = this->head;
  Node *curr = this->head->next;
  while(curr){
    if(curr->data->getData() == element){
      return prev;
    }
    prev = prev->next;
    curr = curr->next;
  }
  return prev;
}
//Postconditions: returns a pointer to the Node

//Function definitions for Card class
Card::Card(string element){
  this->data = element;
  this->next = nullptr;
}

Card::~Card(){
}

string Card::getData() const{
  return data;
}

void Card::printCard(){
  cout<<this->data<<endl;
}

//Overloaded operator functions
ostream& operator<<(ostream &os, const CardList &c){
  CardList::Node *tmp = c.head;
  while(tmp){
    os<<tmp->data->getData()<<endl;
    tmp = tmp->next;
  }
  return os;
}

bool operator==(const Card &a, const Card &b){
  if(a.getData() == b.getData())
    return true;
  return false;
}
