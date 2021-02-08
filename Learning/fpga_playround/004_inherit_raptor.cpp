// TestCPP1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

struct RaptorBasic {
  template <typename Raptor> struct Event {
    int b;
    typename Raptor::inside_dang
        inside; // Raptor o day chinh la struct dangdeptrai nen phai dung
                // typename vi no khong thuoc struct RaptorBasic
  };
};

template <typename Base> struct RaptorAHD : Base {
  template <typename Raptor>
  struct Event
      : Base::template Event<Raptor> { // Cai nay se goi den
                                       // RaptorBasic::Event<dangdeptrai>
    int a;
  };
};

struct dangdeptrai {
  int d;
  struct inside_dang {
    int e;
  };
};

struct Raptor : RaptorAHD<RaptorBasic> {
  typedef RaptorAHD<RaptorBasic> Base;
  struct Event : Base::Event<dangdeptrai> {
  }; // cai nay se goi den RaptorAHD::Event
};

int main() {
  Raptor::Event event; // vay thi event se co bien a, b, e,
  // event se thua ke RaptorAHD, RaptorBase, trong RaptorBase lai co 1 bien
  // inside cua dangdeptrai nen se co bien e
  return 0;
}