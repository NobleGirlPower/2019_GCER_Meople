
#include <kipr/botball.h>


#define target_theta_45 235000 //numbers for wallaby-1497
#define target_theta_60 350000
#define target_theta_90 534500
#define target_theta_180 1081500
#define target_theta_360 2175000//not changed
#define target_theta_m45 225000
#define target_theta_m90 507500
#define target_theta_m180 1061500
#define target_theta_m360 2175000
#define target_theta_building 260000
#define target_theta_building_2 260000


#define arm 2 //lift mechanism
#define hand 1
#define ET 2
#define analog_white 2500
#define analog_grey 230
#define analog_black 3800
#define left_IR 1
#define right_IR 3
#define stop 0
#define back_IR 5
#define front_IR 2
#define arm_max 1700
#define leftET 2
#define rightET 4
#define thingy 2
#define thingy_up 100
#define thingy_down 938
#define thingy_middle 600
#define mainservo 1 
#define mainservo_up 800
#define mainservo_down 1400 //1250
#define mainservo_low 1400

//#define mainservo_meople 1400
#define frontbutton 0
#define L_motor 3
#define R_motor 1
#define fast 2
#define slow 1
#define bumper 0
int white;
int black;
int arm_valve;
int arm_mats;
int arm_min;
int arm_building;
int hand_max;
int hand_min;
int hand_mats;
int hand_prism_close;
int hand_start;


int physical;
int black_speed;


void slow_arm ( int x,int speed);//this funtion slows 
void slow_mainservo( int x, int speed);
void slow_hand ( int z, int speed);

void move(int l_speed,int r_speed);

double bias;
double calibrate_gyro();
int i;
double avg;

void square_up(int ending,int speed);

void start_pos();

void PID_gyro_drive(int speed, double time);
void PID_gyro_drive_distance(int speed,int distance);
double startTime;
double theta ;
void Drive(int desired);
void Drive_ET(int distance);

void turn_with_gyro(int speed, int deg);

void Drive_SquareUp(int end,int desired);
void start_position();
void meople_closed();
void meople_open();
void drive_fast();
void line_follow_fast(int nrticks);
void collect_meople(int degree);
void linefollow_backwards(int nrticks);
void line_follow_slow(int nrticks);
void side_ET_linefollow();
void line_follow_ET(int bigETvalue, int smallETvalue);
void drive_backwards(int nrticks);
void back_square_up();
void push_packets();
void drive_right(int nrticks);
void bumpy_drive();
void IR_turn();
void ET_follow();
void linefollow(int distance);
void linefollow_b(int distance);
void until_bump();