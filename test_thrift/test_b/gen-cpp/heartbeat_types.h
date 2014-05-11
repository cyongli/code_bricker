/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef heartbeat_TYPES_H
#define heartbeat_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>




typedef struct _heartbeat__isset {
  _heartbeat__isset() : hostname(false), cpu_util(false), mem_util(false), disk_util(false) {}
  bool hostname;
  bool cpu_util;
  bool mem_util;
  bool disk_util;
} _heartbeat__isset;

class heartbeat {
 public:

  static const char* ascii_fingerprint; // = "404E13C197753240A95904827D10660E";
  static const uint8_t binary_fingerprint[16]; // = {0x40,0x4E,0x13,0xC1,0x97,0x75,0x32,0x40,0xA9,0x59,0x04,0x82,0x7D,0x10,0x66,0x0E};

  heartbeat() : hostname(), cpu_util(0), mem_util(0), disk_util(0) {
  }

  virtual ~heartbeat() throw() {}

  std::string hostname;
  double cpu_util;
  double mem_util;
  double disk_util;

  _heartbeat__isset __isset;

  void __set_hostname(const std::string& val) {
    hostname = val;
  }

  void __set_cpu_util(const double val) {
    cpu_util = val;
  }

  void __set_mem_util(const double val) {
    mem_util = val;
  }

  void __set_disk_util(const double val) {
    disk_util = val;
  }

  bool operator == (const heartbeat & rhs) const
  {
    if (!(hostname == rhs.hostname))
      return false;
    if (!(cpu_util == rhs.cpu_util))
      return false;
    if (!(mem_util == rhs.mem_util))
      return false;
    if (!(disk_util == rhs.disk_util))
      return false;
    return true;
  }
  bool operator != (const heartbeat &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const heartbeat & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(heartbeat &a, heartbeat &b);



#endif
