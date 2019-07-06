#include <kipr/botball.h>
#include <Movement.h>

int main()
{
	enable_servo(mainservo);
    start_position();
    msleep(1000);
    square_up(black,800); //to check if sensors are working
    //wait_for_light(9); //--> wait for light  
    square_up(black,800); //box line running parrellel w/ package line
    turn_with_gyro(500, 90); 
    msleep(100);
    turn_with_gyro(500, 60);
    square_up(black,800); //square up on box line perpedicular w/ package line
    square_up(white, 800);
    square_up(black, 800); //utility zone box line
    turn_with_gyro(500, -90);
    msleep(100);
    move(1000, 1000);
    msleep(1000);
    ao();
    msleep(100);
    turn_with_gyro(500,45); //turn to ensure farther back on the package line
    square_up(black, 800);
    square_up(white, 800);// square up on package line
    meople_open();
    move(0,0);
    msleep(100);
    turn_with_gyro(500, -90);
    linefollow(5400); //linefollow package line //6400
    linefollow_b(2800);
    meople_closed();
    linefollow(3000);
    linefollow_b(1600); //to change if not aligning with meople correctly
    msleep(100);
    turn_with_gyro(500, 90); //turn towards meople
    square_up(white,-800);
    square_up(black, 800); //square up to package line facing meople
    //square_up(white, 800);
    meople_open();
    until_bump(); //go until lever hits pvc pipe in middle 
    meople_closed();
    square_up(black, -800); //square up to package line 
    //square_up(white, -800);
    msleep(100);
    turn_with_gyro(500, -90);
    linefollow(3400); //line follow package line w/ meople 4
    msleep(100);
    turn_with_gyro(500, 90); //turn towards meople 3
    meople_open();
    square_up(white,-800);
    square_up(black, 800);
    until_bump(); //go until lever hits pvc pipe in middle 
    meople_closed();
    square_up(black, -800);
    square_up(white, -800); //square up to package line 
    turn_with_gyro(500, -90);
    linefollow(1500); //move w/ meople 3 and 4
    meople_open();
    msleep(500);
    move(-1000,-1000); //back up to leave meople
    msleep(2000);
    
    
    
    
    return 0;
}