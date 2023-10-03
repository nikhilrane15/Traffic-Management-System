#include <iostream>
#include <thread>
#include <chrono>

enum TrafficLightState { RED, GREEN, YELLOW };

class TrafficLight {
private:
    TrafficLightState state;

public:
    TrafficLight() : state(RED) {}

    void setState(TrafficLightState newState) {
        state = newState;
    }

    TrafficLightState getState() const {
        return state;
    }
};

class Intersection {
private:
    TrafficLight trafficLight;

public:
    void simulateTrafficFlow() {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(5)); // Change lights every 5 seconds for demonstration

            TrafficLightState currentState = trafficLight.getState();

            switch (currentState) {
                case RED:
                    trafficLight.setState(GREEN);
                    break;

                case GREEN:
                    trafficLight.setState(YELLOW);
                    break;

                case YELLOW:
                    trafficLight.setState(RED);
                    break;
            }

            std::cout << "Traffic light changed to " << currentState << std::endl;
        }
    }
};

int main() {
    Intersection intersection;
    intersection.simulateTrafficFlow();

    return 0;
}
