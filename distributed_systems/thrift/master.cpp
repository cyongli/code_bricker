#include "gen-cpp/trans_operands.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using boost::shared_ptr;

using namespace test;

#include<iostream>
using std::cout;
using std::cerr;
using std::endl;

class trans_operandsHandler : virtual public trans_operandsIf {
 public:
  trans_operandsHandler() { }

  void trans_operands(const Operand& first, const Operand& second) {
    // Your implementation goes here
    printf("%d\n",first.num+second.num);
  }

};

class testA : public Runnable{
	public:
	 void run(){
		cout << "Hello world!" << endl;
		sleep(100);
	}
};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<trans_operandsHandler> handler(new trans_operandsHandler());
  shared_ptr<TProcessor> processor(new trans_operandsProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  //TThreadedServer server(processor,serverTransport,transportFactory,protocolFactory);
 
  shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
  shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
  threadManager->threadFactory(threadFactory);
  threadManager->start();
  shared_ptr<testA> t(new testA()) ;
  threadManager->add(t);
  
  TNonblockingServer server(processor,protocolFactory,port,threadManager);
  //TThreadPoolServer server(processor,serverTransport,transportFactory,protocolFactory,threadManager);
  //TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}



