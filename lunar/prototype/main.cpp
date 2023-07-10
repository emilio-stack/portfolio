/*************************************************************
 * 1. Name:
 *      Emilio Regino
 * 2. Assignment Name:
 *      Lab 01: Apollo 11
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part was understanding the physics to get the simulation to
 *      work. It got me to really think about what kind of software engineering do
 *      I want to do. Other than that I would say the hardest part was figuring out
 *      the C++ syntax that I have forgotten. Overall the assignment wasn't too hard.
 * 5. How long did it take for you to complete the assignment?
 *      6 Hours
 *****************************************************************/





#include <iostream>
#include <cmath>
#include <map>
#include <assert.h>

using namespace std;
using std::map;

float getVertVelocity() {
    /* This function prompts for the vertical velocity. */
    
    // Initilaize variables.
    float vertVelocity = 0.0;
    
    // Get vertical velocity.
    cout << "What is your vertical velocity (m/s)? ";
    cin >> vertVelocity;
    
    return vertVelocity;
}

float getHorVelocity() {
    /* This function prompts for the horizontal velocity. */
    
    // Initialize variables.
    float horVelocity = 0.0;
    
    // Get horizontal velocity.
    cout << "What is your horizontal velocity (m/s)? ";
    cin >> horVelocity;
    
    return horVelocity;
}

float getAltitutde() {
    /* This function prompts for the altitude. */
    
    // Initialize the variables.
    float altitude = 0.0;
    
    // Get altitude.
    cout << "What is your altitude (m)? ";
    cin >> altitude;
    
    return altitude;
}

float calcVertAcceleration(map<string, float>lunarLander) {
    /* This function calculates the veritcal acceleration. */
    
    // Initialize the variables.
    float acceleration = 0.0;
    float weight = lunarLander["weight"];
    float g = lunarLander["gravity"];
    float thrust = lunarLander["vertThrustPower"];
    
    // Calculate the acceleration.
    acceleration = (thrust / weight) + g;
    
    return acceleration;
}

float calcHorAcceleration(map<string, float>lunarLander) {
    /* This function calculates the horizontal acceleration. */
    
    // Initialize the variables.
    float acceleration = 0.0;
    float weight = lunarLander["weight"];
    float g = 0.0; // gravity is not factored into horizontal velocity.
    float thrust = lunarLander["horThrustPower"];
    
    // Calculate the acceleration.
    acceleration = (thrust / weight) + g;
    
    return acceleration;
}

float calcTime(float altitude, float velocity, float acceleration) {
    /* This function calculates the time until landing. */
    
    // Initialize the variables.
    float time = 0.0;
    float a = 0.0;
    float sqrtComponent = 0.0;
    
    // Calculate the time until the lunar lander hits the ground.
    /* We will use the distance formula to solve for t:
     * 0 = altitude + velocity * t + ½ * acceleration^t2
     *
     * We can simplify this equation to the quadratic equation by
     * solving for (1/2 * acceleration). */
    a = acceleration * 0.5;
    
    /* Now this becomes a quadratic equation in standard form:
     * 0 = altitude + velocity * t + a^t2
     * Use the quadratic forumla to solve for t. */
    sqrtComponent = (powf(velocity, 2)) - (4 * a * altitude);
    
    // If the discriminant is < 0, then the lunar lander will fly off into space
    // and there is no need to continue with the calculation.
    if (sqrtComponent < 0) {
        time = sqrtComponent;
    }
    
    // Else continue with the calculation.
    else {
        sqrtComponent = sqrtf(sqrtComponent);
        time  = ((velocity * (-1)) + sqrtComponent) / (2 * a);
    }
    
    return time;
}

float calcVelocity(float initVelocity, float acceleration, float time) {
    /* This function calculates velocity. */
    
    // Initialize the variables.
    float velocity = 0.000;
    
    // Calculate the velocity.
    velocity = initVelocity + (acceleration * time);
    
    return velocity;
}

float calcTotalVelocity(float vertVelocity, float horVelocity) {
    /* This function calculates total velocity. */
    
    // Initialize variables.
    float totalVelocity = 0.000;
    float cSquared = 0.00;
    
    // Use Pythagorean Theorem to calculate the total velocity.
    cSquared = (powf(vertVelocity, 2)) + (powf(horVelocity, 2));
    totalVelocity = sqrtf(cSquared);
    
    return totalVelocity;
}

