#include <kipr/botball.h>
#include <Movement.h>


double bias = 0.0;

//int arm_max = 1700;
//int arm_max = 1700;
int arm_valve = arm_max - 225;
int arm_mats = arm_max - 105;
int arm_min = 1700 - 1600;
int hand_max = 1700;
int hand_min = 1700 - 900;
int hand_mats = 1700 - 900;
//int hand_prism_close;
int hand_start = 1700;
int white = 1;
int black = 2;
int front_button()
{
    return digital(frontbutton);
}





int total;
int i;
int buffer(int sensor)
{
    total = 0;
    i = 0;
    while(i<5){
        i = i+1;
        total = total + analog(sensor);
        msleep(1);
    }
    return(total/5);
}

void move(int l_speed,int r_speed){
    mav(R_motor,r_speed);
    mav(L_motor,l_speed);
}

void square_up(int ending,int speed){
    if(speed > 0 && speed < 850){
        black_speed = 1.2*speed;
    }
    else{black_speed = 0.25*speed;}
    if(ending == 1 || ending == 2){
        while(1){
            if(analog(left_IR)<analog_white && analog(right_IR)<analog_white){
                move(speed,speed);
            }
            if(analog(right_IR)>analog_white){
                move(speed,stop);
            }
            if(analog(left_IR)>analog_white){
                move(stop,speed);
            }
            if(analog(left_IR)>analog_white && analog(right_IR)>analog_white) {
                move(stop,stop);
                break;
            }
        }
    }
    if(ending == 3){
        ao();
    }
    switch(ending){
        case 3:
            {
                while(1){
                    if(digital(right_IR)==0 && digital(left_IR)==0){
                        move(speed,speed);
                    }
                    if(digital(right_IR)==1){
                        move(speed,stop);
                    }
                    if(digital(left_IR)==1){
                        move(stop,speed);
                    }
                    if(digital(right_IR)==1 && digital(left_IR)==1){
                        move(stop,stop);
                        break;
                    }
                }
            }
        case 1:
            {
                while(1){
                    if(analog(left_IR)>analog_white && analog(right_IR)>analog_white){
                        move(black_speed,black_speed);
                    }
                    if(analog(left_IR)<analog_white){
                        move(stop,black_speed);
                    }
                    if(analog(right_IR)<analog_white){
                        move(black_speed,stop);
                    }
                    if(analog(left_IR)<analog_white && analog(right_IR)<analog_white){
                        move(stop,stop);
                        break;
                    }
                }
            }
        case 2:
            {
                while(1){
                    if(analog(left_IR)>analog_white && analog(right_IR)>analog_white){
                        move(-1*black_speed,-1*black_speed);
                    }
                    if(analog(left_IR)<analog_white){
                        move(stop,-1*black_speed);
                    }
                    if(analog(right_IR)<analog_white){
                        move(-1*black_speed,stop);
                    }
                    if(analog(left_IR)<analog_white && analog(right_IR)<analog_white){
                        move(stop,stop);
                        break;
                    }
                }
            }
    }
}
/*void square_up(int ending,int speed){
    if(speed > 0 && speed < 600){
        black_speed = 0.5*speed;
    }
    else{black_speed = 0.25*speed;}
    if(ending == 1 || ending == 2){
        while(1){
            if(get_create_lfcliff_amt()>cliff && get_create_rfcliff_amt()>cliff){
                create_drive_direct(speed,speed);
            }
            if(get_create_rfcliff_amt()<cliff){
                create_drive_direct(speed,stop);
            }
            if(get_create_lfcliff_amt()<cliff){
                create_drive_direct(stop,speed);
            }
            if(get_create_lfcliff_amt()<cliff && get_create_rfcliff_amt()<cliff) {
                create_drive_direct(stop,stop);
                break;
            }
        }
    }
    switch(ending){
        case 1:
            {
                while(1){
                    if(get_create_lfcliff_amt()<cliff && get_create_rfcliff_amt()<cliff){
                        create_drive_direct(black_speed,black_speed);
                    }
                    if(get_create_lfcliff_amt()>cliff){
                        create_drive_direct(stop,black_speed);
                    }
                    if(get_create_rfcliff_amt()>cliff){
                        create_drive_direct(black_speed,stop);
                    }
                    if(get_create_lfcliff_amt()>cliff && get_create_rfcliff_amt()>cliff){
                        create_drive_direct(stop,stop);
                        break;
                    }
                }
            }
        case 2:
            {
                while(1){
                    if(get_create_lfcliff_amt()<cliff && get_create_rfcliff_amt()<cliff){
                        create_drive_direct(-1*black_speed,-1*black_speed);
                    }
                    if(get_create_lfcliff_amt()>cliff){
                        create_drive_direct(stop,-1*black_speed);
                    }
                    if(get_create_rfcliff_amt()>cliff){
                        create_drive_direct(-1*black_speed,stop);
                    }
                    if(get_create_lfcliff_amt()>cliff && get_create_rfcliff_amt()>cliff){
                        create_drive_direct(stop,stop);
                        break;
                    }
                }
            }
    }
} */

