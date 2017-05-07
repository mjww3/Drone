// Generated by gencpp from file planning_msgs/PlannerServiceRequest.msg
// DO NOT EDIT!


#ifndef PLANNING_MSGS_MESSAGE_PLANNERSERVICEREQUEST_H
#define PLANNING_MSGS_MESSAGE_PLANNERSERVICEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>

namespace planning_msgs
{
template <class ContainerAllocator>
struct PlannerServiceRequest_
{
  typedef PlannerServiceRequest_<ContainerAllocator> Type;

  PlannerServiceRequest_()
    : start_pose()
    , start_velocity()
    , goal_pose()
    , goal_velocity()
    , bounding_box()  {
    }
  PlannerServiceRequest_(const ContainerAllocator& _alloc)
    : start_pose(_alloc)
    , start_velocity(_alloc)
    , goal_pose(_alloc)
    , goal_velocity(_alloc)
    , bounding_box(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _start_pose_type;
  _start_pose_type start_pose;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _start_velocity_type;
  _start_velocity_type start_velocity;

   typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _goal_pose_type;
  _goal_pose_type goal_pose;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _goal_velocity_type;
  _goal_velocity_type goal_velocity;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _bounding_box_type;
  _bounding_box_type bounding_box;




  typedef boost::shared_ptr< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct PlannerServiceRequest_

typedef ::planning_msgs::PlannerServiceRequest_<std::allocator<void> > PlannerServiceRequest;

typedef boost::shared_ptr< ::planning_msgs::PlannerServiceRequest > PlannerServiceRequestPtr;
typedef boost::shared_ptr< ::planning_msgs::PlannerServiceRequest const> PlannerServiceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace planning_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'planning_msgs': ['/home/mukul/Landing/src/mav_comm/planning_msgs/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'octomap_msgs': ['/home/mukul/simulation/ros_catkin_ws/src/octomap_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6090fe8ab3df1362b8c26859b8850940";
  }

  static const char* value(const ::planning_msgs::PlannerServiceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6090fe8ab3df1362ULL;
  static const uint64_t static_value2 = 0xb8c26859b8850940ULL;
};

template<class ContainerAllocator>
struct DataType< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "planning_msgs/PlannerServiceRequest";
  }

  static const char* value(const ::planning_msgs::PlannerServiceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
geometry_msgs/PoseStamped start_pose\n\
geometry_msgs/Vector3 start_velocity\n\
geometry_msgs/PoseStamped goal_pose\n\
geometry_msgs/Vector3 goal_velocity\n\
geometry_msgs/Vector3 bounding_box\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::planning_msgs::PlannerServiceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.start_pose);
      stream.next(m.start_velocity);
      stream.next(m.goal_pose);
      stream.next(m.goal_velocity);
      stream.next(m.bounding_box);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct PlannerServiceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::planning_msgs::PlannerServiceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::planning_msgs::PlannerServiceRequest_<ContainerAllocator>& v)
  {
    s << indent << "start_pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.start_pose);
    s << indent << "start_velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.start_velocity);
    s << indent << "goal_pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_pose);
    s << indent << "goal_velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_velocity);
    s << indent << "bounding_box: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.bounding_box);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PLANNING_MSGS_MESSAGE_PLANNERSERVICEREQUEST_H