void simulatorTest(float initVertVelocity, float initHorVelocity, float altitude) {
    /* This function tests the simulator. The test is specified in the arguments when
     this function is called.*/
    
    // This is the inital data for the Lunar Lander.
    map<string, float> lunarLander;
    lunarLander["weight"] = 15103;
    lunarLander["gravity"] = -1.625;
    lunarLander["vertThrustPower"] = 45000;
    lunarLander["horThrustPower"] = 450;
    
    // Perform the calculations.
    float vertAcceleration = calcVertAcceleration(lunarLander);
    float horAcceleration = calcHorAcceleration(lunarLander);
    float time = calcTime(altitude, initVertVelocity, vertAcceleration);
    
    // If there is too much thrust, the lunar lander will fly off into
    // space and there is no need for the rest of the calculations.
    if (time < 0) {
        cout << "\tYou will not land but rather fly off into space.\n";
    }
    
    // Else continue with the calculations.
    else {
        float vertVelocity = calcVelocity(initVertVelocity, vertAcceleration, time);
        float horVelocity = calcVelocity(initHorVelocity, horAcceleration, time);
        float totalVelocity = calcTotalVelocity(vertVelocity, horVelocity);
        
        // Display output.
        cout.precision(2);
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout << "\tTime to landing: " << time << " seconds.\n";
        cout << "\tVertical velocity: " << vertVelocity << " m/s.\n";
        cout << "\tHorizontal velocity: " << horVelocity << " m/s.\n";
        cout << "\tTotal velocity: " << totalVelocity << " m/s.\n";
    }
    return;
}


void simulator() {
    /* This function runs the lunar lander simulator. */
    
    // This is the inital data for the Lunar Lander.
    map<string, float> lunarLander;
    lunarLander["weight"] = 15103;
    lunarLander["gravity"] = -1.625;
    lunarLander["vertThrustPower"] = 45000;
    lunarLander["horThrustPower"] = 450;
    
    // Prompt for initial velocities and altitude information.
    float initVertVelocity = getVertVelocity();
    float initHorVelocity = getHorVelocity();
    float altitude = getAltitutde();
    
    // Perform the calculations.
    float vertAcceleration = calcVertAcceleration(lunarLander);
    float horAcceleration = calcHorAcceleration(lunarLander);
    float time = calcTime(altitude, initVertVelocity, vertAcceleration);
    
    // If there is too much thrust, the lunar lander will fly off into
    // space and there is no need for the rest of the calculations.
    if (time < 0) {
        cout << "\tYou will not land but rather fly off into space.\n";
    }
    
    // Else continue with the calculations.
    else {
        float vertVelocity = calcVelocity(initVertVelocity, vertAcceleration, time);
        float horVelocity = calcVelocity(initHorVelocity, horAcceleration, time);
        float totalVelocity = calcTotalVelocity(vertVelocity, horVelocity);
        
        // Display output.
        cout.precision(2);
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout << "\tTime to landing: " << time << " seconds.\n";
        cout << "\tVertical velocity: " << vertVelocity << " m/s.\n";
        cout << "\tHorizontal velocity: " << horVelocity << " m/s.\n";
        cout << "\tTotal velocity: " << totalVelocity << " m/s.\n";
    }
    return;
}

int main(int argc, const char * argv[]) {
    
    // Test the simulator
    cout << "\nRunning Simulator Test 1: Zero Velocity\n";
    simulatorTest(0.0, 0.0, 10.0);
    cout << "\nRunning Simulator Test 2: Soft Landing\n";
    simulatorTest(-9.07, -0.26, 30.0);
    cout << "\nRunning Simulator Test 3: Hard Landing\n";
    simulatorTest(-20.0, -5.0, 50.0);
    cout << "\nRunning Simulator Test 4: Armstrong is awesome!\n";
    simulatorTest(-16.4593, -0.36, 100.0);
    cout << "\n\n";
    
    // Run the simulator
    simulator();
    
    return 0;
}
