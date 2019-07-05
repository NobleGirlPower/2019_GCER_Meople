
#include <kipr/botball.h>
#include <Movement.h>
#include <camera.h> //camera code is here now
//values for driving have to be changed
/*int main()
{ 

    //  IR_turn();
	
    enable_servo(mainservo);
    start_position();
    msleep(3000); 
    //--> wait for light 
    meople_open(); 
    square_up(black,500); //Should square up in the box facing buildings 
    cmpc(R_motor);
	Drive(1000);
    square_up(black,800);// line w/ packages
    meople_closed();
   	Drive(500);
    turn_with_gyro(800 ,90);//turn towards package 4
    msleep(15);
    turn_with_gyro(600,45);
    meople_open();
    msleep(100);
    turn_with_gyro(800,-45);
    ao();//stopped facing electical wires,packages in basket
    msleep(500);
    line_follow_fast(1500);
    ao();
    meople_closed();
    turn_with_gyro(800,180); 
    meople_open();
    line_follow_fast(1000);
    bumpy_drive(); //unload packets @ circle
    enable_servo(thingy);
    set_servo_position(thingy,thingy_down);
    ao();
    msleep(1000);
    cmpc(R_motor);
    linefollow_backwards(-2500);
    ao();
    msleep(1000);
    //push packets
    push_packets();    
    // collect set 1 meople
    linefollow_backwards(-1000);
    enable_servo(thingy);
    collect_meople(90);
    //drive to set 2
    enable_servo(mainservo);
   turn_with_gyro(800,90);
    line_follow_fast(1000);
    line_follow_ET(600,300);  
    line_follow_slow(1300);
  
    // collect set 2 meople
    collect_meople(-90);
    msleep(1000);
    turn_with_gyro(800,-90);
    line_follow_fast(1850);
    //---------------------------------------> check these values before running
    line_follow_fast(7000); //infront of building 2
    line_follow_slow(1500);
    drive_right(800);
    ao();
    msleep(500);
    drive_right(-800);
    enable_servo(thingy);
    set_servo_position(thingy,thingy_down);
    ao();
    msleep(1000);
    cmpc(R_motor);
    linefollow_backwards(-2500);
    //push_packets(3000);
    ao();

    return 0;

}*/
