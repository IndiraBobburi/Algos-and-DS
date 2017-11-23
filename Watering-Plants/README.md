# Watering-Plans
How to water your garden
You have a simple garden with N plants in a straight row, and a faucet at one end:
At the faucet, you fill a watering can completely with water and then walk to water your plants one at a time. When the can becomes empty, you walk back to the faucet to refill it. After you’ve watered the last plant, you walk back to the faucet with an empty or partially filled can. Leaving the faucet, watering plants, and returning to the faucet constitute one trip. To keep things simple, assume that the watering can holds three units of water, and each plant requires one unit of water. Each plant is one step away from the next plant, and the faucet is one step from the first plant. The plant next to the faucet is labeled #1, the next plant is labeled #2, etc.

You have two different plans to accomplish each trip.
Watering Plan Near: 
After filling the watering can at the faucet, you always walk to the nearest unwatered plant and proceed to water each unwatered plant as you walk away from the faucet. When the can becomes empty, you walk back to the faucet with the empty can to refill it completely for another trip. After you’ve watered the last unwatered plant, you walk back to the faucet with the can, which can be empty or partially filled. For example, you have five plants. On the first trip, you walk to plant #1 and water it, you water #2 and #3, and then you walk back to the faucet with an empty can. On your second trip, you walk to plant #4 and water it and #5, and then walk back to the faucet with one unit of water remaining in the can.

Watering Plan Far: 
After filling the watering can at the faucet, you always walk to the farthest unwatered plant and proceed to water each unwatered plant as you walk back towards the faucet. When the can becomes empty, you walk back to the faucet with the empty can to refill it completely for another trip. After you’ve watered the last unwatered plant, you walk back to the faucet with the can, which can be empty or partially filled. For example, you have five plants. On the first trip, you walk to plant #5 and water it, you water #4 and #3, and then you walk back to the faucet with an empty can. On your second trip, you walk to plant #2 and water it and #1, and then you walk back to the faucet with one unit of water remaining in the can. 

In each plan, you always fill the can completely before each trip.

Which plan is better? For each plan, you can count the total number of steps required to water all the plants. But a better measure is the total amount of weight you had to carry, measured in “step-units”. If you walk 3 steps to a plant with a full can (3 units), that’s 9 step units. Water the plant (now the can contains 2 units) and step to the next plant, which adds 2 step-units, for a cumulative total of 11 step-units. Which watering plan results in fewer total step-units?
