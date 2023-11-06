// Implementation starter file for CSCI 60 Homework 4; due Sunday 2/5/23
// List any collaborators and write your name here

//Mengxi He

#include "parity.h" // Do NOT add any additional libraries/namespaces!
 
Parity::Parity(int * a, size_t n):nEven_(0), nOdd_(0), evens_(nullptr), odds_(nullptr)
{
  for (int i = 0; i < n; i++)
  {
    if (a[i] % 2 == 0)
    {
      if (nEven_ % CAP == 0)
      {
        int *tempEven = new int[CAP + nEven_];
        for (int x = 0; x < nEven_; x++)
        {
          tempEven[x] = evens_[x];
        }
        if (nEven_ != 0) delete evens_;
        evens_ = tempEven;
        tempEven=nullptr;
      }
      evens_[nEven_++] = a[i];
    }
    else
    {
      if (nOdd_ % CAP == 0)
      {
        int *tempOdd = new int[CAP + nOdd_];
        for (int x = 0; x < nOdd_; x++)
        {
          tempOdd[x] = odds_[x];
        }
        if (nOdd_ != 0) delete odds_;
        odds_ = tempOdd;
        tempOdd=nullptr;
      }
      odds_[nOdd_++] = a[i];
    }
  }
}

Parity::~Parity()
{
  delete [] evens_;
  delete [] odds_;
}

Parity& Parity::operator=(const Parity& rhs)
{
  nEven_ = rhs.nEven_;
  nOdd_ = rhs.nOdd_;
  delete evens_;
  delete odds_;
  evens_ = new int[nEven_];
  for (int i = 0; i < nEven_; i++)
  {
    evens_[i] = rhs.evens_[i];
  }
  odds_ = new int[nOdd_];
  for (int i = 0; i < nOdd_; i++)
  {
    odds_[i] = rhs.odds_[i];
  }
  return *this;
}



int Parity:: min() const
{
  int min = INT_MAX;
  for (int i = 0; i < nEven_; i++)
  {
    if (evens_[i] < min)
    min = evens_[i];
  }
  for (int i = 0; i < nOdd_; i++)
  {
    if (odds_[i] < min)
    min = odds_[i];
  }
  return min;
}

int Parity:: max() const
{
  int max = INT_MIN;
  for (int i = 0; i < nEven_; i++)
  {
    if (evens_[i] > max)
    max = evens_[i];
  }
  for (int i = 0; i < nOdd_; i++)
  {
    if (odds_[i] > max)
    max = odds_[i];
  }
  return max;
}

bool Parity:: odd() const
{
  int sum = 0;
  for (int i = 0; i < nEven_; i++)
  {
    sum += evens_[i];
  }
  for (int i = 0; i < nOdd_; i++)
  {
    sum += odds_[i];
  }
  if (sum %2 != 0)
  return true;
  else
  return false;
}

void Parity::insert(int val)
{
  if (val % 2 == 0)
    {
      if (nEven_ % CAP == 0)
      {
        int *tempEven = new int[CAP + nEven_];
        for (int x = 0; x < nEven_; x++)
        {
          tempEven[x] = evens_[x];
        }
        if (nEven_ != 0) delete evens_;
        evens_ = tempEven;
        tempEven=nullptr;
      }
      evens_[nEven_++] = val;
    }
    else
    {
      if (nOdd_ % CAP == 0)
      {
        int *tempOdd = new int[CAP + nOdd_];
        for (int x = 0; x < nOdd_; x++)
        {
          tempOdd[x] = odds_[x];
        }
        if (nOdd_ != 0) delete odds_;
        odds_ = tempOdd;
        tempOdd=nullptr;
      }
      odds_[nOdd_++] = val;
    }
}

size_t Parity::remove(int val)
{
  int count = 0;
  if (val % 2 == 0)
  {
    for (int i = 0; i < nEven_; i++)
    {
      if(evens_[i] == val)
      count++;
    }
    int e = 0;
    int *tempEven = new int[nEven_];
    for (int x = 0; x < nEven_; x++)
    {
      if (val != evens_[x])
      tempEven[e++] = evens_[x];
    }
      nEven_ -= count;
      delete evens_;
      evens_=tempEven;
    }
  else
  {
    for (int i = 0; i < nOdd_; i++)
    {
      if(odds_[i] == val)
      count++;
    }
    int o = 0;
    int *tempOdd = new int[nOdd_];
    for (int x = 0; x < nOdd_; x++)
    {
      if (val != odds_[x])
      tempOdd[o++] = odds_[x]; 
    }
    nOdd_ -= count;
    delete odds_;
    odds_=tempOdd;
    }
  return count;
}





ostream& operator <<(ostream& out, const Parity& p) {
  out << "\nEvens: ";
  for (int i = 0; i < p.nEven_; i++)
  {
    out << *(p.evens_+i) << " ";
  }
  out << "\nOdds: ";
  for (int i = 0; i < p.nOdd_; i++)
  {
    out << *(p.odds_+i) << " ";
  }
  return out;
}

// Starer test program for CSCI 60 Homework 4; due Tuesday 2/2/21

#include <iostream>
#include "parity.h"

using namespace std;

int main() {
  int arr[] = {3,5,-1,2,6,8,10,7,-2,11,15};
  Parity p1;
  Parity p(arr, 11); 
  p.insert(16);
  p.insert(11);
  cout << p << endl; 
  cout << "\nmin: " << p.min();
  cout << "\nmax: " << p.max();
  if(p.odd())
  cout << "\nODD!";
  else
  cout << "\nEVEN!";
  p1 = p;
  cout << p1 << endl;
  cout << "\n(1)removed: " << p.remove(2) << endl;
  cout << p << endl;
  cout << "\n(2)removed: " << p.remove(11) << endl;
  cout << p << endl;
  return 0;
}