double calibrate_gyro(){
    int i = 0;
    double avg = 0;
    while( i < 50){
        avg += gyro_z();
        msleep(1);
        i++;
        printf("Gyro Z: %d\n",gyro_z());
    }
    bias = avg / 50.0;
    printf("New Bias: %f\n", bias);
    return bias;
}

void slow_arm (int x,int speed)//this funtion slows 
{ 

    enable_servo (arm);
    int desired_position;
    int current_position = get_servo_position(arm);
    if (0) {desired_position = arm_max;}
    else if(0) {desired_position = arm_min;}
    else {desired_position = x;}

    switch(speed){
        case 1:
            while(current_position <= desired_position-2 || current_position >= desired_position+2)
            {
                if(current_position < desired_position)
                { current_position=current_position +2;
                 set_servo_position(arm, current_position);
                 msleep(1);
                }
                if(current_position > desired_position)
                { current_position=current_position -2;
                 set_servo_position(arm, current_position);

                 msleep(1);
                }
            }
            break;
        case 2:
            while(current_position != desired_position)
            {
                if(current_position < desired_position)
                { current_position=current_position +1;
                 set_servo_position(arm, current_position);
                 msleep(2);
                }
                if(current_position > desired_position)
                { current_position=current_position -1;
                 set_servo_position(arm, current_position);

                 msleep(2);
                }
            }
            break;
    }

    set_servo_position (arm, x);
    msleep(15);
    disable_servo (arm);

}

void slow_hand ( int z, int speed )//this funtion slows 
{ 

    enable_servo (hand);
    int desired_position;
    int current_position = get_servo_position(hand);
    if (0) {desired_position = hand_max;}
    else if(0) {desired_position = hand_min;}
    else {desired_position = z;}


    switch(speed){
        case 1:
            while(current_position <= desired_position-2 || current_position >= desired_position+2)
            {
                if(current_position < desired_position)
                { current_position=current_position +2;
                 set_servo_position(hand, current_position);
                 msleep(1);
                }
                if(current_position > desired_position)
                { current_position=current_position -2;
                 set_servo_position(hand, current_position);
                 msleep(1);
                }
            }
            break;
        case 2:

            while(current_position != desired_position)
            {
                if(current_position < desired_position)
                { current_position=current_position +1;
                 set_servo_position(hand, current_position);
                 msleep(2);
                }
                if(current_position > desired_position)
                { current_position=current_position -1;
                 set_servo_position(hand, current_position);

                 msleep(2);
                }
            }
            break;
    }
    set_servo_position (hand, z);
    msleep(15);
    disable_servo (hand);
}



void a_cel(){
    float L_speed;
    float curr_time = seconds(); 
    float init_time = seconds();
    while( (curr_time - init_time) < .2 ){
        curr_time = seconds();   
        L_speed = 6.75 * ((curr_time - init_time) * 1000);
        move(L_speed,L_speed); 
    }
}


void de_cel(){


    cmpc(L_motor);
    cmpc(R_motor);
    while(gmpc(L_motor) < 500){

        int R_speed = 2.4 * (500 - gmpc(R_motor) + 150);
        int L_speed = 2.4 * (500 - gmpc(L_motor) + 150);
        move(L_speed,R_speed);

    }
    move(0,0);
}

int speed;
int distance;


double theta = 0;



