#include "Arduino.h"

class RegimeStrob {
public:
  RegimeStrob(int timeStrob, bool lamp1, bool lamp2, bool lamp3, bool lamp4);
  int getTimeStrob();
  bool getLamp1();
  bool getLamp1();
  bool getLamp1();
  bool getLamp1();
private:
  int _timeStrob;
  bool _lamp1;
  bool _lamp2;
  bool _lamp3;
  bool _lamp4;
};