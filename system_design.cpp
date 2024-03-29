class ParkingSystem {
public: vector<int> vehicle;
public:
    ParkingSystem(int big, int medium, int small) {
        vehicle = { big,medium,small };
    }
    
    bool addCar_longWay(int carType) {
        if(carType == 1) {
            if(vehicle[0] > 0){
                vehicle[0]--;
                return true;
            }
        }
        else if(carType == 2) {
            if(vehicle[1] > 0){
                vehicle[1]--;
                return true;
            }
        }
        else if(carType == 3) {
            if(vehicle[2] > 0){
                vehicle[2]--;
                return true;
            }
        }
        return false;
    }
  
    bool addCar_shortWay(int carType){
        if(vehicle[carType - 1]) {
            vehicle[carType - 1] -= 1
            return true
		}
		  return false
    }
};