void Drive(int desired){

    cmpc(L_motor);
    cmpc(R_motor);
    a_cel();
    //desired = gmpc(L_motor) - desired;
    //desired = desired -500;
    int speed =1350;
    if(desired < speed){
        speed = desired;   
    }
    while(gmpc(L_motor) < (desired-500)){
        if (speed < 0){
            mav(L_motor, (speed - (speed * (theta/100000))));            
            mav(R_motor, (speed + (speed * theta/100000)));
            msleep(10);

            theta += (gyro_z() - bias) * 10;
        }
        else{
            mav(R_motor, (speed - (speed * (theta/100000))));            
            mav(L_motor, (speed + (speed * theta/100000)));
            msleep(10);

            theta += (gyro_z() - bias) * 10;
        }
        //desired = desired - gmpc(L_motor);
    }
    de_cel();
}

void Drive_ET(int distance){

    cmpc(L_motor);
    cmpc(R_motor);
    a_cel();
    double speed =750;
    while(1){
        if(analog(ET)>distance-50 && analog(ET)<distance+50){
            speed = speed/1.035;
        }
        if(analog(ET)>distance-25 || analog(ET)<distance+25){break;}
        else if(analog(ET)<distance){
            mav(R_motor, (speed - (speed * (theta/100000))));            
            mav(L_motor, (speed + (speed * theta/100000)));
            msleep(10);
        }
        else if(analog(ET)>distance){
            mav(R_motor, -1*(speed - (speed * (theta/100000))));            
            mav(L_motor, -1*(speed + (speed * theta/100000)));
            msleep(10);
        }
        theta += (gyro_z() - bias) * 10;
    }
}

/*void Servo(){

    int x; //controls servo 1
    int y; //servo 2
    int z; //servo 3
    while(1){
        double init_time = seconds();
        double elapsed_time = seconds()-init_time;
        if(get_servo_position(1)<x){x=x+2;}
        else if(get_servo_position(1)>x){x=x-2;}
        if(get_servo_position(2)<y && time>30){y=y+2;}
        else if(get_servo_position(2)>y && time<30){y=y-2;}
        if(get_servo_position(3)<z && time>35){z=z+2;}
        else if(get_servo_position(3)>z && time>35){z=z-2;}
    }
}*/

void start_pos()
{
    slow_arm(fast,arm_max);
    set_servo_position(1,hand_min);
}

void turn_with_gyro(int speed, int deg){
    //calibrate_gyro();
    double theta ;
    int targetTheta; 
    switch(deg){
        case 45:
            targetTheta = target_theta_45;
            move(speed,speed*-1);
            break;
        case 60:
            targetTheta = target_theta_60;
            move(speed,speed*-1);
            break;
        case 90:
            targetTheta = target_theta_90;
            move(speed,speed*-1);
            break;
        case 180:
            targetTheta = target_theta_180;
            move(speed,speed*-1);
            break;
        case 360:
            targetTheta = target_theta_360;
            move(speed,speed*-1);
            break;
        case -45:
            targetTheta = target_theta_m45;
            move(speed*-1,speed);
            break;
        case -90:
            targetTheta = target_theta_m90;
            move(speed*-1,speed);
            break;
        case -180:
            targetTheta = target_theta_m180;
            move(speed*-1,speed);
            break;
        case -360:
            targetTheta = target_theta_m360;
            move(speed*-1,speed);
            break;
        default:
            targetTheta = 0;
            break;
    }  
    while(theta < targetTheta){
        msleep(10);
        theta += abs(gyro_z() - bias) * 10;
        printf("Turn Gyro Z: %d\n",gyro_z());
    }
    mav(R_motor, 0);
    mav(R_motor, 0);
    ao();
}

void Drive_SquareUp(int end,int desired){
    cmpc(L_motor);
    cmpc(R_motor);
    a_cel();
    //desired = gmpc(L_motor) - desired;
    //desired = desired -500;
    int speed =1350;
    if(desired < speed){
        speed = desired;   
    }
    while(gmpc(L_motor) < (desired-500)){

        mav(R_motor, (speed - (speed * (theta/100000))));            
        mav(L_motor, (speed + (speed * theta/100000)));
        msleep(10);

        theta += (gyro_z() - bias) * 10;
        //desired = desired - gmpc(L_motor);
    }
    square_up(end, 500);

}

void PID_gyro_drive(int speed, double time){
    calibrate_gyro();
    double startTime = seconds();
    double theta = 0;
    while((seconds() - startTime) < time){
        if(speed > 0){
            mav(R_motor, (speed - (speed * (theta/100000))));            
            mav(L_motor, (speed + (speed * theta/100000)));
        }


        else{
            mav(L_motor, (speed - (speed * theta/100000)));            
            mav(R_motor, (speed + (speed * (theta/100000))));
        }
        msleep(10);
        theta += (gyro_z() - bias) * 10;
    }
    move(0,0);
}
void start_position(){
    set_servo_position(mainservo,mainservo_down);
    set_servo_position(thingy,thingy_up);
    slow_arm(334, 60);
}
void meople_open(){
    set_servo_position(mainservo,mainservo_up);
}

