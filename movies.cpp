#include "movies.h"

//function implementations for Movie class
Movie::Movie(){
    this->title = "";
    this->rating = 0.0;
    this->depth = 0;
}

Movie::Movie(string title, double rating, int depth){
  this->title = title;
  this->rating = rating;
  this->depth = depth;
}

Movie::~Movie(){
  title = "";
  rating = 0.0;
  depth = 0;
}

string Movie::getTitle() const{
  return this->title;
}

double Movie::getRating() const{
  return this->rating;
}

int Movie::getDepth() const{
  return this->depth;
}

ostream& operator<<(ostream &os, const Movie &m){
  os<<m.getTitle()<<", "<<m.getRating()<<", "<<m.getDepth()<<"\n";
  return os;
}

bool operator==(const Movie &a, const string element){
  if(a.getTitle() == element)
    return true;
  return false;
}
//function implementations for CollectionBST class
CollectionBST::CollectionBST(){
  this->root = nullptr;
}

CollectionBST::~CollectionBST(){
  recursiveDeleteHelper(this->root);
}

void CollectionBST::insertMovie(const string title, const double rating){
    Node *curr = this->root;
    int depth = 0;
    if(!curr){
      this->root = new Node();
      this->root->data = new Movie(title, rating, depth);
      return;
    }
    else{
      Node *par = nullptr;
      while(curr){
        int a = curr->data->getTitle().compare(title);
        if(a > 0){
          par = curr;
          curr = curr->left;
          depth += 1;
        }
        if(a < 0){
          par = curr;
          curr = curr->right;
          depth += 1;
        }
      }
      int b = par->data->getTitle().compare(title);
      if(b > 0){
        par->left = new Node();
        par->left->data = new Movie(title, rating, depth);
        par->left->parent = par;
        return;
      }
      if(par->data->getTitle().compare(title) < 0){
        par->right = new Node();
        par->right->data = new Movie(title, rating, depth);
        par->right->parent = par;
        return;
      }
    }
    return;
}

// bool CollectionBST::search(const string title) const{
//   return true;
// }

//TODO can this be condensed?? are 3 different functions really necessary?
Movie* CollectionBST::searchForMaxPrefix(const string prefix) const{
  Movie* tmp = this->searchForMaxPrefixHelper(prefix)->data;
  return tmp;
}

void CollectionBST::printPreOrder(){
  printPreOrderHelper(this->root);
  cout<<endl;
}

//private helper functions
void CollectionBST::recursiveDeleteHelper(Node *r){
  if(r){
    recursiveDeleteHelper(r->left);
    recursiveDeleteHelper(r->right);
    delete r;
  }
}

void CollectionBST::printPreOrderHelper(Node *r){
  if(!r)
    return;
  cout<<r->data->getTitle()<<", "<<r->data->getRating()<<", "<<r->data->getDepth()<<endl;
  printPreOrderHelper(r->left);
  printPreOrderHelper(r->right);
}

//returns the first movie with the given prefix
//Precondition: the movie with the given prefix is in the collection
CollectionBST::Node* CollectionBST::searchHelper(Node *r, const string prefix) const{
  //if it matches; have to finish this
  if(matches(r->data->getTitle(), prefix)){
    return r;
  }
  int a = r->data->getTitle().compare(prefix);
  if(a > 0){
    return searchHelper(r->left, prefix);
  }
  if(a < 0){
    return searchHelper(r->right, prefix);
  }
  return nullptr;
}

//returns the movie with the prefix that has the highest rating
//Precondition: the collection has a movie that contains the prefix given
CollectionBST::Node* CollectionBST::searchForMaxPrefixHelper(const string prefix) const{
  Node *max = searchHelper(this->root, prefix);
  double maxRating = max->data->getRating();
  if(searchHelper(max->left, prefix)->data->getRating() > maxRating){
    max = searchHelper(max->left, prefix);
    maxRating = max->data->getRating();
  }
  if(searchHelper(max->right, prefix)->data->getRating() > maxRating){
    max = searchHelper(max->right, prefix);
    maxRating = max->data->getRating();
  }
  return max;
}

//Other non-member functions
bool greaterThan(const string &a, const string &b){
  string result = a;
  if(a.length() > b.length()){
    result = b;
  }
  for(int i = 0; i < result.length(); i++){
    if(b[i] < a[i])
      return false;
  }
  return true;
}

//b is the prefix
bool matches(const string &a, const string &b){
  for(int i = 0; i < b.length(); i ++){
    if(b[i] != a[i])
      return false;
  }
  return true;
}
