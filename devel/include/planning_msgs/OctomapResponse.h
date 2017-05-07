// Generated by gencpp from file planning_msgs/OctomapResponse.msg
// DO NOT EDIT!


#ifndef PLANNING_MSGS_MESSAGE_OCTOMAPRESPONSE_H
#define PLANNING_MSGS_MESSAGE_OCTOMAPRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <octomap_msgs/Octomap.h>

namespace planning_msgs
{
template <class ContainerAllocator>
struct OctomapResponse_
{
  typedef OctomapResponse_<ContainerAllocator> Type;

  OctomapResponse_()
    : map()  {
    }
  OctomapResponse_(const ContainerAllocator& _alloc)
    : map(_alloc)  {
  (void)_alloc;
    }



   typedef  ::octomap_msgs::Octomap_<ContainerAllocator>  _map_type;
  _map_type map;




  typedef boost::shared_ptr< ::planning_msgs::OctomapResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::planning_msgs::OctomapResponse_<ContainerAllocator> const> ConstPtr;

}; // struct OctomapResponse_

typedef ::planning_msgs::OctomapResponse_<std::allocator<void> > OctomapResponse;

typedef boost::shared_ptr< ::planning_msgs::OctomapResponse > OctomapResponsePtr;
typedef boost::shared_ptr< ::planning_msgs::OctomapResponse const> OctomapResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::planning_msgs::OctomapResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::planning_msgs::OctomapResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::planning_msgs::OctomapResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::planning_msgs::OctomapResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::planning_msgs::OctomapResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::planning_msgs::OctomapResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::planning_msgs::OctomapResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::planning_msgs::OctomapResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::planning_msgs::OctomapResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "be9d2869d24fe40d6bc21ac21f6bb2c5";
  }

  static const char* value(const ::planning_msgs::OctomapResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbe9d2869d24fe40dULL;
  static const uint64_t static_value2 = 0x6bc21ac21f6bb2c5ULL;
};

template<class ContainerAllocator>
struct DataType< ::planning_msgs::OctomapResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "planning_msgs/OctomapResponse";
  }

  static const char* value(const ::planning_msgs::OctomapResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::planning_msgs::OctomapResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "octomap_msgs/Octomap map\n\
\n\
\n\
================================================================================\n\
MSG: octomap_msgs/Octomap\n\
# A 3D map in binary format, as Octree\n\
Header header\n\
\n\
# Flag to denote a binary (only free/occupied) or full occupancy octree (.bt/.ot file)\n\
bool binary\n\
\n\
# Class id of the contained octree \n\
string id\n\
\n\
# Resolution (in m) of the smallest octree nodes\n\
float64 resolution\n\
\n\
# binary serialization of octree, use conversions.h to read and write octrees\n\
int8[] data\n\
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
";
  }

  static const char* value(const ::planning_msgs::OctomapResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::planning_msgs::OctomapResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.map);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct OctomapResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::planning_msgs::OctomapResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::planning_msgs::OctomapResponse_<ContainerAllocator>& v)
  {
    s << indent << "map: ";
    s << std::endl;
    Printer< ::octomap_msgs::Octomap_<ContainerAllocator> >::stream(s, indent + "  ", v.map);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PLANNING_MSGS_MESSAGE_OCTOMAPRESPONSE_H
