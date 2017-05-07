// Generated by gencpp from file mavros/ParamSetRequest.msg
// DO NOT EDIT!


#ifndef MAVROS_MESSAGE_PARAMSETREQUEST_H
#define MAVROS_MESSAGE_PARAMSETREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mavros
{
template <class ContainerAllocator>
struct ParamSetRequest_
{
  typedef ParamSetRequest_<ContainerAllocator> Type;

  ParamSetRequest_()
    : param_id()
    , integer(0)
    , real(0.0)  {
    }
  ParamSetRequest_(const ContainerAllocator& _alloc)
    : param_id(_alloc)
    , integer(0)
    , real(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _param_id_type;
  _param_id_type param_id;

   typedef int64_t _integer_type;
  _integer_type integer;

   typedef double _real_type;
  _real_type real;




  typedef boost::shared_ptr< ::mavros::ParamSetRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros::ParamSetRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ParamSetRequest_

typedef ::mavros::ParamSetRequest_<std::allocator<void> > ParamSetRequest;

typedef boost::shared_ptr< ::mavros::ParamSetRequest > ParamSetRequestPtr;
typedef boost::shared_ptr< ::mavros::ParamSetRequest const> ParamSetRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros::ParamSetRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros::ParamSetRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mavros

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'mavros': ['/home/mukul/Landing/src/mavros/mavros/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'diagnostic_msgs': ['/opt/ros/indigo/share/diagnostic_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mavros::ParamSetRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros::ParamSetRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros::ParamSetRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros::ParamSetRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros::ParamSetRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros::ParamSetRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros::ParamSetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ea705c97d21e1fbcbf5e474d576723e3";
  }

  static const char* value(const ::mavros::ParamSetRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xea705c97d21e1fbcULL;
  static const uint64_t static_value2 = 0xbf5e474d576723e3ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros::ParamSetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros/ParamSetRequest";
  }

  static const char* value(const ::mavros::ParamSetRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros::ParamSetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
string param_id\n\
int64 integer\n\
float64 real\n\
";
  }

  static const char* value(const ::mavros::ParamSetRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros::ParamSetRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.param_id);
      stream.next(m.integer);
      stream.next(m.real);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ParamSetRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros::ParamSetRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros::ParamSetRequest_<ContainerAllocator>& v)
  {
    s << indent << "param_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.param_id);
    s << indent << "integer: ";
    Printer<int64_t>::stream(s, indent + "  ", v.integer);
    s << indent << "real: ";
    Printer<double>::stream(s, indent + "  ", v.real);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MESSAGE_PARAMSETREQUEST_H
