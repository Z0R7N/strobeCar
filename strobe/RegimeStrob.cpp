#include "RegimeStrob.h"

RegimeStrob::RegimeStrob(int timeStrob, bool lamp1, bool lamp2, bool lamp3, bool lamp4) {
  _timeStrob = timeStrob;
  _lamp1 = lamp1;
  _lamp2 = lamp2;
  _lamp3 = lamp3;
  _lamp4 = lamp4;
}

int RegimeStrob::getTimeStrob() {
  return _timeStrob;
}

bool RegimeStrob::getLamp1() {
  return _lamp1;
}
bool RegimeStrob::getLamp2() {
  return _lamp2;
}
bool RegimeStrob::getLamp3() {
  return _lamp3;
}
bool RegimeStrob::getLamp4() {
  return _lamp4;
}
