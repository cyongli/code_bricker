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
#include <thread>
using std::thread;
#include <mutex>
#include <condition_variable>
std::mutex some_mutex;
std::condition_variable data_cond;
int res = 0;

class trans_operandsHandler : virtual public trans_operandsIf {
 public:
  trans_operandsHandler() { }

  void trans_operands(const Operand& first, const Operand& second) {
    // Your implementation goes here
    for(int i=0;i<7;i++){
    	some_mutex.lock();
    	res += first.num+second.num;
    	some_mutex.unlock();
		data_cond.notify_one();
	}
  }

};

void connection(){
  int port = 9090;
  shared_ptr<trans_operandsHandler> handler(new trans_operandsHandler());
  shared_ptr<TProcessor> processor(new trans_operandsProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
 
  shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager();
  shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
  threadManager->threadFactory(threadFactory);
  threadManager->start();
  
  TNonblockingServer server(processor,protocolFactory,port,threadManager);
  server.serve();
}

int main(int argc, char* argv[]){
	thread t(connection);
	t.detach();
	std::unique_lock<std::mutex> cond(some_mutex);
	while(true){
		data_cond.wait(cond,[]{return res>100;});
		cout << "res is:" << res << endl;
		res = 0;
	}
	return 0;
}

