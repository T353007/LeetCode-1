class CheckIn {
  public String stationName;
  public int t;

  public CheckIn(String stationName, int t) {
    this.stationName = stationName;
    this.t = t;
  }
}

class Info {
  public int numTrips;
  public int totalTime;

  public Info(int numTrips, int totalTime) {
    this.numTrips = numTrips;
    this.totalTime = totalTime;
  }
}

class UndergroundSystem {
  public void checkIn(int id, String stationName, int t) {
    idToCheckIn.put(id, new CheckIn(stationName, t));
  }

  public void checkOut(int id, String stationName, int t) {
    final CheckIn checkIn = idToCheckIn.get(id);
    idToCheckIn.remove(id);
    graph.putIfAbsent(checkIn.stationName, new HashMap<>());
    final Info info = graph.get(checkIn.stationName).get(stationName);
    if (info == null) {
      graph.get(checkIn.stationName).put(stationName, new Info(1, t - checkIn.t));
    } else {
      graph.get(checkIn.stationName).put(stationName, new Info(info.numTrips + 1, info.totalTime + t - checkIn.t));
    }
  }

  public double getAverageTime(String startStation, String endStation) {
    final Info info = graph.get(startStation).get(endStation);
    return info.totalTime / (double) info.numTrips;
  }

  private Map<Integer, CheckIn> idToCheckIn = new HashMap<>();
  private Map<String, Map<String, Info>> graph = new HashMap<>();
}