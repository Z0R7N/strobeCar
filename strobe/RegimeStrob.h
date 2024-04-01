
class RegimeStrob {
public:
  RegimeStrob(int timeStrob, bool lamp1, bool lamp2, bool lamp3, bool lamp4);
  getTimeStrob();
  getLamp1();
  getLamp2();
  getLamp3();
  getLamp4();
private:
  int _timeStrob;
  bool _lamp1;
  bool _lamp2;
  bool _lamp3;
  bool _lamp4;
};