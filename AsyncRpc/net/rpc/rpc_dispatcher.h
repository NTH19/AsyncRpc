#ifndef TINYRPC_NET_TINYPB_TINYPB_RPC_DISPATCHER_H
#define TINYRPC_NET_TINYPB_TINYPB_RPC_DISPATCHER_H

#include <google/protobuf/message.h>
#include <google/protobuf/service.h>
#include <google/protobuf/descriptor.h>
#include <map>
#include <memory>

#include "AsyncRpc/net/abstract_dispatcher.h"
#include "AsyncRpc/net/rpc/rpc_data.h"


namespace AsyncRpc {

class RpcDispacther : public AbstractDispatcher {
 public:

  // typedef std::shared_ptr<TinyPbRpcDispacther> ptr;
  typedef std::shared_ptr<google::protobuf::Service> service_ptr;

  RpcDispacther() = default;
  ~RpcDispacther() = default;

  void dispatch(AbstractData* data, TcpConnection* conn);

  bool parseServiceFullName(const std::string& full_name, std::string& service_name, std::string& method_name);

  void registerService(service_ptr service);

 public:

  // all services should be registerd on there before progress start
  // key: service_name
  std::map<std::string, service_ptr> m_service_map;

};


}



#endif