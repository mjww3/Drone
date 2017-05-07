// Generated by gencpp from file mavros/WaypointGOTORequest.msg
// DO NOT EDIT!


#ifndef MAVROS_MESSAGE_WAYPOINTGOTOREQUEST_H
#define MAVROS_MESSAGE_WAYPOINTGOTOREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <mavros/Waypoint.h>

namespace mavros
{
template <class ContainerAllocator>
struct WaypointGOTORequest_
{
  typedef WaypointGOTORequest_<ContainerAllocator> Type;

  WaypointGOTORequest_()
    : waypoint()  {
    }
  WaypointGOTORequest_(const ContainerAllocator& _alloc)
    : waypoint(_alloc)  {
  (void)_alloc;
    }



   typedef  ::mavros::Waypoint_<ContainerAllocator>  _waypoint_type;
  _waypoint_type waypoint;




  typedef boost::shared_ptr< ::mavros::WaypointGOTORequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros::WaypointGOTORequest_<ContainerAllocator> const> ConstPtr;

}; // struct WaypointGOTORequest_

typedef ::mavros::WaypointGOTORequest_<std::allocator<void> > WaypointGOTORequest;

typedef boost::shared_ptr< ::mavros::WaypointGOTORequest > WaypointGOTORequestPtr;
typedef boost::shared_ptr< ::mavros::WaypointGOTORequest const> WaypointGOTORequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros::WaypointGOTORequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros::WaypointGOTORequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mavros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'mavros': ['/home/mukul/Landing/src/mavros/mavros/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'diagnostic_msgs': ['/opt/ros/indigo/share/diagnostic_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mavros::WaypointGOTORequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros::WaypointGOTORequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros::WaypointGOTORequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros::WaypointGOTORequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros::WaypointGOTORequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros::WaypointGOTORequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros::WaypointGOTORequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "aeb81a83418666b5948fe3f24d59594e";
  }

  static const char* value(const ::mavros::WaypointGOTORequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xaeb81a83418666b5ULL;
  static const uint64_t static_value2 = 0x948fe3f24d59594eULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros::WaypointGOTORequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros/WaypointGOTORequest";
  }

  static const char* value(const ::mavros::WaypointGOTORequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros::WaypointGOTORequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
\n\
\n\
mavros/Waypoint waypoint\n\
\n\
================================================================================\n\
MSG: mavros/Waypoint\n\
# Waypoint.msg\n\
#\n\
# ROS representation of MAVLink MISSION_ITEM\n\
# See mavlink documentation\n\
\n\
\n\
\n\
# see enum MAV_FRAME\n\
uint8 frame\n\
uint8 FRAME_GLOBAL = 0\n\
uint8 FRAME_LOCAL_NED = 1\n\
uint8 FRAME_MISSION = 2\n\
uint8 FRAME_GLOBAL_REL_ALT = 3\n\
uint8 FRAME_LOCAL_ENU = 4\n\
\n\
# see enum MAV_CMD\n\
uint16 command\n\
uint16 NAV_WAYPOINT = 16\n\
uint16 NAV_LOITER_UNLIM = 17\n\
uint16 NAV_LOITER_TURNS = 18\n\
uint16 NAV_LOITER_TIME = 19\n\
uint16 NAV_RETURN_TO_LAUNCH = 20\n\
uint16 NAV_LAND = 21\n\
uint16 NAV_TAKEOFF = 22\n\
# TODO: ROI mode\n\
\n\
bool is_current\n\
bool autocontinue\n\
# meaning of this params described in enum MAV_CMD\n\
float32 param1\n\
float32 param2\n\
float32 param3\n\
float32 param4\n\
float64 x_lat\n\
float64 y_long\n\
float64 z_alt\n\
";
  }

  static const char* value(const ::mavros::WaypointGOTORequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros::WaypointGOTORequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.waypoint);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct WaypointGOTORequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros::WaypointGOTORequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros::WaypointGOTORequest_<ContainerAllocator>& v)
  {
    s << indent << "waypoint: ";
    s << std::endl;
    Printer< ::mavros::Waypoint_<ContainerAllocator> >::stream(s, indent + "  ", v.waypoint);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MESSAGE_WAYPOINTGOTOREQUEST_H
