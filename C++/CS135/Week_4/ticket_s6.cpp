//  Header Files  //////////////////////////////////////////////////////////////
#include "formatted_console_io_v16.h"
#include <cmath>

using namespace std;

//  Global Constants  //////////////////////////////////////////////////////////

    // global color constants
    const short TITLE_COLOR = COLOR_CYAN;
    const short DISPLAY_BKGD_COLOR = COLOR_CYAN;
    const short TEXT_DISPLAY_COLOR = COLOR_YELLOW;
    const short ENTRY_DISPLAY_COLOR = COLOR_RED;
    const short INPUT_COLOR = COLOR_WHITE;
    const short MSG_TEXT_COLOR = COLOR_WHITE;
    const short COMPLETE_COLOR = COLOR_BLUE;
    const short INCOMPLETE_COLOR = COLOR_RED;

    // set frame locations and person codes
    const int BOX_LEFT_POS = 8;
    const int BOX_TOP_POS = 5;
    const int BOX_WIDTH = 63;
    const int BOX_HEIGHT = 14;
    const int ADULT_CODE = 1;
    const int CHILD_CODE = 2;
    const int SENIOR_CODE = 3;

    // set ticket price constants
    const double ADULT_TICKET_PRICE = 12.00;
    const double CHILD_TICKET_PRICE = 3.00;
    const double SENIOR_TICKET_PRICE = 5.00;

    // set decimal precision value
    const int DECIMAL_PRECISION = 2;

//  Function Prototypes  ///////////////////////////////////////////////////////

/*
Name: displayInputScreen
Process: clear screen, create box, set color for display text, 
         print strings of categories for user input
Input: none
Output/to screen: sets up screen for input and output
Dependencies: formatted console I/O tools
*/
void displayInputScreen(); 

/*
Name: promptForNumTickets
Process: moves to appropriate line according to the person code,
         clears dashes, acquires input
Input: person code (int)
Output/returned: amount
Dependencies: formatted console I/O tools
*/
int promptForNumTickets( int personCode );

/*
Name: calcTicketPrice
Process: uses the person code to figure out ticket price,
         then multiplies by number of tickets to calculate price
Input: numTickets (int), person code (int)
Output/returned: totalPrice
Dependencies: none
*/
double calcTicketPrice( int numTickets, int personCode );

/*
Name: printSubTotal
Process: prints running subtotal at correct location on screen
Input: subtotal (double)
Output/to screen: displays running ticket price subtotal
Dependencies: formatted console I/O tools
*/
void printSubTotal( double sTot );

/*
Name: promptForAmtTendered
Process: moves to amount tendered location on screen, acquires user input
Input: none
Output/returned: amount tendered (double)
Dependencies: formatted console I/O tools
*/
double promptForAmtTendered();

/*
Name: completeTransaction
Process: displays change if successful transaction,
         otherwise prints amount tendered,
         then prints message to the user saying the transaction
         was successful or not
Input: change, amountTendered (double)
Output/to screen: message to user and change/amountTendered
Dependencies: formatted console I/O tools
*/
void completeTransaction( double change, double amountTendered );


//  Main Function  /////////////////////////////////////////////////////////////
int main()
   {
    // initialize program

       // initialize variables
          int adultTickets, childTickets, seniorTickets;
          double total, amountTendered, change;

       // start curses
          // function: startCurses
          startCurses();

       // clear the screen for outside background
          // function: clearScreen
          clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

       // create data input screen
          // function: displayInputScreen
          displayInputScreen(); 

    // get user input & process data

       // prompt user for number of adult tickets
          // function: promptForNumTickets
          adultTickets = promptForNumTickets( ADULT_CODE );

       // calculate subtotal
          // function: calcTicketPrice
          total = calcTicketPrice( adultTickets, ADULT_CODE );

       // display subtotal
          // function: printSubTotal
          printSubTotal( total );

       // prompt user for number of children tickets
          // function: promptForNumTickets
          childTickets = promptForNumTickets( CHILD_CODE );

       // calculate subtotal
          // function: calcTicketPrice
          total += calcTicketPrice( childTickets, CHILD_CODE );

       // display subtotal
          // function: printSubTotal
          printSubTotal( total );

       // prompt user for number of senior tickets
          // function: promptForNumTickets
          seniorTickets = promptForNumTickets( SENIOR_CODE );

       // calculate total
          // function: calcTicketPrice
          total += calcTicketPrice( seniorTickets, SENIOR_CODE );

       // display total
          // function: printSubTotal
          printSubTotal( total );

       // prompt user for amount tendered
          // function: promptForAmountTendered
          amountTendered = promptForAmtTendered();

    // calculate change
       // operation: math
    change = amountTendered - total;

    // display results
       // function: completeTransaction
       completeTransaction( change, amountTendered );

    // shut down program

       // hold screen for user
          // function: waitForInput
          waitForInput( FIXED_WAIT );

       // end curses
          // function: endCurses
          endCurses();

       // return success
       return 0;
   }

