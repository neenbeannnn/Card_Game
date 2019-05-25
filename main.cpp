#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

void endGame(Player *p1, CardList &a, Player *p2, CardList &b);

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }

  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined
  // to contain two sets of cards in two input files
  CardList cardList1;
  CardList cardList2;
  bool player1turn = true;
  bool player2turn = false;
  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
    cardList1.addCard(line);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    cardList2.addCard(line);
  }
  cardFile2.close();

  cardList1.setCurrent();
  cardList2.setCurrent();

  Player *player1 = new Player("Alice", cardList1);
  Player *player2 = new Player("Bob", cardList2);
  Card *player1Card, *player2Card;

  while(cardList1.getCurrent() && cardList2.getCurrent()){
    while(player1turn){
      player1Card = cardList1.getCurrent();
      if(cardList2.search(*player1Card)){
        cout<<player1->getName()<<" picked matching card ";
        player1Card->printCard();
        if(cardList1.moveCurrentUp() == false){
          cardList1.removeCard(*player1Card);
          cardList2.removeCard(*player1Card);
          endGame(player1, cardList1, player2, cardList2);
          return 0;
        }
        cardList1.removeCard(*player1Card);
        cardList2.removeCard(*player1Card);
        player1turn = false;
        player2turn = true;
      }
      else{
          cardList1.moveCurrentUp();
      }
    }
    if(cardList1.getCurrent() == nullptr){
      player1turn = false;
      player2turn = false;
    }
    player1turn = false;
    player2turn = true;
    while(player2turn){
      player2Card = cardList2.getCurrent();
      if(cardList1.search(*player2Card)){
        cout<<player2->getName()<<" picked matching card ";
        player2Card->printCard();
        if(cardList2.moveCurrentUp() == false){
          cardList1.removeCard(*player2Card);
          cardList2.removeCard(*player2Card);
          endGame(player1, cardList1, player2, cardList2);
          return 0;
        }
        cardList1.removeCard(*player2Card);
        cardList2.removeCard(*player2Card);
        player1turn = true;
        player2turn = false;
      }
      else{
        cardList2.moveCurrentUp();
      }
    }
    player1turn = true;
    player2turn = false;
  }
  return 0;
}

void endGame(Player *p1, CardList &a, Player *p2, CardList &b){
  cout<<endl<<p1->getName()<<"'s cards:"<<endl;
  cout<<a;
  cout<<endl;

  cout<<p2->getName()<<"'s cards:"<<endl;
  cout<<b;
}
