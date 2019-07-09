/*
 * File:          three_wheels.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */
 // motors and stuff
#include <webots/robot.h>
#include <webots/motor.h> 
//#include <webots/keyboard.h>
//sensors
#include <webots/distance_sensor.h>
#include <webots/light_sensor.h>
//calculations
#include <stdio.h>
#define PI 3.14

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
  wb_robot_init();

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
  WbDeviceTag first_motor = wb_robot_get_device("wheel1");
  WbDeviceTag second_motor = wb_robot_get_device("wheel2");
  WbDeviceTag third_motor = wb_robot_get_device("wheel3");
 
  WbDeviceTag right_distance = wb_robot_get_device("right_light_sensor");
  WbDeviceTag left_distance = wb_robot_get_device("left_light_sensor");
 
  WbDeviceTag first_position = wb_robot_get_device("first_position_sensor");
  WbDeviceTag second_position = wb_robot_get_device("second_position_sensor");
  WbDeviceTag third_position = wb_robot_get_device("third_position_sensor");
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
   
  wb_motor_set_position(first_motor, INFINITY);
  wb_motor_set_position(second_motor, INFINITY);
  wb_motor_set_position(third_motor, INFINITY); 
  
  //wb_keyboard_enable(TIME_STEP); 
  wb_light_sensor_enable(right_distance, TIME_STEP);
  wb_light_sensor_enable(left_distance, TIME_STEP);
  
  wb_position_sensor_enable(first_position, TIME_STEP);
  wb_position_sensor_enable(second_position, TIME_STEP);
  wb_position_sensor_enable(third_position, TIME_STEP);
  
  double rgt_lht_val;
  double lft_lht_val;
  
  double first_ps_val;
  double second_ps_val;
  double third_ps_val;
  
  while (wb_robot_step(TIME_STEP) != -1) {

    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */
     float one_speed = -3.14;
     float second_speed =3.14;
     
     rgt_lht_val = wb_light_sensor_get_value(right_distance);
     printf("Distance sensor value: %lf\n", rgt_lht_val);
     lft_lht_val = wb_light_sensor_get_value(left_distance);
     printf("Distance sensor value: %lf\n",  lft_lht_val);
     
     first_ps_val = wb_position_sensor_get_value(first_position);
     printf("Right position sensor value: %lf\n", first_ps_val);
     second_ps_val = wb_position_sensor_get_value(second_position);
     printf("Left position sensor value: %lf\n", second_ps_val);
     third_ps_val = wb_position_sensor_get_value(third_position);
     printf("Left position sensor value: %lf\n", third_ps_val);
     
     ///satarting motors forward
     wb_motor_set_velocity(first_motor, one_speed);
     wb_motor_set_velocity(second_motor, one_speed);
    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_differential_wheels_set_speed(100.0,100.0);
     */
     
   //Note to professor:
   // have trouble with the light sensor so i cant continue with the 
  // project, in fact the problem doesnt have a solution and dont have enough time to post it
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