//  Supporting Function Implementation  ////////////////////////////////////////

void displayInputScreen()
   {
    // initialize function/varialbles
       int xLoc = BOX_LEFT_POS, yLoc = BOX_TOP_POS;

    // set color, clear box screen
       // functions: setColor, clearScreen
       setColor( TEXT_DISPLAY_COLOR, DISPLAY_BKGD_COLOR, SET_BRIGHT );
       clearScreen( BOX_LEFT_POS, BOX_TOP_POS, 
                           BOX_LEFT_POS + BOX_WIDTH, BOX_TOP_POS + BOX_HEIGHT );

    // print box frame
       // function: printStringAt
       printStringAt( xLoc, yLoc, "|--------------------------------------------------------------|", "LEFT" );

    // print title
       // function: printStingAt
       yLoc += 1;
       xLoc += BOX_WIDTH / 2; // center of box
       printStringAt( xLoc, yLoc, "TICKET MISTER", "CENTER" );

    // print middle vertical line
       // function: printStringVertical
       yLoc = BOX_TOP_POS + 3;
       printStringVertical( xLoc, yLoc, "|||||||||||", "DOWN" );

    // print middle and bottom horizontal lines
       // function: printStringAt
       xLoc = BOX_LEFT_POS;
       yLoc -= 1;
       printStringAt( xLoc, yLoc, "|==============================================================|", "LEFT" );
       yLoc = BOX_TOP_POS + BOX_HEIGHT;
       printStringAt( xLoc, yLoc, "|==============================================================|", "LEFT" );

    // print side lines
       // function: printString Vertical
       yLoc = BOX_TOP_POS;
       printStringVertical( xLoc, yLoc, "||||||||||||||", "DOWN" );
       xLoc += BOX_WIDTH;
       printStringVertical( xLoc, yLoc, "||||||||||||||", "DOWN" );

    // print empty display for user input and display locations (left side)
       // function: printStringAt
       xLoc = BOX_LEFT_POS + 2;
       yLoc += 4;
       printStringAt( xLoc, yLoc, "Number of Tickets", "LEFT" );
       yLoc +=2;
       printStringAt( xLoc, yLoc, "Adults:   --- @ $", "LEFT" );
       yLoc += 2;
       printStringAt( xLoc, yLoc, "Children: --- @ $", "LEFT" );
       yLoc += 2;
       printStringAt( xLoc, yLoc, "Seniors:  --- @ $", "LEFT" );
       yLoc +=2;
       printStringAt( xLoc, yLoc, "Total Ticket Price: $ ---", "LEFT" );

    // print prices for ticket types
       // function: printDoubleAt
       xLoc = xLoc + 21;
       yLoc = BOX_TOP_POS + 6;
       printDoubleAt( xLoc, yLoc, ADULT_TICKET_PRICE, DECIMAL_PRECISION, "RIGHT" );
       yLoc += 2;
       printDoubleAt( xLoc, yLoc, CHILD_TICKET_PRICE, DECIMAL_PRECISION, "RIGHT" );
       yLoc += 2;
       printDoubleAt( xLoc, yLoc, SENIOR_TICKET_PRICE, DECIMAL_PRECISION, "RIGHT" );

    // print empty display for categories (right side)
       // function: printStringAt
       xLoc = BOX_LEFT_POS + BOX_WIDTH / 2 + 3;
       yLoc = BOX_TOP_POS + 4;
       printStringAt( xLoc, yLoc, "Amount Tendered", "LEFT" );
       yLoc += 2;
       printStringAt( xLoc, yLoc, "$ -----", "LEFT" );    
       yLoc +=2;
       printStringAt( xLoc, yLoc, "Change Returned", "LEFT" );
       yLoc += 2;
       printStringAt( xLoc, yLoc, "$ -----", "LEFT" );    
   }


int promptForNumTickets( int personCode )
   {
    // initialize function/variables
    int xLoc = BOX_LEFT_POS;
    int yLoc = BOX_TOP_POS;
    int ticket;
    // set x location of the prompt
       // operaation: math
       xLoc += 12;
       // check for personCode equal to adult code
       if ( personCode == ADULT_CODE )
            // assign adult code y location
            yLoc += 6;
       // check for personCode equal to child code
       else if ( personCode == CHILD_CODE )
            // assign child code y location
            yLoc += 8;
       // otherwise assume senior code
       else         
            // assign senior code y location
            yLoc += 10;
    // clear dashes 
       // functions: setColor, printStringAt
       setColor(COLOR_RED, COLOR_WHITE, 1);
       printStringAt( xLoc, yLoc, "   ", "LEFT" );
    // prompt user for number of tickets 
       // function: promptForIntAt
       ticket = promptForIntAt (xLoc, yLoc,"");
    // return amount
       return ticket; 
   }

