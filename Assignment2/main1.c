/**************************************************************************
*           MAIN1
*  Pauses for 2 seconds then prints 'Hello World' to the debug stream
*  to display the debug stream:
*      -download the program to the cortex
*      -in the Robot menu select debugger
*      -go back to Robot; then go to the debugger window and select debug stream
*
***************************************************************************/

int hailstone(int n) { //define the hailstone method
	writeDebugStream("%d \n", n); //prints the value of n after running through the if statement
	if (n == 1) { //if n == 1 then the hailstone function is over
		return 1;
  } else if (n%2 == 0) { //if n%2 == 0 then n is even and the algorithm will follow the definition for “if n is even”
		int next = n/2; // runs the hailstone function for the even integer
		return hailstone(next); //uses recursion to set n = to the next integer in 
					//the hailstone function. Thereby, passing it back into the function 
					//to print to the debug stream and find the following integer.
  } else if (n%2 == 1) { //if n%2 == 1 then n is odd an the algorithm will follow the definition for “if n is odd”
  	int next = 3*n + 1; //runs the hailstone function for the odd integer
 		return hailstone(next); //same as the past recursive step
 	} else return 1; //returns 1 as a failsafe.
}

task main() // the main method
{
  wait1Msec(2000); //waits for the robot operating system
  hailstone(7); // runs the hailstone function with a starting value of 7
}
