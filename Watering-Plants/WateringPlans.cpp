/*
 * Author Indira Bobburi
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int UNITS_PER_CAN    =  3;

const int AWAY_FROM_FAUCET =  1;  // Plan Near direction to the next plant
const int TOWARDS_FAUCET   = -1;  // Plan Far  direction to the next plant

const string INPUT_FILE_NAME = "counts.txt";

/**
 * Simulate a watering plan.
 * @param plan the name of the plan, "Near" or "Far".
 * @param plant_count the count of plants.
 * @return the total count of step-units for the plan.
 */
int simulate_watering_plan(const string plan, const int plant_count);

/**
 * Go to the next unwatered plant after leaving the faucet,
 * according to the plan.
 * @param plan the name of the plan, "Near" or "Far".
 * @param plant_count the count of plants.
 * @param unwatered_count the count of unwatered plants.
 * @return the number of the next unwatered plant.
 */
int next_unwatered_plant(const string plan, const int plant_count,
                         const int unwatered_count);

/**
 * Walk from the faucet to a plant.
 * Update the count of steps taken and the count of step-units.
 * @param plant_number the number of the plant to walk to.
 * @param steps the count of steps taken.
 * @param step_units the count of step-units.
 * @return the number of the plant.
 */
int walk_to_plant(const int plant_number, int& steps, int& step_units);

/**
 * Which direction to go while watering plants, according to the plan.
 * @param plan the name of the plan, "Near" or "Far".
 * @return the direction.
 */
int which_direction(const string plan);

/**
 * Water a plant and move to the next plant.
 * Update the plant number to that of the next plant.
 * Also update the amount of water in the can,
 * the count of unwatered plants, the count
 * of steps taken, and the count of step-units.
 * @param plant_number the number of the plant to water.
 * @param direction the direction to the next plant.
 * @param water_amount the amount of water in the can.
 * @param unwatered_count the count of unwatered plants.
 * @param steps the count of steps taken.
 * @param step_units the count of step-units.
 * @return true if this trip is done, else false.
 */
bool water_plant(int& plant_number, const int direction,
                 int& water_amount, int& unwatered_count,
                 int& steps, int& step_units);

/**
 * Return to the faucet at the end of a trip.
 * Update the count of steps taken and the count of step-units.
 * @param plant_number the number of the last plant watered on this trip.
 * @param water_amount the amount of water left in the can.
 * @param steps the count of steps taken.
 * @param step_units the count of step_units.
 */
void return_to_faucet(const int plant_number, const int water_amount,
                      int& steps, int& step_units);

/**
 * Print the summary for a plan's simulation.
 * @param plan_name the plan name.
 * @param steps the count of steps.
 * @param step_units the count of step_units.
 */
void print_plan_summary(const string plan_name,
                        const int steps, const int step_units);

/**
 * Decide and print which plan was better for the given count of plants.
 * @param plant_count the count of plants.
 * @param near_step_units the count of step units for Plan Near.
 * @param far_step_units the count of step units for Plan Far.
 */
void compare_plans(const int plant_count,
                   const int near_step_units, const int far_step_units);

/**
 * The main. For each count of plants, simulate Plan Near and Plan Far,
 * and decide which plan was better.
 */
int main()
{
    int plant_count;  // count of plants
    
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    
    // Loop once for each number of plants read from the input file.
    // Stop when the number of plants is 0 or less.
    // During each loop, simulate Plan Near and Plan Far.
    do
    {
        input >> plant_count;
        if (plant_count <= 0) return 0;
        
        int near_step_units = simulate_watering_plan("Near", plant_count);
        int far_step_units  = simulate_watering_plan("Far",  plant_count);
        
        // Which plan was better? Better means fewer step-units.
        compare_plans(plant_count, near_step_units, far_step_units);
        
    } while (plant_count > 0);
    
    return 0;
}

