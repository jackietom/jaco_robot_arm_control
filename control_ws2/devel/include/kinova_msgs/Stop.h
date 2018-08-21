// Generated by gencpp from file kinova_msgs/Stop.msg
// DO NOT EDIT!


#ifndef KINOVA_MSGS_MESSAGE_STOP_H
#define KINOVA_MSGS_MESSAGE_STOP_H

#include <ros/service_traits.h>


#include <kinova_msgs/StopRequest.h>
#include <kinova_msgs/StopResponse.h>


namespace kinova_msgs
{

struct Stop
{

typedef StopRequest Request;
typedef StopResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Stop
} // namespace kinova_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::kinova_msgs::Stop > {
  static const char* value()
  {
    return "585dc4164508d473dff8f8b67a05d2ad";
  }

  static const char* value(const ::kinova_msgs::Stop&) { return value(); }
};

template<>
struct DataType< ::kinova_msgs::Stop > {
  static const char* value()
  {
    return "kinova_msgs/Stop";
  }

  static const char* value(const ::kinova_msgs::Stop&) { return value(); }
};


// service_traits::MD5Sum< ::kinova_msgs::StopRequest> should match 
// service_traits::MD5Sum< ::kinova_msgs::Stop > 
template<>
struct MD5Sum< ::kinova_msgs::StopRequest>
{
  static const char* value()
  {
    return MD5Sum< ::kinova_msgs::Stop >::value();
  }
  static const char* value(const ::kinova_msgs::StopRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::kinova_msgs::StopRequest> should match 
// service_traits::DataType< ::kinova_msgs::Stop > 
template<>
struct DataType< ::kinova_msgs::StopRequest>
{
  static const char* value()
  {
    return DataType< ::kinova_msgs::Stop >::value();
  }
  static const char* value(const ::kinova_msgs::StopRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::kinova_msgs::StopResponse> should match 
// service_traits::MD5Sum< ::kinova_msgs::Stop > 
template<>
struct MD5Sum< ::kinova_msgs::StopResponse>
{
  static const char* value()
  {
    return MD5Sum< ::kinova_msgs::Stop >::value();
  }
  static const char* value(const ::kinova_msgs::StopResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::kinova_msgs::StopResponse> should match 
// service_traits::DataType< ::kinova_msgs::Stop > 
template<>
struct DataType< ::kinova_msgs::StopResponse>
{
  static const char* value()
  {
    return DataType< ::kinova_msgs::Stop >::value();
  }
  static const char* value(const ::kinova_msgs::StopResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // KINOVA_MSGS_MESSAGE_STOP_H