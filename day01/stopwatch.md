```cpp

template <typename T> class basic_stopwatch : T {
  typedef typename T BaseTimer;
public:
  // create, optionally start timing an activity
  explicit basic_stopwatch(bool start);

  explicit basic_stopwatch(char const* activity = "Stopwatch", bool start=true);

  basic_stopwatch(std::ostream& log, char const* activity="Stopwatch", bool start=true);

  // stop and destroy a stopwatch
  ~basic_stopwatch();

  // get last lap time (time of last stop)
  unsigned LapGet() const;

  // predicate: return true if the stopwatch is running
  bool IsStarted() const;

  // show accumulated time, keep running, set/return lap
  unsigned Show(char const* event="show");

  // (re)start a stopwatch, set/return lap time
  unsigned Start(char const* event_namee="start"); // stop a running stopwatch, set/return lap time
  unsigned Stop(char const* event_name="stop");

private: // members
  char const* m_activity; // "activity" string
  unsigned m_lap; // lap time (time of last stop)
  std::ostream& m_log; // stream on which to log events
};
  

// Example 3-4. TimerBase class using <chrono>
# include <chrono>
using namespace std::chrono; class TimerBase {public:
  // clears the timer
  TimerBase() : m_start(system_clock::time_point::min()) { }

  // clears the timer
  void Clear() {
    m_start = system_clock::time_point::min();
  }

  // returns true if the timer is running
  bool IsStarted() const {
    return (m_start.time_since_epoch() != system_clock::duration(0));
  }

  // start the timer
  void Start() {
    m_start = system_clock::now();
  }

  // get the number of milliseconds since the timer was started
  unsigned long GetMs() {
    if (IsStarted()) {
      system_clock::duration diff;
      diff = system_clock::now() - m_start;
      return (unsigned)(duration_cast<milliseconds>(diff).count());
    }
    return 0;
  }
 
 private:
    system_clock::time_point m_start;
};

```
