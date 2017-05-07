// Generated by gencpp from file mavros/FileChecksumRequest.msg
// DO NOT EDIT!


#ifndef MAVROS_MESSAGE_FILECHECKSUMREQUEST_H
#define MAVROS_MESSAGE_FILECHECKSUMREQUEST_H


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
struct FileChecksumRequest_
{
  typedef FileChecksumRequest_<ContainerAllocator> Type;

  FileChecksumRequest_()
    : file_path()  {
    }
  FileChecksumRequest_(const ContainerAllocator& _alloc)
    : file_path(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _file_path_type;
  _file_path_type file_path;




  typedef boost::shared_ptr< ::mavros::FileChecksumRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros::FileChecksumRequest_<ContainerAllocator> const> ConstPtr;

}; // struct FileChecksumRequest_

typedef ::mavros::FileChecksumRequest_<std::allocator<void> > FileChecksumRequest;

typedef boost::shared_ptr< ::mavros::FileChecksumRequest > FileChecksumRequestPtr;
typedef boost::shared_ptr< ::mavros::FileChecksumRequest const> FileChecksumRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros::FileChecksumRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros::FileChecksumRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::mavros::FileChecksumRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros::FileChecksumRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros::FileChecksumRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros::FileChecksumRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros::FileChecksumRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros::FileChecksumRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros::FileChecksumRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a1f82596372c52a517e1fe32d1e998e8";
  }

  static const char* value(const ::mavros::FileChecksumRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa1f82596372c52a5ULL;
  static const uint64_t static_value2 = 0x17e1fe32d1e998e8ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros::FileChecksumRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros/FileChecksumRequest";
  }

  static const char* value(const ::mavros::FileChecksumRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros::FileChecksumRequest_<ContainerAllocator> >
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
string file_path\n\
";
  }

  static const char* value(const ::mavros::FileChecksumRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros::FileChecksumRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.file_path);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct FileChecksumRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros::FileChecksumRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros::FileChecksumRequest_<ContainerAllocator>& v)
  {
    s << indent << "file_path: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.file_path);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MESSAGE_FILECHECKSUMREQUEST_H
