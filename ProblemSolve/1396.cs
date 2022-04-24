/*****************************
 * Design Underground System *
 *****************************/

public class UndergroundSystem {
    struct CheckInMap{
        public string name;
        public int time;
        
        public CheckInMap(string name, int time){
            this.name = name;
            this.time = time;
        }
    }
    
    struct CheckOutTime{
        public double totalTime;
        public int count;
        
        public CheckOutTime(double totalTime, int count){
            this.totalTime = totalTime;
            this.count = count;
        }
    }
    
    Dictionary<int, CheckInMap> checkInMapHash = new Dictionary<int, CheckInMap>();
    Dictionary<string, CheckOutTime> timeHash = new Dictionary<string, CheckOutTime>();
    
    public UndergroundSystem() {
        
    }
    
    public void CheckIn(int id, string stationName, int t) {
        checkInMapHash.Add(id, new CheckInMap(stationName, t));
    }
    
    public void CheckOut(int id, string stationName, int t) {
        var checkIn = checkInMapHash[id];
        checkInMapHash.Remove(id);
        
        string route = checkIn.name + "~" + stationName;
        if(!timeHash.TryGetValue(route, out CheckOutTime times)){
            timeHash.Add(route, new CheckOutTime((double)t - checkIn.time, 1));
            return;
        }
        
        var temp = timeHash[route];
        temp.totalTime += (t - checkIn.time);
        temp.count += 1;
        timeHash[route] = temp;
    }
    
    public double GetAverageTime(string startStation, string endStation) {
        string routeName = startStation + "~" + endStation;
        var route = timeHash[routeName];
        return route.totalTime / route.count;
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.CheckIn(id,stationName,t);
 * obj.CheckOut(id,stationName,t);
 * double param_3 = obj.GetAverageTime(startStation,endStation);
 */