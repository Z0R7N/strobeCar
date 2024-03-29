#inlude "RegimeStrob.h"

RegimeStrob::RegimeStrob(int timeStrob, bool lamp1, bool lamp2, bool lamp3, bool lamp4) {
  _timeStrob = timeStrob;
  _lamp1 = lamp1;
  _lamp2 = lamp2;
  _lamp3 = lamp3;
  _lamp4 = lamp4;
}

class RegimeStrob {
public:
  int getTimeStrob() return _timeStrob;
  bool getLamp1() return _lamp1;
  bool getLamp1() return _lamp2;
  bool getLamp1() return _lamp3;
  bool getLamp1() return _lamp4;
private:
  int _timeStrob;
  bool _lamp1;
  bool _lamp2;
  bool _lamp3;
  bool _lamp4;
};