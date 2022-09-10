#include "utils/data_structure.hpp"

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
class MyCalendar {
public:
  /* 80.53, 87.88 */
  std::vector<std::pair<int, int>> my_booking;
  MyCalendar() {}
  bool book(int start, int end) {
    for (std::pair<int, int> & interval: my_booking) {
      int left = MAX(interval.first, start);
      int right = MIN(interval.second, end);
      if (right > left) return false;
    }
    my_booking.push_back(std::pair<int, int>(start, end));
    return true;      
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */