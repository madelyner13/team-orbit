#include <string>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <cmath>

int main(int argc, char** argv) {

	ros::init(argc, argv, "state_publisher");
	ros::NodeHandle n;
	ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
//	tf::TransformBroadcaster broadcaster;
	ros::Rate loop_rate(30);

//	const double degree = M_PI/180;

	double j1 = 0, j3 = 0, j6 = 0, j9 = 0, j11 = 0, j12 = 0, j17 = 0, pi = acos(0);
	double j3_inc = 0.05235, j6_inc = 0.052357, j9_inc = 0.0279217, j12_inc = 0.022333;

	geometry_msgs::TransformStamped odom_trans;
	sensor_msgs::JointState joint_state;
//	odom_trans.header.frame_id = "odom";
//	odom_trans.child_frame_id = "axis";

	while (ros::ok()) {

		joint_state.header.stamp = ros::Time::now();
		joint_state.name.resize(7);
		joint_state.position.resize(7);
		joint_state.name[0] = "joint_1";
		joint_state.position[0] = j1;
		joint_state.name[1] = "joint_3";
		joint_state.position[1] = j3;
		joint_state.name[2] = "joint_6";
		joint_state.position[2] = j6;
		joint_state.name[3] = "joint_9";
		joint_state.position[3] = j9;
		joint_state.name[4] = "joint_11";
		joint_state.position[4] = j11;
		joint_state.name[5] = "joint_12";
		joint_state.position[5] = j12;
		joint_state.name[6] = "joint_17";
		joint_state.position[6] = j17;

//		odom_trans.header.stamp = ros::Time::now();
//		odom_trans.transform.translation.x = cos(angle) * 2;
//		odom_trans.transform.translation.y = sin(angle) * 2;
//		odom_trans.transform.translation.z = 0.7;
//		odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(angle+M_PI/2);

		// sending joint state
		joint_pub.publish(joint_state);
//		broadcaster.sendTransform(odom_trans);	

		// creating a new robot state
		j1 += pi;
		j3 += j3_inc;
		if (j3 <= -0.5235 || j3 >= 1.047) j3_inc *= -1;
		j6 += j6_inc;
		if (j6 <= 0 || j6 >= 1.5707) j6_inc *= -1;
		j9 += j9_inc;
		if (j9 <= -0.7853 || j9 >= 0.5235) j9_inc *= -1;
		j11 -= pi;
		j12 += j12_inc;
		if (j12 <= 0 || j12 >= 0.67) j12_inc *= -1;
		j17 = j12;		

		loop_rate.sleep();

	}

return 0;

}
