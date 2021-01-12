struct CheckIn {
  string stationName;
  int t;
};

struct T {
  int numTrips;
  int totalTime;
};

class UndergroundSystem {
 public:
  void checkIn(int id, string stationName, int t) {
    idToCheckIn[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    const CheckIn checkIn = idToCheckIn[id];
    idToCheckIn.erase(id);
    ++graph[checkIn.stationName][stationName].numTrips;
    graph[checkIn.stationName][stationName].totalTime += t - checkIn.t;
  }

  double getAverageTime(string startStation, string endStation) {
    const auto [numTrips, totalTime] = graph[startStation][endStation];
    return totalTime / (double)numTrips;
  }

 private:
  unordered_map<int, CheckIn> idToCheckIn;
  unordered_map<string, unordered_map<string, T>> graph;
};