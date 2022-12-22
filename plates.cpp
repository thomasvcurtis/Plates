#include "iostream"
#include "vector"

//Plate options, 45,25,10,5


std::vector<float> getPlates(int weight, int bar, float plates[]){

    float weightWithoutBar = weight - bar;
    float weightOneSide = weightWithoutBar / 2;

    float plateCalculation = weightOneSide;

    bool is45 = true;
    bool is25 = true;
    bool is10 = true;
    bool is5 = true;
    bool is2_5 = true;

    std::vector<float> sideBar;

    while(plateCalculation != 0){

        is45 = true;
        is25 = true;
        is10 = true;
        is5 = true;
        is2_5 = true;


        if(plateCalculation >= 45){
            
            sideBar.push_back(45);
            plateCalculation = plateCalculation - 45;

            is45 = false;
        }

        if(plateCalculation >= 25 && is45){
            sideBar.push_back(25);
            plateCalculation = plateCalculation - 25;
            is25 = false;
        }

        if(plateCalculation >= 10 && is25 && is45 ){
            sideBar.push_back(10);
            plateCalculation = plateCalculation - 10;

            is10 = false;
        }

        if(plateCalculation >= 5 && is10 && is25 && is45){
            sideBar.push_back(5);
            plateCalculation = plateCalculation - 5;
            is10 = false;
        }

        if(plateCalculation >= 2.5 && is5 && is10 && is25 && is45){
            sideBar.push_back(2.5);
            plateCalculation = plateCalculation - 2.5;
            is5 = false;
        }
        

        if(plateCalculation < 2.5 && plateCalculation != 0){
            std::cout << "Weight cant not be reached, off by " << plateCalculation << " pounds\n";
            return sideBar;
        }


    }
    
    
    std::sort(sideBar.begin(), sideBar.end(), std::greater<int>());
    return sideBar;
}




int main(){

    float plates[5] = {2.5,5,10,25,45};
    int weight = 0;
    int bar = 45;
    std::cin >> weight;
    
    for(float elements: getPlates(weight,bar,plates)){
        std::cout << elements << '\n';
    }
    

    return 0;
}