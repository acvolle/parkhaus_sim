# parkhaus_sim
### Team "Flying Monkeys Brigade"
https://theirontailor.blogspot.com/2017/10/flying-monkey-brigade.html

### How to build the Parkhaus Simulation App
To use this software "out of the box", CMAKE has to be installed
CMAKE can use the included "CMakeLists.txt" to build the app "parkhaus_sim.exe"
It will only build the app after all unit tests are passed, ensuring proper functionality.
Use these steps to launch the app:
1. Create a "build" directory and navigate to it.
2. Use `cmake ..` command to create mandatory files
3. Use `cmake --build .` command to run unit tests and build the app.
4. Launch the app by running the executable `./parkhaus_sim.exe` or `./Debug/parkhaus_sim.exe`
   
### How to use this Parkhaus Simulation Tool
You will be asked to enter the simulation parameters:
1. The number of parking spaces your garage has
2. The *maximum* duration a car can park before it leaves the garage (the actual duration is set randomly)
3. How many timesteps you want to simulate (you can think of timesteps as minutes)
4. The probability for new cars to arrive per timestep (e.g. 50% would equal a car arriving every other timestep on average)
5. Your simulation seed for random number generation (different Seeds will lead to different results)

Now for each simulation timestep the current statistics are printed out on the console as well as written into a log file.
For each timestep, a stress score is calculated. It tells you on a scale of 0-100, how stressful the current situation is.
Example: Occupation 50% -> Score 12.5
If every space is occupied, the score will be at least 50, and cars queueing up and waiting to get in will gradually increase the score up to 100.

After the simulation is finished, you will also instantly see averages printed out on the console.
- How occupied the garage was on average (ideally about 80%)
- What the average waiting time was for a car to be able to get in (ideally 0)
- The average stress score throughout the entire simulated period (ideally 30-35)

To analyze the generated data, you can find the values for each timestep (csv format) inside the file "parkhaus_sim_log.txt".
