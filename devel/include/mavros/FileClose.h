// Generated by gencpp from file mavros/FileClose.msg
// DO NOT EDIT!


#ifndef MAVROS_MESSAGE_FILECLOSE_H
#define MAVROS_MESSAGE_FILECLOSE_H

#include <ros/service_traits.h>


#include <mavros/FileCloseRequest.h>
#include <mavros/FileCloseResponse.h>


namespace mavros
{

struct FileClose
{

typedef FileCloseRequest Request;
typedef FileCloseResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct FileClose
} // namespace mavros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::mavros::FileClose > {
  static const char* value()
  {
    return "1c309002d7f7c6df7d3f094925ea8e10";
  }

  static const char* value(const ::mavros::FileClose&) { return value(); }
};

template<>
struct DataType< ::mavros::FileClose > {
  static const char* value()
  {
    return "mavros/FileClose";
  }

  static const char* value(const ::mavros::FileClose&) { return value(); }
};


// service_traits::MD5Sum< ::mavros::FileCloseRequest> should match 
// service_traits::MD5Sum< ::mavros::FileClose > 
template<>
struct MD5Sum< ::mavros::FileCloseRequest>
{
  static const char* value()
  {
    return MD5Sum< ::mavros::FileClose >::value();
  }
  static const char* value(const ::mavros::FileCloseRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros::FileCloseRequest> should match 
// service_traits::DataType< ::mavros::FileClose > 
template<>
struct DataType< ::mavros::FileCloseRequest>
{
  static const char* value()
  {
    return DataType< ::mavros::FileClose >::value();
  }
  static const char* value(const ::mavros::FileCloseRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::mavros::FileCloseResponse> should match 
// service_traits::MD5Sum< ::mavros::FileClose > 
template<>
struct MD5Sum< ::mavros::FileCloseResponse>
{
  static const char* value()
  {
    return MD5Sum< ::mavros::FileClose >::value();
  }
  static const char* value(const ::mavros::FileCloseResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros::FileCloseResponse> should match 
// service_traits::DataType< ::mavros::FileClose > 
template<>
struct DataType< ::mavros::FileCloseResponse>
{
  static const char* value()
  {
    return DataType< ::mavros::FileClose >::value();
  }
  static const char* value(const ::mavros::FileCloseResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MAVROS_MESSAGE_FILECLOSE_H