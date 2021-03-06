// Generated by gencpp from file mavros/StreamRate.msg
// DO NOT EDIT!


#ifndef MAVROS_MESSAGE_STREAMRATE_H
#define MAVROS_MESSAGE_STREAMRATE_H

#include <ros/service_traits.h>


#include <mavros/StreamRateRequest.h>
#include <mavros/StreamRateResponse.h>


namespace mavros
{

struct StreamRate
{

typedef StreamRateRequest Request;
typedef StreamRateResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct StreamRate
} // namespace mavros


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::mavros::StreamRate > {
  static const char* value()
  {
    return "d12f7661724c8ba25f67ba597bb7d039";
  }

  static const char* value(const ::mavros::StreamRate&) { return value(); }
};

template<>
struct DataType< ::mavros::StreamRate > {
  static const char* value()
  {
    return "mavros/StreamRate";
  }

  static const char* value(const ::mavros::StreamRate&) { return value(); }
};


// service_traits::MD5Sum< ::mavros::StreamRateRequest> should match 
// service_traits::MD5Sum< ::mavros::StreamRate > 
template<>
struct MD5Sum< ::mavros::StreamRateRequest>
{
  static const char* value()
  {
    return MD5Sum< ::mavros::StreamRate >::value();
  }
  static const char* value(const ::mavros::StreamRateRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros::StreamRateRequest> should match 
// service_traits::DataType< ::mavros::StreamRate > 
template<>
struct DataType< ::mavros::StreamRateRequest>
{
  static const char* value()
  {
    return DataType< ::mavros::StreamRate >::value();
  }
  static const char* value(const ::mavros::StreamRateRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::mavros::StreamRateResponse> should match 
// service_traits::MD5Sum< ::mavros::StreamRate > 
template<>
struct MD5Sum< ::mavros::StreamRateResponse>
{
  static const char* value()
  {
    return MD5Sum< ::mavros::StreamRate >::value();
  }
  static const char* value(const ::mavros::StreamRateResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::mavros::StreamRateResponse> should match 
// service_traits::DataType< ::mavros::StreamRate > 
template<>
struct DataType< ::mavros::StreamRateResponse>
{
  static const char* value()
  {
    return DataType< ::mavros::StreamRate >::value();
  }
  static const char* value(const ::mavros::StreamRateResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MAVROS_MESSAGE_STREAMRATE_H