void drive_fast(){
    motor(L_motor,93);
    motor(R_motor,90);
}


void meople_closed(){
    set_servo_position(mainservo,mainservo_down);
}
void mainservo_meople(){

    set_servo_position(mainservo,mainservo_low);


}

void line_follow_fast(int nrticks)
{cmpc(R_motor);
 while(gmpc(R_motor) < nrticks)
 {
     if(analog(left_IR) > analog_white && analog(right_IR) < analog_white)
     {
         motor(L_motor,80);
         motor(R_motor,94);   
     }
     if(analog(left_IR) > analog_white && analog(right_IR) > analog_white)
     {
         motor(L_motor,80);
         motor(R_motor,76);   
     }

     if(analog(left_IR) < analog_white && analog(right_IR) > analog_white)
     {
         motor(L_motor,98);
         motor(R_motor,76);
     }
 }
}
void collect_meople(int degree){
    turn_with_gyro(800, degree);
    back_square_up();
    square_up(white,800);
    meople_open();
    msleep(1500);
    set_servo_position(thingy,thingy_middle);
    msleep(500);
    while (front_button()==0)
    {drive_fast();
    }
    ao();
    slow_mainservo(mainservo_down,20);
    msleep(1000);
    drive_backwards(-2000);
    back_square_up();
    square_up(white,800);
}
void drive_backwards(int nrticks){
    cmpc(R_motor);
    while(gmpc(R_motor) > nrticks){
        motor(L_motor, -53);
        motor(R_motor, -50);
    }
}
void linefollow_backwards(int nrticks)
{cmpc(R_motor);
 while (gmpc(R_motor) > nrticks)
 {
     if(analog(back_IR) > analog_white && analog(right_IR) < analog_white)
     {
         motor(L_motor,-40);
         motor(R_motor,-46);   
     }
     if(analog(back_IR) > analog_white && analog(right_IR) > analog_white)
     {
         motor(L_motor,-40);
         motor(R_motor,-46);   
     }

     if(analog(back_IR) < analog_white)
     {
         motor(L_motor,-50);
         motor(R_motor,-36);
     }
    
 }
}

void right_line_follow(int nrticks)
{
    cmpc(R_motor);
    while(gmpc(R_motor) < nrticks)
    {
        if(analog(right_IR) < analog_white)
        {
           	move(500,600);
        }
        if(analog(right_IR) > analog_white)
        {
            move(600,500);
        }
    }      
}