double promptForAmtTendered()
   {
    // initialize function/variables
       int xLoc = BOX_LEFT_POS + BOX_WIDTH / 2 + 5;
       int yLoc = BOX_TOP_POS + 6;
       double tendered;

    // clear the dashes
       // function: printStringAt
       printStringAt( xLoc, yLoc, "     ", "LEFT" );

    // get the amount tendered
       // function: promptForDoubleAt
       tendered = promptForDoubleAt( xLoc, yLoc, "" );

    // return the amount tendered
       return tendered;
   }


double calcTicketPrice( int numTickets, int personCode )
   {
    // initialize function/variables
    double cost;
    // select correct ticket price, and calculate total

       // check for person code equal to adult code
       if ( personCode == ADULT_CODE )
            // calculate price using adult ticket price
            {
            cost = numTickets * ADULT_TICKET_PRICE;
            }
       // check for person code equal to child code
       else if (personCode == CHILD_CODE)
            // calculate price using child ticket price
            {
            cost = numTickets * CHILD_TICKET_PRICE;
            }
       // otherwise assume senior code
       else
            // calculate price using senior ticket price
            {
            cost = numTickets * SENIOR_TICKET_PRICE;
            }
    // return ticket price
  
       return cost; 
   }


void printSubTotal( double sTot )
   {
    // initialize function/variables
       int xLoc = BOX_LEFT_POS + 26, yLoc = BOX_TOP_POS + 12;

    // clear the dashes or previous output
       // function: printStringAt
       printStringAt( xLoc, yLoc, "   ", "RIGHT" );

    // print the sub total value
       // function: printDoubleAt
       xLoc += 3;
       printDoubleAt( xLoc, yLoc, sTot, DECIMAL_PRECISION, "RIGHT" );
   }

void completeTransaction( double change, double amountTendered )
   {
    // initialize function/variables
    int xLoc, yLoc, xLoc2, yLoc2;
       // initialize x location and y location using constants
       yLoc = BOX_TOP_POS + 10;
       xLoc = BOX_LEFT_POS +41;
       xLoc2 = xLoc + 6;
       yLoc2 = yLoc + 2; 
       // clear dashes
          // function: printStringAt
          printStringAt( xLoc, yLoc, "      ", "RIGHT" );
       // check for change greater than or equal to zero,
       if (change >= 0)
       {
            // show change and successful transaction
            
              // print change
                 // function: printDoubleAt
                 printDoubleAt (xLoc, yLoc, change,DECIMAL_PRECISION, "RIGHT");  
              // set message location
                 // function: setColor
                 setColor(COLOR_WHITE, COLOR_BLUE, 1);
                 }
              // check for change >= $20 
              if (change >= 20)
                  // report completed transaction and offer user a popcorn
                     // function: printStringAt
                     {
                     printStringAt( xLoc2, yLoc2 , "Ticket Purchase Completed", "CENTER" );
                     printStringAt( xLoc2, yLoc2 + 1 , "Your change can buy popcorn!", "CENTER" );
                      }        
              // check for change >= $10
              else if (change >= 10)
                  // report completed transaction and offer user a soda
                     // function: printStringAt
                     {
                     printStringAt( xLoc2, yLoc2 , "Ticket Purchase Completed", "CENTER" );
                     printStringAt( xLoc2, yLoc2 + 1 , "Your change can buy a soda!", "CENTER" );
                     }
           // otherwise, assume change < $10
           else if (change < 10)
               // report completed transaction and ask user to take tickets
                  // function: printStringAt
                  {
                     printStringAt( xLoc2, yLoc2 , "Ticket Purchase Completed", "CENTER" );
                     printStringAt( xLoc2, yLoc2 + 1 , "Please Take Tickets", "CENTER" );
                  }
      // otherwise if change is not greater than or equal to zero
      if (change < 0)
                   {
            // show amount tendered and failed transaction
              
               // print amount tendered
                  // function: printDoubleAt
                  printDoubleAt (xLoc, yLoc, amountTendered,DECIMAL_PRECISION, "RIGHT");
                  
            // set message location
               // function: setColor
               setColor(COLOR_WHITE, COLOR_RED, 1);
            // report incorrect amount entered
               // function: printStringAt    
                     printStringAt( xLoc2, yLoc2 , "Ticket Purchase Not Completed", "CENTER" );
                     printStringAt( xLoc2, yLoc2 + 1 , "Incorrect Amount Tendered", "CENTER" );
                    } 

   }
