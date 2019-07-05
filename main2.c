#include <kipr/botball.h>
#include <Movement.h>

int main()
{
	enable_servo(mainservo);
    start_position();
    msleep(3000); 
    //--> wait for light  
    square_up(black,800); 
    turn_with_gyro(500, 90);
    msleep(100);
    turn_with_gyro(500, 60);
    square_up(black,800); 
    square_up(white, 800);
    square_up(black, 800);
    turn_with_gyro(500, -90);
    msleep(100);
    move(1000, 1000);
    msleep(1000);
    ao();
    msleep(100);
    turn_with_gyro(500,45);
    square_up(black, 800);
    square_up(white, 800);
    meople_open();
    move(0,0);
    msleep(100);
    turn_with_gyro(500, -90);
    linefollow(6400);
    linefollow_b(2800);
    msleep(100);
    turn_with_gyro(500, 90);
    square_up(white,-800);
    square_up(black, 800);
    //square_up(white, 800);
    until_bump();
    meople_closed();
    square_up(black, -800);
    //square_up(white, -800);
    msleep(100);
    turn_with_gyro(500, -90);
    linefollow(3400);
    msleep(100);
    turn_with_gyro(500, 90);
    meople_open();
    square_up(white,-800);
    square_up(black, 800);
    until_bump();
    meople_closed();
    square_up(black, -800);
    square_up(white, -800);
    turn_with_gyro(500, -90);
    linefollow(1500);
    meople_open();
    msleep(500);
    move(-1000,-1000);
    msleep(2000);
    
    
    
    
    return 0;
}