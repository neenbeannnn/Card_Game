#include <iostream>
using namespace std;

class Movie{
public:
  Movie();
  Movie(string title, double rating, int depth);
  ~Movie();
  string getTitle() const;
  double getRating() const;
  int getDepth() const;
  friend ostream& operator<<(ostream &os, const Movie &m);
  friend bool operator==(const Movie &a, const string element);
private:
  string title;
  double rating;
  int depth;
};

class CollectionBST{
public:
  CollectionBST();
  ~CollectionBST();
  void insertMovie(string title, double rating);
  // bool search(const string title) const;
  Movie* searchForMaxPrefix(const string prefix) const;
  void printPreOrder();
private:
  struct Node{
    Movie *data;
    Node *parent;
    Node *right;
    Node *left;
    Node():data(nullptr), parent(nullptr), right(nullptr), left(nullptr){}
  };

  Node *root;
  //private helper functions
  void recursiveDeleteHelper(Node *r);
  void printPreOrderHelper(Node *r);
  Node* searchHelper(Node *r, const string prefix) const;
  Node* searchForMaxPrefixHelper(const string prefix) const;
};

//non-member functions
bool greaterThan(const string &a, const string &b);
bool matches(const string &a, const string &b);
// bool operator>(const string &a, const string &b);
