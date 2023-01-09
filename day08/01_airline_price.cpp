/*
You're building a tool to estimate the cost of various airplane tickets based on the airline, distance and seating class. Your tool must take in this information as a series of inputs (one ticket calculation per line of input) and produce a list of output costs.

Each airline contains its own cost requirements. Ultimately, the airline is only interested in two major components: the space (seating class) you take on the plane, and the distance you fly. You must generate ticket costs using this gathered data:

Airlines: United, Delta, Southwest, LuigiAir

Operating Costs:

 - Economy:  No charge
 - Premium:  $25
 - Business: $50 + $0.25/mile

Per-Airline Prices:

 - Delta charges $0.50/mile
   + OperatingCost
   
 - United charges $0.75/mile
   + OperatingCost
   + $0.10/mile for Premium seats

 - Southwest charges $1.00/mile

 - LuigiAir charges $100 or 2 * OperatingCost, whichever is higher

Keep in mind that, while there are only four airlines listed above, your solution should be able to expand to dozens of individual airlines, whose ticket cost can be based on arbitrary functions of "Operating Costs", miles, and/or seating class.

You can assume that the input will be provided as a list, and that there could be millions of elements in this list. Each element is another list that provides strings of the Airline, Distance, and Seating Class. Please review the examples below:

Example Input:
-------------------------------------------
United 150.0 Premium
Delta 60.0 Business
Southwest 1000.0 Economy
LuigiAir 50.0 Business
-------------------------------------------

Example Output:
-------------------------------------------
152.50
95.00
1000.00
125.00
-------------------------------------------

Explanation of Output:
-------------------------------------------
152.50      (150.0 * (0.75 + 0.10) + 25)
95.00       (60.0 * (0.50 + 0.25) + 50)
1000.00     (1000.0 * 1.00)
125.00      (100 <= 2 * (50 + 50 * 0.25))
-------------------------------------------
 */

#include <iostream>
#include <vector>
#include <memory>
#include <map>

using namespace std;

class AirLinePrice {
  protected:
  map<string, float> operatingCosts = {
    {"Economy", 0.0},
    {"Premium", 25.0},
    {"Business", 50.0}
  };

  public:
  float getOperatingCosts(string& seatClass, int distance) {
    return operatingCosts[seatClass];
  }

  bool isPremiumClass(string& seatClass) {
    if (seatClass == "Premium") {
      return true;
    }
    return false;
  }

  virtual float estimate(string& seatClass, float distance) = 0;
};

class United : public AirLinePrice {
  public:
  float estimate (string& seatClass, float distance) {
    float cost = (0.75 * distance) + getOperatingCosts(seatClass, distance);
  
    if (isPremiumClass(seatClass)) {
      cost += 0.10 * distance;
    }
    return cost;
  }
};

class Delta : public AirLinePrice {
  public:
  float estimate (string& seatClass, float distance) {
    return (0.5 * distance) + getOperatingCosts(seatClass, distance);
  }
};

class SouthWest : public AirLinePrice {
  public:
  float estimate (string& seatClass, float distance) {
    return distance;
  }
};

class LuigiAir : public AirLinePrice {
  public:
  float estimate (string& seatClass, float distance) {
    return std::max((float)100.0, getOperatingCosts(seatClass, distance));
  }
};

class PriceFactory {
  static map<std::string,shared_ptr<AirLinePrice>> instances;

  public:
  PriceFactory() {
  }

  static void init() {
    instances.insert({"United", make_shared<United>()});
    instances.insert({"Delta", make_shared<Delta>()});
    instances.insert({"Southwest", make_shared<SouthWest>()});
    instances.insert({"LuigiAir", make_shared<LuigiAir>()});
  }

  static shared_ptr<AirLinePrice> getPriceEstimator(string& airlineName) {

    if (instances.find(airlineName) == instances.end()) {
      string error= "unidentified airline";
      throw std::exception();
    }

    return instances[airlineName];
  }
};

map<std::string,shared_ptr<AirLinePrice>> PriceFactory::instances = {};

const vector<vector<string>> input = {
  {"United", "150.0", "Premium"},
  {"Delta", "60.0", "Business"},
  {"Southwest", "1000.0", "Economy"},
  {"LuigiAir", "50.0", "Business"}
};

enum airlineNames {
  Southwest = 0,

};

int main() {
   PriceFactory::init();

   for (auto query : input) {
     auto airlineName = query[0];
     auto distanceStr = query[1];
     auto seatClass = query[2];

     auto estimator = PriceFactory::getPriceEstimator(airlineName);
     float distance = stof(distanceStr);
     cout << " Price for " + airlineName  + "for class " + seatClass + "  "  << estimator->estimate(seatClass, distance) << endl;
   }
}
