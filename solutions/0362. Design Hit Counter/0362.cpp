class HitCounter {
 public:
  /** Record a hit.
      @param timestamp - The current timestamp (in seconds granularity). */
  void hit(int timestamp) {
    const int i = timestamp % 300;

    if (timestamps[i] == timestamp) {
      ++hits[i];
    } else {
      timestamps[i] = timestamp;
      hits[i] = 1;  // reset hit count to 1
    }
  }

  /** Return the number of hits in the past 5 minutes.
      @param timestamp - The current timestamp (in seconds granularity). */
  int getHits(int timestamp) {
    int countHits = 0;

    for (int i = 0; i < 300; ++i)
      if (timestamp - timestamps[i] < 300)
        countHits += hits[i];

    return countHits;
  }

 private:
  vector<int> timestamps = vector<int>(300);
  vector<int> hits = vector<int>(300);
};