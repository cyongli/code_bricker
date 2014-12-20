
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;

#include "gen-cpp/trans_operands.h"
#include "gen-cpp/test_types.h"

using std::cerr;
using std::cout;
using std::endl;
using namespace test;

int main(int argc, char* argv[]){

	boost::shared_ptr<TTransport> socket(new TSocket("localhost",9090));
	boost::shared_ptr<TTransport> transport(new TFramedTransport(socket));
	boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	trans_operandsClient client(protocol);

	test::Operand first,second;
	first.num = 10;
	second.num = 20;
	try{
		transport->open();
		client.trans_operands(first,second);
		transport->close();
	} catch (TException& tx){
		cout << "ERROR: bad %s\n" << tx.what() << endl;
	}

	return 0;
}
