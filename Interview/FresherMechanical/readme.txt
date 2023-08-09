// ---------------------------------------------------------
// Find number of ways to climb N stairs jumping 1 or 2 steps
// ---------------------------------------------------------
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
e.g for n=2 there are 2 ways
1,1
2
e.g for n=3 there are 3 ways
1,1,1
1,2
2,1

int climbStairs(int n) {
   // your code goes here. 
}

class Solution {
public:
    int climbStairs(int n) {
        int p = 0;
        int c= 1;
        int s = 0;
        for(int i=0;i<n;i++) {
            s = c + p;
            p = c;
            c = s;
        }
        return s;
    }
};

// ----------------------------------------------------
// Check if the input number is prime of not
// ----------------------------------------------------
bool isPrime(int n) {
   // your code goes here. 

}

// ----------------------------------------------
// write a method which takes string and position.
// ----------------------------------------------
Check if substring from that position ahead is palindrome or not. 
bool isSubPalindrome(std::string input, int pos)
{

}

// --------------------------------------------------------------------
// find number of comparisons to find heavy coin among 9 coins with you 
// --------------------------------------------------------------------
divide it in group of 3,3,3

// ---------------------------------------------------
// write a program to calculate century from year
// ---------------------------------------------------
// Given a year, return the century it is in. The first century spans from
// the year 1 up to and including the year 100, the second - from the year 101 up
// to and including the year 200, etc.
// Example
//  For `year = 1905`, the output should be centuryFromYear(year) = 20
//  For `year = 1700`, the output should be centuryFromYear(year) = 17

// ----------------------------------------------------------
// write a recursive function to return factorial of a input 
// ----------------------------------------------------------
// for e.g factorial(5)
// output: 120

// write definition of following function declaration
int factorial(int n);

// -----------------------------------------------------------------------------------
// write a function to find all pairs of numbers in input vector whose sum is "sum"
// -----------------------------------------------------------------------------------
// void main() {
//   vector<int> items = { 0, 10, 20, 5, 30, 7, 40, 25 };
//   findSumPair(items, 30);
// }

// -----------------------------------------------------
// How to check if the point is within the closed polygon
// -----------------------------------------------------

// ---------------------------------------------
// what is angle between hands in clock at 3:15 ? 
// ---------------------------------------------
60 min = 360 degree
1 min = 6 degree
5 min = 30 degree
5/4 min = 7.5 degree

// ---------------------------------
// Puzzle US : MM/DD/yy  India: DD/MM/YY
if we don't know which system we follow , how many times in year there will be confusion

day 1 to 12 is confusing. 
such 12 months hence 12 * 12  = 144 days 

// ---------------------------------------------------
// find shortest distance between two 3D lines ? 
// ---------------------------------------------------


// ---------------------------------
// Puzzle : started with some money
// --------------------------------
doubles everytime with temple. 
offers 100 rs. at each visit

after 4 visits money is zero. 
what was initial money 

// -------------------------------------
// what is static in C programming
// -------------------------------------

// ---------
// Puzzle
How do we measure forty-five minutes using two identical wires, 
each of which takes an hour to burn? We have matchsticks with us. 
>> start one wire burning on both side
>> start other wire burning on one side
>> After 30 minutes one wire will completely burn
>> then start second wire burning from both sides. 

// ---------
// Puzzle

There is a room with a door (closed) and three light bulbs. Outside the room, there are three switches, connected to the bulbs. You may manipulate the switches as you wish, but once you open the door you can’t change them. Identify each switch with its bulb. All bulbs are in working condition.
Solution:
Let the bulbs be X, Y, and Z 
Turn on switch X for 5 to 10 minutes. Turn it off and turn on switch Y. Open the door and touch the light bulb. 
1. the light is on from the bulb, it is Y 

Now we will check other two off bulbs 
2. the bulb which is hot, it is X 
3. the bulb which is cold, it is Z  

// ---------- 
// Puzzle
// ---------- 
An employee works for an employer for 7 days. The employer has a gold rod of 7 units. 
How does the employer pay to the employee, so that the number of employee’s rod units increases by one at the end of each day? The employer can make at most 2 cuts in the rod. 

(Hint- after the end of the day employee’s can’t spend any part of rod) 
 
solution : Cut rod in part 1,2,4

// ----------
// Puzzle
Rubic cube N x N
Number of smaller cubes N^3
2 different color cubes 4 X N
3 different colors cubes 
1 face cubes
0 face cubes 

// ----------
// Puzzle
A dealer has 1000 coins and 10 bags. He has to divide the coins over the ten bags so that he can make any number of coins simply by handing over a few bags. How must divide his money into the ten bags? 
1,2,4,8,16,32,64,128,256,512

// -----------
// Puzzle 
// Maximum chocolates
You have 15 Rs with you. You go to a shop and shopkeeper tells you price as 1 Rs per chocolate. He also tells you that you can get a chocolate in return of 3 wrappers. How many maximum chocolates you can eat?

// ------------
// Puzzle 
Given two hourglass of 4 minutes and 7 minutes, the task is to measure 9 minutes

At 0 minutes: Start both hourglasses at the same time.
At 4 minutes: 4 minutes hourglass runs out and flip it. 7 minutes hourglass is left with 3 minutes.
At 7 minutes: 4 minutes hourglass is left with 1 minute. 7 minutes hourglass runs out and flip it.
At 8 minutes: 4 minutes hourglass runs out and 7 is filled with 6 minutes and 1 minute on the other side. Flip it as the sand is left with 1 minute.
At 9 minutes: 7 minutes hourglass becomes empty from above side
