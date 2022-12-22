//Author: Thomas Curtis

#include "iostream"
#include "vector"
#include "stdexcept"
#include "limits"


std::vector<float> getPlates(int weight, int bar){

    float weightWithoutBar = weight - bar;
    float weightOneSide = weightWithoutBar / 2;
    
    //TODO rename bools to something better
    bool is45 = true;
    bool is25 = true;
    bool is10 = true;
    bool is5 = true;
    bool is2_5 = true;

    std::vector<float> sideBar;

    while(weightOneSide != 0){

        is45 = true;
        is25 = true;
        is10 = true;
        is5 = true;
        is2_5 = true;

        if(weightOneSide >= 45){

            sideBar.push_back(45);
            weightOneSide -= 45;
            is45 = false;
        }

        if(weightOneSide >= 25 && is45){

            sideBar.push_back(25);
            weightOneSide -= 25;
            is25 = false;
        }

        if(weightOneSide >= 10 && is25 && is45 ){

            sideBar.push_back(10);
            weightOneSide -= 10;
            is10 = false;
        }

        if(weightOneSide >= 5 && is10 && is25 && is45){

            sideBar.push_back(5);
            weightOneSide -= 5;
            is10 = false;
        }

        if(weightOneSide >= 2.5 && is5 && is10 && is25 && is45){

            sideBar.push_back(2.5);
            weightOneSide -= 2.5;
            is5 = false;
        }
        
        if(weightOneSide < 2.5 && weightOneSide != 0){
            std::cout << "Weight cant not be exactly, off by " << weightOneSide << " pounds\n";
            return sideBar;
        }

    }
     
    std::sort(sideBar.begin(), sideBar.end(), std::greater<int>());
    return sideBar;
}


int main(int argc, char *argv[]){

    int bar = atoi(argv[1]);
    int weight = atoi(argv[2]);

    for(float elements : getPlates(weight,bar)){
        std::cout << elements << '\n';
    }
    
    return 0;
}