int simulate_watering_plan(const string plan, const int plant_count)
{
    cout << endl;
    cout << "==========================" << endl;
    cout << " Plan " << plan << " with " << plant_count << " plants" << endl;
    cout << "==========================" << endl;
    cout << endl;
    cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
    cout << "---------  ----------  ----------  ---------------" << endl;
    
    int unwatered_count = plant_count;  // count of unwatered plants
    int steps = 0;                      // number of steps taken for Plan Near
    int step_units = 0;                 // step-units for Plan Near
    int plant_number;                   // plant #1, #2, #3, ...
    int water_amount;                   // amount of water in the watering can
    bool trip_done;                     // true if a trip is done
    
    // Loop once per trip from the faucet until all the plants are watered.
    // During each loop, fill the can, water plants according to plan,
    // and return to the faucet.
    while (unwatered_count > 0)
    {
        // Fill the can.
        water_amount = UNITS_PER_CAN;
        
        // Walk to the next unwatered plant (nearest or farthest) from the
        // faucet with a full can, according to the plan.
        int next_plant = next_unwatered_plant(plan, plant_count, unwatered_count);
        plant_number = walk_to_plant(next_plant, steps, step_units);
        
        // Water plants while walking away from or towards the faucet.
        // Loop once per plant until either the can is empty
        // or all the plants have been watered.
        // During each loop, water one plant.
        do
        {
            int direction = which_direction(plan);
            trip_done = water_plant(plant_number, direction,
                                    water_amount, unwatered_count,
                                    steps, step_units);
        } while (!trip_done);
        
        // Walk back to the faucet with an empty or partially filled can.
        return_to_faucet(plant_number, water_amount, steps, step_units);
    }
    
    print_plan_summary(plan, steps, step_units);
    return step_units;
}

int next_unwatered_plant(const string plan, const int plant_count,
                         const int unwatered_count)
{
    if (plan == "Near")
    {
        return plant_count - unwatered_count + 1;
    }
    else  // plan == "Far"
    {
        return unwatered_count;
    }
}

int walk_to_plant(const int plant_number, int& steps, int& step_units)
{
    steps += plant_number;
    step_units += plant_number*UNITS_PER_CAN;
    
    return plant_number;
}

int which_direction(const string plan)
{
    if (plan == "Near")
    {
        return AWAY_FROM_FAUCET;
    }
    else  // plan == "Far"
    {
        return TOWARDS_FAUCET;
    }
}

bool water_plant(int& plant_number, const int direction,
                 int& water_amount, int& unwatered_count,
                 int& steps, int& step_units)
{
    cout << "Plant " << setw(2) << plant_number
    << setw(9)  << steps
    << setw(11) << water_amount
    << setw(16) << step_units << endl;
    
    water_amount--;
    unwatered_count--;
    bool trip_done = (water_amount == 0) || (unwatered_count == 0);
    
    if (!trip_done)
    {
        // Walk away from (Plan Near) or towards (Plan Far) the faucet
        // to the next unwatered plant.
        plant_number += direction;
        
        steps++;
        step_units += water_amount;
    }
    
    return trip_done;
}

void return_to_faucet(const int plant_number, const int water_amount,
                      int& steps, int& step_units)
{
    steps += plant_number;
    step_units += plant_number*water_amount;
    
    cout << "FAUCET "
    << setw(10) << steps
    << setw(11) << water_amount
    << setw(16) << step_units << endl;
}

void print_plan_summary(const string plan,
                        const int steps, const int step_units)
{
    cout << endl;
    cout << "Plan " << plan << ": Total steps = " << steps
    << ", total step-units = " << step_units << endl;
}

void compare_plans(const int plant_count,
                   const int near_step_units, const int far_step_inits)
{
    cout << endl;
    cout << "*** With " << plant_count << " plants, ";
    if (far_step_inits == near_step_units)
    {
        cout << "both plans are equal." << endl;
    }
    else if (far_step_inits < near_step_units)
    {
        cout << "Plan Far is better with "
        << near_step_units - far_step_inits
        << " fewer step-units." << endl;
    }
    else
    {
        cout << "Plan Near is better with "
        << far_step_inits - near_step_units
        << " fewer step-units." << endl;
    }
}