void line_follow_slow(int nrticks){
    cmpc(R_motor);
    while(gmpc(R_motor) < nrticks)
    {
        if(analog(left_IR) > analog_white && analog(right_IR) < analog_white)
        {
            motor(L_motor,20);
            motor(R_motor,50);   
        }
        if(analog(left_IR) > analog_white && analog(right_IR) > analog_white)
        {
            motor(L_motor,40);
            motor(R_motor,36);   
        }

        if(analog(left_IR) < analog_white && analog(right_IR) > analog_white)
        {
            motor(L_motor,52);
            motor(R_motor,16);
        }
    }
}
/*void side_ET_linefollow(){
    while(leftET > 650){
        if (leftET < 500){
            break;
        }
        else 
        {
            line_follow();
        }
    }
}*/
void line_follow_ET(int bigETvalue, int smallETvalue)
{enable_servo(thingy);
 set_servo_position(thingy,thingy_up);
 msleep(500);
 while(leftET > bigETvalue)
 {
     if(leftET < smallETvalue){
         break;
     }
     else
     {
         if(analog(left_IR) > analog_white && analog(right_IR) < analog_white)
         {
             motor(L_motor,90);
             motor(R_motor,94);   
         }
         if(analog(left_IR) > analog_white && analog(right_IR) > analog_white)
         {
             motor(L_motor,90);
             motor(R_motor,86);   
         }

         if(analog(left_IR) < analog_white && analog(right_IR) > analog_white)
         {
             motor(L_motor,98);
             motor(R_motor,86);
         }
     }
 }
}
void back_square_up(){
    while(1){
        if(analog(left_IR)<analog_white && analog(right_IR)<analog_white){
            motor(L_motor,-90);
            motor(R_motor,-86);   
        }
        if(analog(right_IR)>analog_white){
            motor(L_motor,-50);
            motor(R_motor,0);   
        }
        if(analog(left_IR)>analog_white){
            motor(L_motor,0);
            motor(R_motor,-46);   
        }
        if(analog(left_IR)>analog_white && analog(right_IR)>analog_white) {
            ao(); 
            break;
        }
    }
}
void slow_mainservo (int x,int speed)//this funtion slows 
{ 

    enable_servo (mainservo);
    int desired_position;
    int current_position = get_servo_position(mainservo);
    if (0) {desired_position = mainservo_down;}
    else if(0) {desired_position = mainservo_up;}
    else {desired_position = x;}

    switch(speed){
        case 1:
            while(current_position <= desired_position-2 || current_position >= desired_position+2)
            {
                if(current_position < desired_position)
                { current_position=current_position +2;
                 set_servo_position(mainservo, current_position);
                 msleep(1);
                }
                if(current_position > desired_position)
                { current_position=current_position -2;
                 set_servo_position(mainservo, current_position);

                 msleep(1);
                }
            }
            break;
        case 2:
            while(current_position != desired_position)
            {
                if(current_position < desired_position)
                { current_position=current_position +1;
                 set_servo_position(mainservo, current_position);
                 msleep(2);
                }
                if(current_position > desired_position)
                { current_position=current_position -1;
                 set_servo_position(mainservo, current_position);

                 msleep(2);
                }
            }
            break;
    }

    set_servo_position (mainservo, x);
    msleep(15);
    disable_servo (mainservo);

}

void push_packets(){
    meople_closed();
    set_servo_position(thingy,thingy_up);
    msleep(500);
    bumpy_drive();
    msleep(500);
}
void drive_right(int nrticks)
{ cmpc(L_motor);
 if (nrticks > 0)
 {
     while (gmpc(L_motor) < nrticks)
     {
         motor(R_motor, 34);
         motor(L_motor, 40);
     }
 }
 if (nrticks < 0) 
 { 
     while (gmpc(L_motor) > nrticks)
     {
         motor(R_motor, -34);
         motor(L_motor, -40);
     }
 }
}
void IR_turn() 
{
    //turn_with_gyro(800,90);
    //  int count = 0;
    turn_with_gyro(800,45);
    /*while (count < 10)
    { 

        count = count + 1;*/
    while(right_IR < 3000)   
    {
        motor(R_motor,-54);
        motor(L_motor,50);
    }
    /* if (right_IR > 3000)
        { count = 0;
        break;} 


    }*/
    /*
    while (count < 10)
    {
        count = count + 1;
        if(left_IR < analog_white)
        {
            motor(R_motor,-54);
            motor(L_motor,50);
        }
        else
        {
            break;
        }
    }*/
}
void line_follow_fast_while()
{
    if(analog(left_IR) > analog_white && analog(right_IR) < analog_white)
    {
        motor(L_motor,80);
        motor(R_motor,94);   
    }
    if(analog(left_IR) > analog_white && analog(right_IR) > analog_white)
    {
        motor(L_motor,80);
        motor(R_motor,76);   
    }

    if(analog(left_IR) < analog_white && analog(right_IR) > analog_white)
    {
        motor(L_motor,98);
        motor(R_motor,76);
    }
}
void bumpy_drive()
{
    while (gyro_y() > -1000)
    {
        if (gyro_y() < -250)
        {
            break;
        }
        if (gyro_y() > -1000)
        {
            line_follow_fast_while();
        }
    }
}

void linefollow(int distance)
{
    cmpc(R_motor);
    while(gmpc(R_motor)<distance)
    {
        mav(R_motor,.35*(analog(front_IR)));
        mav(L_motor,.35*(3300-analog(front_IR)));
    }
}

void linefollow_b(int distance)
{
    cmpc(R_motor);
    while(gmpc(R_motor) > -1 * distance)
    {
        mav(R_motor,-1*.35*(analog(back_IR)));
        mav(L_motor,-1*.35*(3300-analog(back_IR))); 
    }
}

void until_bump()
{
    cmpc(R_motor);
    while(digital(bumper) != 1)
    {
        if(gmpc(R_motor) > 3000)
        {
            break;
        }
        move(800,800);
    }   
    move(500,500);
    msleep(500);
}
