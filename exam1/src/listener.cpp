
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose.h"
#include <sstream>
//Here we have the headers for the subscribers.

int main(int argc, char **argv)
{
 ros::init(argc, argv, "listener");
 ros::NodeHandle n;

 ros::Publisher velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
 ros::Rate loop_rate(1); //1 message per second

   int count = 0;
   /* initialize random seed: */
     srand (time(NULL));
   while (ros::ok()) // Keep spinning loop until user presses Ctrl+C
   {

   geometry_msgs::Twist vel_msg;
   //set a random linear velocity in the x-axis
   vel_msg.linear.x =(double)(rand() % 10 +1)/4.0;
   vel_msg.linear.y =0;
   vel_msg.linear.z =0;
   //set a random angular velocity in the y-axis
   vel_msg.angular.x = 0;
   vel_msg.angular.y = 0;
   vel_msg.angular.z =(double)(rand() % 10 - 5)/2.0;

   //print the content of the message in the terminal
   //randomwalk= turtlesim making random decsisions.
    ROS_INFO("[Random Walk] linear.x = %.2f, angular.z=%.2f\n", vel_msg.linear.x, vel_msg.angular.z);

   //publish the message
   velocity_publisher.publish(vel_msg);
       ros::spinOnce(); // Need to call this function often to allow ROS to process incoming messages

      loop_rate.sleep(); // Sleep for the rest of the cycle.
       count++;
   }
   return 0;
}
